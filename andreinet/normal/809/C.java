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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            while (q-- > 0) {
                int x1 = in.nextInt() - 1;
                int y1 = in.nextInt() - 1;
                int x2 = in.nextInt() - 1;
                int y2 = in.nextInt() - 1;
                int k = in.nextInt() - 1;
                int ans = (solve(k, x2, y2) - solve(k, x1 - 1, y2)) % MOD -
                        (solve(k, x2, y1 - 1) - solve(k, x1 - 1, y1 - 1)) % MOD;
                ans %= MOD;
                if (ans < 0) {
                    ans += MOD;
                }
                out.println(ans);
            }
        }

        private int solve(int k, int a, int b) {
            if (a < 0 || b < 0) {
                return 0;
            }
            int[][][][] dp = new int[32][2][2][2];
            int[][][][] dpSum = new int[32][2][2][2];
            dp[31][0][0][0] = 1;
            for (int i = 30; i >= 0; --i) {
                for (int putA = 0; putA < 2; ++putA) {
                    for (int putB = 0; putB < 2; ++putB) {
                        int putK = putA ^ putB;
                        int value = 0;
                        if (putK > 0) {
                            value = (1 << i) % MOD;
                        }

                        for (int lastK = 0; lastK < 2; ++lastK) {
                            int nK = computeNew(k, i, putK, lastK);
                            if (nK == -1) continue;
                            for (int lastA = 0; lastA < 2; ++lastA) {
                                int nA = computeNew(a, i, putA, lastA);
                                if (nA == -1) continue;
                                for (int lastB = 0; lastB < 2; ++lastB) {
                                    int nB = computeNew(b, i, putB, lastB);
                                    if (nB == -1) continue;
                                    dp[i][nK][nA][nB] += dp[i + 1][lastK][lastA][lastB];
                                    dp[i][nK][nA][nB] %= MOD;
                                    dpSum[i][nK][nA][nB] += (long) dp[i + 1][lastK][lastA][lastB] * value % MOD;
                                    dpSum[i][nK][nA][nB] %= MOD;
                                    dpSum[i][nK][nA][nB] += dpSum[i + 1][lastK][lastA][lastB];
                                    dpSum[i][nK][nA][nB] %= MOD;
                                }
                            }
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    for (int l = 0; l < 2; ++l) {
                        ans += dpSum[0][i][j][l];
                        ans %= MOD;
                        ans += dp[0][i][j][l];
                        ans %= MOD;
                    }
                }
            }
            return ans;
        }

        int computeNew(int k, int i, int put, int last) {
            if (last == 1) {
                return 1;
            }
            int nK;
            if (put == 0) {
                nK = ((k & (1 << i)) != 0) ? 1 : 0;
            } else {
                if ((k & (1 << i)) == 0) {
                    return -1;
                } else {
                    nK = 0;
                }
            }
            return nK;
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