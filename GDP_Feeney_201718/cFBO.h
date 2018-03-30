#ifndef _FBO_HG_
#define _FBO_HG_

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class cFBO
{
public:
	cFBO() : 
		ID(0), 
		colourTexture_0_ID(0),
		normalTexture_1_ID(1),
		depthTexture_ID(0), 
		width(-1), height(-1) {};

	GLuint ID;				// g_FBO	// = 0;
	GLuint colourTexture_0_ID;		// = 0;
	GLuint normalTexture_1_ID;
	GLuint vertexWorldPos_2_ID;
//	GLuint TBDTexture_2_ID;
//	GLuint TBDTexture_3_ID;

	GLuint depthTexture_ID;		// = 0;
	GLint width;		// = 512 the WIDTH of the framebuffer, in pixels;
	GLint height;

	// Inits the FBP
	bool init(int width, int height, std::string &error);
	bool shutdown(void);
	// Calls shutdown(), then init()
	bool reset(int width, int height, std::string &error);
	
	//Clears colour to 0, depth to 1, and stencil to 0
	void clearBuffers(bool bClearColour = true, bool bClearDepth = true);
	//Clears colour to RGBA, depth to 1, and stencil 0
	void clearBuffers(glm::vec4 clearColour, bool bClearColour = true, bool bClearDepth = true);

	void clearColourBuffer(int bufferindex);
	void clearAllColourBuffers(void);
	void clearDepthBuffer(void);
	void clearStencilBuffer( int clearColour, int mask = 0xFF );

	int getMaxColourAttachments(void);
	int getMaxDrawBuffers(void);
};

#endif