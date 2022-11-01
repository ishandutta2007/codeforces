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
        private final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            long ans = 0;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    int eveni = n % 2 == 1 ? (n + 1) / 2 : n / 2 + (i + 1) % 2;
                    int evenj = m % 2 == 1 ? (m + 1) / 2 : m / 2 + (j + 1) % 2;

                    int oddi = n - eveni + 1;
                    int oddj = m - evenj + 1;

                    int odd = oddi * oddj;
                    int all = (n + 1) * (m + 1);
                    int even = all - odd;

                    ans += (long) even * even % MOD;
                    ans += (long) odd * odd % MOD;
                    ans %= MOD;
                }
            }

            int[] dp;
            dp = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                dp[i] = dp[i - 1] + i;
                ans = (ans - 6L * (m + 1) * dp[i]) % MOD;
            }
            dp = new int[m + 1];
            for (int i = 1; i <= m; ++i) {
                dp[i] = dp[i - 1] + i;
                ans = (ans - 6L * (n + 1) * dp[i]) % MOD;
            }

            dp = new int[m + 1];
            int[] ndp = new int[m + 1];

            int[][] gcd = new int[n + 1][m + 1];

            for (int i = 1; i <= n; ++i) {
                //ndp[0] = dp[0] + i;
                //ans = (ans - 6L * ndp[0]) % MOD;
                for (int j = 1; j <= m; ++j) {
                    if (gcd[i][j] == 0) {
                        gcd[i][j] = 1;
                        for (int p = 2; i * p <= n && p * j <= m; ++p)
                            gcd[i * p][j * p] = p;
                    }
                    ndp[j] = (dp[j] + ndp[j - 1]) % MOD;
                    ndp[j] = (ndp[j] - dp[j - 1]) % MOD;
                    ndp[j] = (ndp[j] + gcd[i][j]) % MOD;
                    ans = (ans - 12L * ndp[j]) % MOD;

                    //int sub = (i + 1) * (j + 1) - 1;
                    //ans = (ans - 6L * sub) % MOD;
                }
                int[] aux = dp;
                dp = ndp;
                ndp = aux;
            }

            ans -= (n + 1) * (m + 1);
            ans %= MOD;
            if (ans < 0) ans += MOD;

            out.println(ans);
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