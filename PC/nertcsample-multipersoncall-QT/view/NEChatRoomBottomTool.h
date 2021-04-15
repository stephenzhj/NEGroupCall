#ifndef NEBOTTOMTOOL_H
#define NEBOTTOMTOOL_H

#include <QWidget>

namespace Ui {
class NEChatRoomBottomTool;
}

class NERtcEngine;
class NECameraDeviceListWidget;
class NEAudioDeviceListWidget;

class NEChatRoomBottomTool : public QWidget {
    Q_OBJECT

public:
    explicit NEChatRoomBottomTool(QWidget* parent = nullptr);
    ~NEChatRoomBottomTool();

    void setRtcEngine(std::shared_ptr<NERtcEngine> engine);
    void init();
    void setVideoCheck(bool check);
    void setAudioCheck(bool check);
    void setVideoEnable(bool bEnable);
    bool getIsBeutyOpen();

Q_SIGNALS:
    void sigVoiceEnable(bool bEnable);
    void sigVideoEnable(bool bEnable);
    void sigBeautyEnable(bool bEnable);
    void sigExitCall();
    void sigVideoSetting();
    void sigAudioSetting();
    void sigShowData();

protected:
    virtual bool eventFilter(QObject* watched, QEvent* event) override;
    virtual void hideEvent(QHideEvent *event) override;

public Q_SLOTS:
    void onVoiceClicked();
    void onVideoClicked( );
    void onBeautyClicked();
    void onVideoSettingClicked();
    void onAudioSettingClicked();
    void onCameraDeviceChanged(const QString& deviceID);
    void onSpeakerDeviceChanged(const QString& deviceID);
    void onMicDeviceChanged(const QString& deviceID);

private:
    Ui::NEChatRoomBottomTool* ui;

    std::shared_ptr<NERtcEngine> m_engine;

    NECameraDeviceListWidget* cameraWidget;

    NEAudioDeviceListWidget* audioWidget;

    qint64 lastClickTime;

    bool m_bCameraCheck = false;
    bool m_bMicCheck = false;
};

#endif  // NEBOTTOMTOOL_H
