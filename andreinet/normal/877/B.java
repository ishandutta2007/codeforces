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
            String a = in.next();
            int n = a.length();
            int[][] dp = new int[3][n + 1];
            final int INF = 0x3f3f3f3f;
            for (int i = 1; i <= n; ++i) {
                if (a.charAt(i - 1) == 'a') {
                    dp[0][i] = dp[0][i - 1];
                    dp[1][i] = Math.min(dp[1][i - 1] + 1, dp[0][i - 1] + 1);
                    dp[2][i] = Math.min(dp[2][i - 1], Math.min(dp[1][i - 1], dp[2][i - 1]));
                } else {
                    dp[0][i] = dp[0][i - 1] + 1;
                    dp[1][i] = Math.min(dp[0][i - 1], dp[1][i - 1]);
                    dp[2][i] = Math.min(dp[2][i - 1] + 1, Math.min(dp[1][i - 1] + 1, dp[2][i - 1] + 1));
                }
            }
            out.println(n - Math.min(dp[0][n], Math.min(dp[1][n], dp[2][n])));
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