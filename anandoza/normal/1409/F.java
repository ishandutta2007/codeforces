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
        FSubsequencesOfLengthTwo solver = new FSubsequencesOfLengthTwo();
        solver.solve(1, in, out);
        out.close();
    }

    static class FSubsequencesOfLengthTwo {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            char[] s = in.next().toCharArray();
            char[] inputT = in.next().toCharArray();
            char a = inputT[0], b = inputT[1];

            if (a == b) {
                int count = 0;
                for (char x : s) {
                    if (x == a)
                        count++;
                }
                count += k;
                count = Math.min(count, n);
                out.println(Util.nc2(count));
                return;
            }

            int[][][] dp = new int[n + 1][k + 2][n + 2]; // left substring length, number moves used, number of 'a' present
            for (int[][] row : dp) {
                for (int[] col : row) {
                    Arrays.fill(col, -1);
                }
            }
            dp[0][0][0] = 0;
            for (int left = 0; left < n; left++) {
                for (int moves = 0; moves <= k; moves++) {
                    for (int count = 0; count <= n; count++) {
                        int cur = dp[left][moves][count];
                        if (cur == -1)
                            continue;

                        char nextChar = s[left];
                        if (nextChar == a) {
                            dp[left + 1][moves][count + 1] = Math.max(dp[left + 1][moves][count + 1], cur);
                            dp[left + 1][moves + 1][count] = Math.max(dp[left + 1][moves + 1][count], cur + count);
                        } else if (nextChar == b) {
                            dp[left + 1][moves][count] = Math.max(dp[left + 1][moves][count], cur + count);
                            dp[left + 1][moves + 1][count + 1] = Math.max(dp[left + 1][moves + 1][count + 1], cur);
                        } else {
                            dp[left + 1][moves][count] = Math.max(dp[left + 1][moves][count], cur);
                            dp[left + 1][moves + 1][count] = Math.max(dp[left + 1][moves + 1][count], cur + count);
                            dp[left + 1][moves + 1][count + 1] = Math.max(dp[left + 1][moves + 1][count + 1], cur);
                        }
                    }
                }
            }

            // for (int left = 0; left <= n; left++) {
            //     System.out.println("left = " + left);
            //     Util.print2DArray(dp[left]);
            // }

            int answer = 0;
            for (int[][] row : dp) {
                for (int moves = 0; moves <= k; moves++) {
                    int[] col = row[moves];
                    for (int val : col) {
                        answer = Math.max(answer, val);
                    }
                }
            }

            out.println(answer);
        }

    }

    static class Util {
        public static long nc2(long n) {
            return n * (n - 1) / 2;
        }

        private Util() {
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

    }
}