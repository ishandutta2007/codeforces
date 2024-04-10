import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        D505 solver = new D505();
        solver.solve(1, in, out);
        out.close();
    }

    static class D505 {
        private static final int K = 4;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[][] a = new int[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.readBitString();
            }

            out.println(solve(n, m, a));
        }

        private static int solve(int n, int m, int[][] a) {
            if (n >= 4) {
                return -1;
            }

            if (n == 1) {
                return 0;
            }

            int[][] parity = new int[n - 1][m - 1];
            for (int i = 0; i + 1 < n; i++) {
                for (int j = 0; j + 1 < m; j++) {
                    parity[i][j] ^= a[i][j];
                    parity[i][j] ^= a[i][j + 1];
                    parity[i][j] ^= a[i + 1][j];
                    parity[i][j] ^= a[i + 1][j + 1];
                }
            }

            int[] p = new int[m - 1];
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    p[i] += (1 << j) * (1 ^ parity[j][i]);
                }
            }

            int[][] dp = new int[m - 1][K];
            for (int i = 0; i < m - 1; i++) {
                Arrays.fill(dp[i], n * m + 1);
            }
            for (int s = 0; s < K; s++) {
                dp[0][p[0] ^ s] = cost(s);
            }
            for (int i = 1; i < m - 1; i++) {
                for (int s = 0; s < K; s++) {
                    dp[i][p[i] ^ s] = dp[i - 1][s] + cost(s);
                }
            }

            int answer = Integer.MAX_VALUE;
            for (int s = 0; s < K; s++) {
                answer = Math.min(answer, dp[m - 2][s] + cost(s));
            }
            return answer;
        }

        private static int cost(int s) {
            return s == 0 ? 0 : 1;
        }

    }

    static class InputReader {
        public final BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readBitString() {
            char[] chars = next().toCharArray();
            int[] x = new int[chars.length];
            for (int i = 0; i < x.length; i++) {
                x[i] = chars[i] - '0';
            }
            return x;
        }

    }
}