import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
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
        DNewYearAndConference solver = new DNewYearAndConference();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNewYearAndConference {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Pair<Integer, Integer>[] a = new Pair[n];
            Pair<Integer, Integer>[] b = new Pair[n];
            for (int i = 0; i < n; i++) {
                a[i] = Pair.of(in.nextInt(), in.nextInt());
                b[i] = Pair.of(in.nextInt(), in.nextInt());
            }

            boolean answer = verify(a, b);
            answer &= verify(b, a);

            out.println(answer ? "YES" : "NO");
        }

        private boolean verify(Pair<Integer, Integer>[] a, Pair<Integer, Integer>[] b) {
            final int n = a.length;
            DNewYearAndConference.Segment[] seg = new DNewYearAndConference.Segment[2 * n];
            for (int i = 0; i < n; i++) {
                seg[i] = new DNewYearAndConference.Segment(a[i].first, b[i].first, b[i].second, true);
                seg[i + n] = new DNewYearAndConference.Segment(a[i].second, b[i].first, b[i].second, false);
            }
            Arrays.sort(seg, Comparator.comparingInt((DNewYearAndConference.Segment i) -> i.x).thenComparingInt(i ->
                    i.start ? 0 : 1));

            TreeMap<Integer, Integer> maxLeft = new TreeMap<>();
            TreeMap<Integer, Integer> minRight = new TreeMap<>();

            for (DNewYearAndConference.Segment s : seg) {
                if (s.start) {
                    add(maxLeft, s.y1);
                    add(minRight, s.y2);
                } else {
                    remove(maxLeft, s.y1);
                    remove(minRight, s.y2);
                }

                if (!maxLeft.isEmpty() && maxLeft.lastKey() > minRight.firstKey())
                    return false;
            }

            return true;
        }

        private void remove(TreeMap<Integer, Integer> set, int y1) {
            set.merge(y1, -1, Integer::sum);
            if (set.get(y1) == 0)
                set.remove(y1);
        }

        private void add(TreeMap<Integer, Integer> set, int y1) {
            set.merge(y1, 1, Integer::sum);
        }

        static class Segment {
            final int x;
            final int y1;
            final int y2;
            final boolean start;

            Segment(int x, int y1, int y2, boolean start) {
                this.x = x;
                this.y1 = y1;
                this.y2 = y2;
                this.start = start;
            }

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

    }
}