import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.BufferedReader;
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
        HSubsequencesHardVersion solver = new HSubsequencesHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class HSubsequencesHardVersion {
        private static final boolean debug = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long k = in.nextLong();

            char[] s = in.next().toCharArray();

            // dp[i][j] is the number of new subseq of length j of s[0..i-1]
            BigInteger[][] dp = new BigInteger[n + 1][n + 1];

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dp[i][j] = BigInteger.ZERO;
                }
            }

            for (int i = 0; i <= n; i++) {
                dp[i][0] = BigInteger.ONE;
            }

            HashMap<Character, Integer> last = new HashMap<>();

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i][j].add(dp[i - 1][j]);
                    dp[i][j] = dp[i][j].add(dp[i - 1][j - 1]);

                    if (last.containsKey(s[i - 1])) {
                        dp[i][j] = dp[i][j].subtract(dp[last.get(s[i - 1])][j - 1]);
                    }
                }
                last.put(s[i - 1], i - 1);
            }

            long answer = 0;
            for (int j = n; j >= 0; j--) {
                long use = k;
                if (dp[n][j].compareTo(BigInteger.valueOf(k)) < 0)
                    use = dp[n][j].longValue();
                long cost = n - j;
                answer += use * cost;
                k -= use;
                if (k == 0)
                    break;
            }

            if (debug) {
                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= n; j++) {
                        System.out.print(dp[i][j] + "\t");
                    }
                    System.out.println();
                }
                verify(dp, s);
            }

            if (k > 0)
                answer = -1;

            out.println(answer);
        }

        private void verify(BigInteger[][] dp, char[] s) {
            HashSet<String>[] strings = new HashSet[s.length + 1];
            for (int i = 0; i <= s.length; i++) {
                strings[i] = new HashSet<>();
            }
            for (long i = 0; i < (1L << s.length); i++) {
                String string = "";
                for (int j = 0; j < s.length; j++) {
                    if ((i & (1L << j)) > 0) {
                        string += s[j];
                    }
                }
                strings[string.length()].add(string);
            }

            for (int i = 0; i <= s.length; i++) {
                System.out.println(i + "\t" + strings[i].size() + "\t" + dp[s.length][i]);
                ASSERT(strings[i].size() == dp[s.length][i].longValue());
            }
        }

        private static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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