#include <GLFW/glfw3.h>

class Engine {
    public:
    
    Engine() {
        
        
    }
    int render(int width, int height, const char *title, GLFWmonitor *monitor = NULL, GLFWwindow *share = NULL) {
        GLFWwindow* window; /* Initialize the library */

        /* Initialize the library */
        if (!glfwInit()) return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(width, height,title, monitor, share);

        if (!window) {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window)) {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();

        return 0;
    }
};

int main(void)
{
    Engine NewEngine;
    NewEngine.render(400,400,"My Window");
    return 0;
}