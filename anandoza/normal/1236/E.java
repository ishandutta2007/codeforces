import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
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
        EAliceAndTheUnfairGame solver = new EAliceAndTheUnfairGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class EAliceAndTheUnfairGame {
        int n;
        int m;
        TreeMap<Integer, Pair<Integer, Integer>>[] positiveDiags;
        TreeMap<Integer, Pair<Integer, Integer>>[] negativeDiags;
        int[] last;
        int[] a;
        HashMap<Pair<Integer, Integer>, Pair<Integer, Integer>> range;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();

            a = in.readIntArray(m);
            for (int i = 0; i < m; i++) {
                a[i]--; // now a[i] in [0, n)
            }

            if (n == 1) {
                out.println(0);
                return;
            }

            long answer = solve();
            out.println(answer);
        }

        public long solve() {
            last = new int[m];
            for (int i = 0, j = 0; i < m; i = j) {
                while (j < m && a[i] == a[j])
                    j++;

                for (int k = i; k < j; k++) {
                    last[k] = j - 1;
                }
            }

            positiveDiags = new TreeMap[p(n, 0)];
            for (int i = 0; i < p(n, 0); i++) {
                positiveDiags[i] = new TreeMap<>();
            }

            negativeDiags = new TreeMap[n(n, m - 1)];
            for (int i = 0; i < n(n, m - 1); i++) {
                negativeDiags[i] = new TreeMap<>();
            }

            for (int i = 0; i < m; i++) {
                positiveDiags[p(a[i], i)].put(i, Pair.of(a[i], i));
                negativeDiags[n(a[i], i)].put(i, Pair.of(a[i], i));
            }

            range = new HashMap<>();

            long answer = 0;
            Pair<Integer, Integer>[] ranges = new Pair[n];
            for (int i = 0; i < n; i++) {
                if (i == a[0]) {
                    ranges[i] = null;
                    continue;
                }
                ranges[i] = f(Pair.of(i, 0));
            }

            for (int i = 0; i < n; i++) {
                int left = Integer.MAX_VALUE;
                int right = Integer.MIN_VALUE;
                if (i - 1 >= 0 && ranges[i - 1] != null) {
                    left = Math.min(left, ranges[i - 1].first);
                }
                if (ranges[i] != null) {
                    left = Math.min(left, ranges[i].first);
                }
                if (i + 1 < n && ranges[i + 1] != null) {
                    left = Math.min(left, ranges[i + 1].first);
                }

                if (i - 1 >= 0 && ranges[i - 1] != null) {
                    right = Math.max(right, ranges[i - 1].second);
                }
                if (ranges[i] != null) {
                    right = Math.max(right, ranges[i].second);
                }
                if (i + 1 < n && ranges[i + 1] != null) {
                    right = Math.max(right, ranges[i + 1].second);
                }

                right = Math.min(right, n - 1);
                left = Math.max(left, 0);
                int count = right - left + 1;

                //System.out.println(left + " " + right + "  " + count);

                answer += count;
            }

//        System.out.println(range);
//        System.out.println(Arrays.toString(ranges));

            return answer;
        }

        private Pair<Integer, Integer> f(Pair<Integer, Integer> pair) {
            if (!range.containsKey(pair)) {
                TreeMap<Integer, Pair<Integer, Integer>> pDiag = positiveDiags[p(pair.first, pair.second)];
                Map.Entry<Integer, Pair<Integer, Integer>> entry = pDiag.higherEntry(pair.second);
                int right;
                if (entry == null) {
                    right = pair.first + m - pair.second;
                } else {
                    int coord = entry.getValue().first;
                    int height = entry.getValue().second;
                    int nextHeight = last[height];
                    Pair<Integer, Integer> next = Pair.of(coord - 1, nextHeight);
                    right = f(next).second;
                }

                TreeMap<Integer, Pair<Integer, Integer>> nDiag = negativeDiags[n(pair.first, pair.second)];
                entry = nDiag.higherEntry(pair.second);
                int left;
                if (entry == null) {
                    left = pair.first - (m - pair.second);
                } else {
                    int coord = entry.getValue().first;
                    int height = entry.getValue().second;
                    int nextHeight = last[height];
                    Pair<Integer, Integer> next = Pair.of(coord + 1, nextHeight);
                    left = f(next).first;
                }
                left = Math.max(left, 0);
                right = Math.min(right, n - 1);
                range.put(pair, Pair.of(left, right));
            }
            return range.get(pair);
        }

        int p(int a, int i) {
            return a - i + (m - 1);
        }

        int n(int a, int i) {
            return a + i;
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
}