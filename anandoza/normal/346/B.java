import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
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
        BLuckyCommonSubsequence solver = new BLuckyCommonSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLuckyCommonSubsequence {
        static final int I = -1;
        static final int J = -2;
        static final int NONE = -4;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] a = in.next().toCharArray();
            char[] b = in.next().toCharArray();
            char[] v = in.next().toCharArray();

            KMP kmp = new KMP(v);

            Pair<Integer, Integer>[][][] dp = new Pair[a.length + 1][b.length + 1][v.length + 1];
            for (int i = 0; i <= a.length; i++) {
                for (int j = 0; j <= b.length; j++) {
                    for (int k = 0; k <= v.length; k++) {
                        dp[i][j][k] = Pair.of(0, NONE);
                    }
                }
            }
            for (int i = 1; i <= a.length; i++) {
                for (int j = 1; j <= b.length; j++) {
                    for (int k = 0; k < v.length; k++) {
                        dp[i][j][k] = max(dp[i][j][k], max(Pair.of(dp[i - 1][j][k].first, I), Pair.of(dp[i][j - 1][k].first, J)));
                        if (a[i - 1] == b[j - 1]) {
                            int len = kmp.adv(k, a[i - 1]);
                            dp[i][j][len] = max(dp[i][j][len], Pair.of(dp[i - 1][j - 1][k].first + 1, k));
                        }
                    }
                }
            }

            Pair<Integer, String> answer = Pair.of(0, null);
            for (int k = 0; k < v.length; k++) {
                int len = k;
                StringBuilder sb = new StringBuilder();

                outer:
                for (int i = a.length, j = b.length; ; ) {
                    switch (dp[i][j][len].second) {
                        case I:
                            i--;
                            break;
                        case J:
                            j--;
                            break;
                        case NONE:
                            break outer;
                        default:
                            sb.append(a[i - 1]);
                            len = dp[i][j][len].second;
                            i--;
                            j--;
                            break;
                    }
                }

                sb.reverse();
                answer = max(answer, Pair.of(sb.length(), sb.toString()));
            }

            if (answer.first == 0) {
                out.println(0);
                return;
            }

            out.println(answer.second);
        }

        private static <T> Pair<Integer, T> max(Pair<Integer, T> x, Pair<Integer, T> y) {
            return x.first > y.first ? x : y;
        }

    }

    static class KMP {
        final char[] pattern;
        final int[] fail;

        public KMP(char[] pattern) {
            this.pattern = pattern;
            fail = new int[pattern.length + 1];

            fail[0] = 0;
            for (int i = 2; i <= pattern.length; i++) {
                fail[i] = adv(fail[i - 1], pattern[i - 1]);
            }
        }

        public int adv(int len, char next) {
            while (len > 0 && pattern[len] != next) {
                len = fail[len];
            }
            return len + (pattern[len] == next ? 1 : 0);
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

    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }
}