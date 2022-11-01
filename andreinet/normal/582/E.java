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
        final int Mod = (int) 1e9 + 7;
        String expression;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            expression = in.next();

            int[] dp = calculate(0, expression.length() - 1);
            int n = in.nextInt();

            int mask = 0, values = 0;
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
                int val = in.nextInt();

                int conf = 8 * a + 4 * b + 2 * c + d;
                mask |= 1 << conf;
                values |= val << conf;
            }

            int ans = 0;
            for (int conf = 0; conf < (1 << 16); ++conf)
                if ((conf & mask) == values)
                    ans = (ans + dp[conf]) % Mod;

            out.println(ans);
        }

        private int[] calculate(int left, int right) {
            if (left == right) {
                char c = expression.charAt(left);

                int[] dp = new int[1 << 16];
                for (int v = 7; v >= 0; --v) {
                    char p = v < 4 ? (char) ('d' - v) : (char) ('D' - v + 4);
                    if (c == '?' || c == p) {
                        int cmask = 0;
                        for (int conf = 0; conf < 16; ++conf) {
                            int mask = v < 4 ? ~conf : conf;
                            if ((mask & (1 << (v % 4))) != 0)
                                cmask |= 1 << conf;
                        }
                        dp[cmask] = 1;
                    }
                }
                return dp;
            } else {
                int cnt = 0, pos = left;
                while (cnt > 0 || (expression.charAt(pos) != '|' && expression.charAt(pos) != '&' &&
                        expression.charAt(pos) != '?')) {
                    switch (expression.charAt(pos)) {
                        case '(':
                            cnt++;
                            break;
                        case ')':
                            cnt--;
                            break;
                    }
                    pos++;
                }

                int[] dpLeft = calculate(left + 1, pos - 2);
                int[] dpRight = calculate(pos + 2, right - 1);
                int[] dp = new int[1 << 16];

                if (expression.charAt(pos) == '&' || expression.charAt(pos) == '?') {
                    int[] dpnLeft = genAnd(dpLeft);
                    int[] dpnRight = genAnd(dpRight);
                    for (int i = 0; i < (1 << 16); ++i)
                        dp[i] = (int) ((long) dpnLeft[i] * dpnRight[i] % Mod);
                    dp = revgenAnd(dp);
                }

                if (expression.charAt(pos) == '|' || expression.charAt(pos) == '?') {
                    int[] dpnLeft = genOr(dpLeft);
                    int[] dpnRight = genOr(dpRight);
                    int[] aux = new int[1 << 16];
                    for (int i = 0; i < (1 << 16); ++i)
                        aux[i] = (int) ((long) dpnLeft[i] * dpnRight[i] % Mod);
                    aux = revgenOr(aux);
                    for (int i = 0; i < (1 << 16); ++i)
                        dp[i] = (dp[i] + aux[i]) % Mod;
                }

                return dp;
            }
        }

        private int[] genAnd(int[] dp) {
            int[] result = new int[1 << 16];
            System.arraycopy(dp, 0, result, 0, 1 << 16);
            for (int i = 0; i < 16; ++i)
                for (int conf = 0; conf < (1 << 16); ++conf)
                    if ((conf & (1 << i)) == 0)
                        result[conf] = (result[conf] + result[conf ^ (1 << i)]) % Mod;
            return result;
        }

        private int[] revgenAnd(int[] dp) {
            int[] result = new int[1 << 16];
            System.arraycopy(dp, 0, result, 0, 1 << 16);
            for (int i = 0; i < 16; ++i)
                for (int conf = 0; conf < (1 << 16); ++conf)
                    if ((conf & (1 << i)) == 0)
                        result[conf] = (result[conf] - result[conf ^ (1 << i)] + Mod) % Mod;
            return result;
        }

        private int[] genOr(int[] dp) {
            int[] result = new int[1 << 16];
            System.arraycopy(dp, 0, result, 0, 1 << 16);
            for (int i = 0; i < 16; ++i)
                for (int conf = 0; conf < (1 << 16); ++conf)
                    if ((conf & (1 << i)) != 0)
                        result[conf] = (result[conf] + result[conf ^ (1 << i)]) % Mod;
            return result;
        }

        private int[] revgenOr(int[] dp) {
            int[] result = new int[1 << 16];
            System.arraycopy(dp, 0, result, 0, 1 << 16);
            for (int i = 0; i < 16; ++i)
                for (int conf = 0; conf < (1 << 16); ++conf)
                    if ((conf & (1 << i)) != 0)
                        result[conf] = (result[conf] - result[conf ^ (1 << i)] + Mod) % Mod;
            return result;
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