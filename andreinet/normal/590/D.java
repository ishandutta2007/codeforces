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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt(), s = in.nextInt();
            int maxp = k * (n - k + 1 + n) / 2 - k * (k + 1) / 2;
            int[][] dp = new int[k + 1][maxp + 1];

            final int Inf = 0x3f3f3f3f;
            for (int[] p : dp) Arrays.fill(p, Inf);
            dp[0][0] = 0;

            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();

                for (int j = Math.min(i, k - 1); j >= 0; --j) {
                    for (int p = 0; p <= maxp - (i - j); ++p) {
                        dp[j + 1][p + (i - j)] = Math.min(dp[j + 1][p + (i - j)],
                                dp[j][p] + x);
                    }
                }
            }

            int ans = Inf;
            for (int i = 0; i <= s && i <= maxp; ++i)
                ans = Math.min(ans, dp[k][i]);

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