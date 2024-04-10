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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        final int Mod = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt(), L = in.nextInt();
            int Len = 100;

            int[][][] dp = new int[Len + 1][Len][N + 1];
            int[][] sp = new int[Len + 1][Len];
            for (int i = 0; i < Len; ++i) {
                dp[0][i][0] = 1;
                sp[0][i] = 1;
            }

            int[] A = new int[N + 1], B = new int[N + 1];
            for (int i = 1; i <= N; ++i) {
                A[i] = in.nextInt() - 1;
                B[i] = in.nextInt() - 1;
            }

            for (int i = 1; i <= L; ++i) {
                int w = i % (Len + 1);
                for (int[] p : dp[w])
                    Arrays.fill(p, 0);
                Arrays.fill(sp[w], 0);

                for (int j = 1; j <= N; ++j) {
                    int x = A[j], y = B[j];

                    int from = (i - x - 1) % (Len + 1);
                    if (from < 0) from += Len + 1;

                    int add = (sp[from][x] - dp[from][x][j] + Mod) % Mod;
                    dp[w][y][j] = (dp[w][y][j] + add) % Mod;
                    sp[w][y] = (sp[w][y] + add) % Mod;

                    if (x != y) {
                        int aux = x;
                        x = y;
                        y = aux;

                        from = (i - x - 1) % (Len + 1);
                        if (from < 0) from += Len + 1;

                        add = (sp[from][x] - dp[from][x][j] + Mod) % Mod;
                        dp[w][y][j] = (dp[w][y][j] + add) % Mod;
                        sp[w][y] = (sp[w][y] + add) % Mod;
                    }
                }
            }

            int ans = 0;
            for (int p : sp[L % (Len + 1)]) ans = (ans + p) % Mod;

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