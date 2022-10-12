import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CBasketballExercise solver = new CBasketballExercise();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBasketballExercise {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[][] h = new long[n][2];
            for (int j = 0; j <= 1; j++) {
                for (int i = 0; i < n; i++) {
                    h[i][j] = in.nextLong();
                }
            }

            long[][] dp = new long[n + 1][2];
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= 1; j++) {
                    if (i - 2 >= 0)
                        dp[i][j] = Math.max(dp[i - 2][1 - j] + h[i - 1][j], dp[i - 1][1 - j] + h[i - 1][j]);
                    else
                        dp[i][j] = dp[i - 1][1 - j] + h[i - 1][j];
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                }
            }

            long answer = Math.max(dp[n][0], dp[n][1]);
            out.println(answer);
        }

    }

    static class InputReader {
        public BufferedReader reader;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}