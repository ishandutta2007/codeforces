import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        EYetAnotherDivisionIntoTeams solver = new EYetAnotherDivisionIntoTeams();
        solver.solve(1, in, out);
        out.close();
    }

    static class EYetAnotherDivisionIntoTeams {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] aOriginal = in.readIntArray(n);
            Pair<Integer, Integer>[] pairs = new Pair[n];
            for (int i = 0; i < n; i++)
                pairs[i] = Pair.of(aOriginal[i], i);
            Arrays.sort(pairs, Comparator.comparingInt(p -> p.first));
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = pairs[i].first;
            }

            int[][] dp = new int[n + 1][3]; // dp[i][j] is using the first i people and the last team has (j+1)+ people
            for (int[] x : dp) {
                Arrays.fill(x, -1);
            }

            dp[1][0] = 0;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    if (dp[i][j] < 0)
                        continue;

                    int u = Math.min(j + 1, 2);
                    dp[i + 1][u] = Math.max(dp[i + 1][u], dp[i][j]);
                    if (j == 2) {
                        // we already have 3+ people, ending with person i-1, so we put person i on the next team
                        dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][j] + a[i] - a[i - 1]);
                    }
                }
            }

            int answer = a[n - 1] - a[0] - dp[n][2];
            int[] team = new int[n];
            int t = 1;
            for (int i = n, j = 2; i > 0; i--) {
                team[pairs[i - 1].second] = t;

                if (j == 0) {
                    // this is the first person on a new team, so the next person is on a diff team
                    j = 2;
                    t++;
                } else {
                    // reverse loop, so we try not to keep j high (not split teams)
                    for (int k = 2; k >= 0; k--) {
                        if (dp[i - 1][k] == dp[i][j]) {
                            j = k;
                            break;
                        }
                    }
                }
            }

            out.println(Util.join(answer, t - 1));
            out.println(Util.join(team));
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
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