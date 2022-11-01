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
            int n = in.nextInt(), t = in.nextInt();

            int r = 205, offset = r / 2 + 1;
            int[][] A = new int[r][r];
            boolean[][] inQueue = new boolean[r][r];
       /* Queue<Cell> q = new ArrayDeque<>();
        q.add(new Cell(offset, offset));*/

            int[] qx = new int[r * r], qy = new int[r * r];
            int left = 0, right = 1, sz = 1;
            qx[0] = qy[0] = offset;
            A[offset][offset] = n;
            int[] dx = new int[]{-1, 0, 1, 0};
            int[] dy = new int[]{0, -1, 0, 1};
            int maxs = 0;
            while (sz > 0) {
                int cx = qx[left], cy = qy[left++];
                left %= qx.length;
                sz--;
                inQueue[cx][cy] = false;
                int add = A[cx][cy] / 4;
                A[cx][cy] %= 4;

                maxs = Math.max(maxs, cx - offset);

                if (add > 0) {
                    for (int k = 0; k < 4; ++k) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        A[nx][ny] += add;
                        if (!inQueue[nx][ny]) {
                            inQueue[nx][ny] = true;
                            qx[right] = nx;
                            qy[right++] = ny;
                            right %= qx.length;
                            sz++;
                        }
                    }
                }
            }

            while (t-- > 0) {
                int x = in.nextInt(), y = in.nextInt();
                if (x < 0) x = -x;
                if (y < 0) y = -y;
                if (x > maxs || y > maxs) {
                    out.println(0);
                } else {
                    out.println(A[offset + x][offset + y]);
                }
            }
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