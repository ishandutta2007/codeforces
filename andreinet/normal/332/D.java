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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[][] G = new int[n][n];

            for (int i = 0; i < n; ++i) {
                G[i][i] = -1;
                for (int j = i + 1; j < n; ++j) {
                    G[i][j] = G[j][i] = in.nextInt();
                }
            }

            if (k == 2) {
                long choose = n * (n - 1) / 2;
                long sum = 0;
                for (int i = 0; i < n; ++i) {
                    int deg = 0;
                    for (int j = 0; j < n; ++j) {
                        if (G[i][j] != -1) {
                            deg++;
                        }
                    }
                    if (deg < 2) continue;
                    for (int j = 0; j < n; ++j) {
                        if (G[i][j] != -1) {
                            sum += (long) (deg - 1) * G[i][j];
                        }
                    }
                }

                out.println(sum / choose);
            } else {
                long sum = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        sum += Math.max(0, G[i][j]);
                    }
                }
                out.println(sum / n);
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