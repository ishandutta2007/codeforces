import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ARecommendations solver = new ARecommendations();
        solver.solve(1, in, out);
        out.close();
    }

    static class ARecommendations {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] t = in.readIntArray(n);
            Pii[] pairs = new Pii[n];
            for (int i = 0; i < n; i++) {
                pairs[i] = Pii.of(a[i], t[i]);
            }
            Arrays.sort(pairs, Comparator.comparingInt(p -> p.first));

            long answer = 0;
            for (int i = 0, start = 0; i <= n; i++) {
                int count = i - start + 1;
                if (i == n || pairs[start].first + count - 1 <= pairs[i].first) {
                    answer += f(pairs, start, i);
                    start = i;
                }
            }
            out.println(answer);
        }

        private long f(Pii[] orig, int start, int end) {
            if (start == end)
                return 0;

            int left = orig[start].first, right = orig[start].first + (end - start);

            Pii[] pairs = new Pii[end - start];
            for (int i = start; i < end; i++) {
                pairs[i - start] = orig[i];
            }
            Arrays.sort(pairs, Comparator.comparingInt(p -> -p.second));
            TreeSet<Integer> available = new TreeSet<>();
            for (int i = left; i < right; i++) {
                available.add(i);
            }
            long answer = 0;
            for (Pii p : pairs) {
                int target = available.ceiling(p.first);
                answer += (long) (target - p.first) * p.second;
                available.remove(target);
            }
            return answer;
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

    static class Pii {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }
}