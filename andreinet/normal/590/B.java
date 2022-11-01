import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int x1 = in.nextInt(), y1 = in.nextInt();
            int x2 = in.nextInt(), y2 = in.nextInt();

            int vmax = in.nextInt(), t = in.nextInt();
            int vx = in.nextInt(), vy = in.nextInt();
            int wx = in.nextInt(), wy = in.nextInt();

            final double eps = 1e-10;

            double left = 0, right = 1e9;
            for (int tt = 0; tt < 200; ++tt) {
                double time = (left + right) / 2;
                double posx, posy;

                if (t > time) {
                    posx = x1 + time * vx;
                    posy = y1 + time * vy;
                } else {
                    posx = x1 + (double) t * vx + (time - t) * wx;
                    posy = y1 + (double) t * vy + (time - t) * wy;
                }
                double dx = Math.abs(posx - x2), dy = Math.abs(posy - y2);
                double speedx = dx / time;
                double speedy = dy / time;

                double speed = speedx * speedx + speedy * speedy;
                if (speed < (double) vmax * vmax + eps) {
                    right = time;
                } else {
                    left = time;
                }
            }

            double ans = (left + right) / 2;
            out.println(String.format("%.18f", ans));
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}