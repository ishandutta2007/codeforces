import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
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
        AGCDTable solver = new AGCDTable();
        solver.solve(1, in, out);
        out.close();
    }

    static class AGCDTable {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n * n);
            SortedCounter<Integer> c = new SortedCounter<>();
            for (int x : a)
                c.incr(x);

            List<Integer> answer = new ArrayList<>();
            while (answer.size() < n) {
                int x = c.count.lastKey();
                for (int i : answer) {
                    c.decr(NumberTheory.gcd(x, i));
                    c.decr(NumberTheory.gcd(x, i));
                }
                c.decr(x);
                answer.add(x);
            }
            out.println(Util.join(answer));
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

    }

    static class NumberTheory {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            int c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
        }

    }

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}