import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            long[] x = new long[n + 1];
            long[] y = new long[n + 1];

            for (int i = 0; i < n; ++i) {
                int x1 = in.nextInt(), y1 = in.nextInt();
                int x2 = in.nextInt(), y2 = in.nextInt();
                x[i] = x1 + x2;
                y[i] = y1 + y2;
            }

            Integer[] sx = new Integer[n], sy = new Integer[n];
            for (int i = 0; i < n; ++i) sx[i] = sy[i] = i;
            Arrays.sort(sx, (o1, o2) -> Long.compare(x[o1], x[o2]));
            Arrays.sort(sy, (o1, o2) -> Long.compare(y[o1], y[o2]));

            boolean[] removed = new boolean[n + 2];

            long ans = Long.MAX_VALUE;
            for (int lx = 0; lx <= k; ++lx) {
                for (int rx = 0; rx <= k; ++rx) {
                    for (int ly = 0; ly <= k; ++ly) {
                        for (int ry = 0; ry <= k; ++ry) {
                            int cnt = 0;
                            for (int i = 0; i < lx; ++i) {
                                if (!removed[sx[i]]) ++cnt;
                                removed[sx[i]] = true;
                            }
                            for (int i = n - rx; i < n; ++i) {
                                if (!removed[sx[i]]) ++cnt;
                                removed[sx[i]] = true;
                            }
                            for (int i = 0; i < ly; ++i) {
                                if (!removed[sy[i]]) ++cnt;
                                removed[sy[i]] = true;
                            }
                            for (int i = n - ry; i < n; ++i) {
                                if (!removed[sy[i]]) ++cnt;
                                removed[sy[i]] = true;
                            }

                            if (cnt <= k) {
                                int leftx = 0, rightx = n - 1;
                                while (removed[sx[leftx]]) ++leftx;
                                while (removed[sx[rightx]]) --rightx;
                                int lefty = 0, righty = n - 1;
                                while (removed[sy[lefty]]) ++lefty;
                                while (removed[sy[righty]]) --righty;

                                long area = Math.max(2,
                                        (x[sx[rightx]] - x[sx[leftx]])) *
                                        Math.max(2,
                                                (y[sy[righty]] - y[sy[lefty]]));
                                ans = Math.min(ans, area);
                            }

                            for (int i = 0; i < lx; ++i)
                                removed[sx[i]] = false;
                            for (int i = n - rx; i < n; ++i)
                                removed[sx[i]] = false;
                            for (int i = 0; i < ly; ++i)
                                removed[sy[i]] = false;
                            for (int i = n - ry; i < n; ++i)
                                removed[sy[i]] = false;
                        }
                    }
                }
            }
            out.println(ans / 4);
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