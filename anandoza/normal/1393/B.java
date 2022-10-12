import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.HashMap;
import java.io.InputStreamReader;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
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
        BApplejackAndStorages solver = new BApplejackAndStorages();
        solver.solve(1, in, out);
        out.close();
    }

    static class BApplejackAndStorages {
        private Counter<Integer> c;
        private SortedCounter<Integer> counts;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            c = new Counter<>();
            counts = new SortedCounter<>();
            for (int x : a)
                add(x);

            int queries = in.nextInt();
            for (int q = 0; q < queries; q++) {
                char type = in.next().charAt(0);
                int x = in.nextInt();
                if (type == '+')
                    add(x);
                else
                    sub(x);

                boolean sq = false, re = false;
                if (counts.distinct() > 0 && counts.count.lastKey() >= 4) {
                    sq = true;
                    int k = counts.count.lastKey();
                    counts.decr(k);
                    counts.incr(k - 4);
                    if (counts.distinct() > 0) {
                        if (counts.count.lastKey() >= 4 || counts.count.lastKey() >= 2 && counts.count.lastEntry().getValue() >= 2 || counts.distinct() >= 2 && counts.count.lastKey() >= 2 && counts.count.lowerKey(counts.count.lastKey()) >= 2)
                            re = true;
                    }
                    counts.incr(k);
                    counts.decr(k - 4);
                }
                out.println(sq && re ? "YES" : "NO");
            }
        }

        private void add(int x) {
            c.incr(x);
            int y = c.get(x);
            counts.incr(y);
            if (y - 1 != 0)
                counts.decr(y - 1);
        }

        private void sub(int x) {
            c.decr(x);
            int y = c.get(x);
            if (y != 0)
                counts.incr(y);
            counts.decr(y + 1);
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class SortedCounter<T> {
        public final TreeMap<T, Integer> count = new TreeMap<>();

        public SortedCounter() {
        }

        public SortedCounter(T[] elements) {
            for (T t : elements)
                incr(t);
        }

        public SortedCounter(Iterable<T> elements) {
            for (T t : elements)
                incr(t);
        }

        public void incr(T key) {
            count.merge(key, 1, Integer::sum);
        }

        public void decr(T key) {
            count.compute(key, (k, v) -> v - 1 == 0 ? null : v - 1);
        }

        public int distinct() {
            return count.size();
        }

    }

    static class Counter<T> {
        public final HashMap<T, Integer> count = new HashMap<>();

        public Counter() {
        }

        public Counter(T[] elements) {
            for (T t : elements)
                incr(t);
        }

        public Counter(Iterable<T> elements) {
            for (T t : elements)
                incr(t);
        }

        public void incr(T key) {
            count.merge(key, 1, Integer::sum);
        }

        public void decr(T key) {
            count.compute(key, (k, v) -> v - 1 == 0 ? null : v - 1);
        }

        public int get(T key) {
            return count.getOrDefault(key, 0);
        }

    }
}