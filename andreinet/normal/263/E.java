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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();

            int[][] A = new int[n + 2][m + 2];
            int[][] d1 = new int[n + 2][m + 2];
            int[][] d2 = new int[n + 2][m + 2];
            int[][] r1 = new int[n + 2][m + 2];
            int[][] r2 = new int[n + 2][m + 2];
            int[][] up = new int[n + 2][m + 2];
            long[][] tleft = new long[n + 2][m + 2];
            long[][] tright = new long[n + 2][m + 2];

            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    A[i][j] = in.nextInt();
                    d1[i][j] = d1[i - 1][j - 1] + A[i][j];
                    up[i][j] = up[i - 1][j] + A[i][j];
                }
                for (int j = m; j > 0; --j) {
                    r1[i][j] = r1[i - 1][j + 1] + A[i][j];
                }
            }

            for (int i = n; i > 0; --i) {
                for (int j = 1; j <= m; ++j) {
                    d2[i][j] = d2[i + 1][j - 1] + A[i][j];
                }
                for (int j = m; j > 0; --j) {
                    r2[i][j] = r2[i + 1][j + 1] + A[i][j];
                }
            }

            k--;

            for (int i = k + 1; i <= n - k; ++i) {
                for (int j = 1; j <= m; ++j) {
                    tleft[i][j] = tleft[i][j - 1];
                    tleft[i][j] += up[i + k][j] - up[i - k - 1][j];
                    tleft[i][j] -= d1[i + k][j - 1];
                    tleft[i][j] -= d2[i - k][j - 1];
                    if (j - k - 1 >= 0) {
                        tleft[i][j] += d1[i][j - k - 1];
                        tleft[i][j] += d2[i][j - k - 1];
                        tleft[i][j] -= A[i][j - k - 1];
                    }
                }
                for (int j = m; j > 0; --j) {
                    tright[i][j] += tright[i][j + 1];
                    tright[i][j] += up[i + k][j] - up[i - k - 1][j];
                    tright[i][j] -= r1[i + k][j + 1];
                    tright[i][j] -= r2[i - k][j + 1];
                    if (j + k + 1 <= m) {
                        tright[i][j] += r1[i][j + k + 1];
                        tright[i][j] += r2[i][j + k + 1];
                        tright[i][j] -= A[i][j + k + 1];
                    }
                }
            }

            long ans = -1;
            int fi = -1, fj = -1;
            for (int i = k + 1; i <= n - k; ++i) {
                long sum = 0;
                for (int l = i - k, d = 1, p = k + 1; l <= i; ++l, ++d, --p) {
                    long cr = r2[l][1] - r2[i][p];
                    cr += r1[2 * i - l][1] - r1[i][p];
                    cr += A[i][p];
                    cr *= d;
                    sum += cr;
                }
                for (int j = 1; j <= m - k; ++j) {
                    if (j > 1) {
                        sum += tright[i][j];
                        sum -= tleft[i][j - 1];
                    }
                    if (j >= k + 1) {
                        if (ans < sum) {
                            ans = sum;
                            fi = i;
                            fj = j;
                        }
                    }
                }
            }

            out.println(fi + " " + fj);
            //System.err.println(ans);
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