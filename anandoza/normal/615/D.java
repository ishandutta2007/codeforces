import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        DMultipliers solver = new DMultipliers();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMultipliers {
        NumberTheory.Mod107 mod = new NumberTheory.Mod107();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int m = in.nextInt();
            long[] primes = in.readLongArray(m);
            Counter<Long> count = new Counter<>();
            for (long x : primes)
                count.incr(x);

            long[] p = new long[count.distinct()];
            long[] c = new long[count.distinct()];
            int n = 0;
            for (Map.Entry<Long, Integer> entry : count.count.entrySet()) {
                p[n] = entry.getKey();
                c[n] = entry.getValue();
                n++;
            }

            NumberTheory.ModM mod106 = new NumberTheory.ModM(mod.modulus() - 1);
            LongSegmentTree ways = new LongSegmentTree(n, (a, b) -> mod106.mult(a, b), 1);
            for (int i = 0; i < n; i++) {
                ways.update_LAZY(i, c[i] + 1);
            }
            ways.rebuild();

            long answer = 1;
            for (int i = 0; i < n; i++) {
                long w = ways.queryExcept(i);

                long exp = 0;
                for (int j = 1; j <= c[i]; j++) {
                    exp = mod106.add(exp, mod106.mult(j, w));
                }

                answer = mod.mult(answer, mod.pow(p[i], exp));
            }

            out.println(answer);
        }

    }

    static class NumberTheory {
        private static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            final ArrayList<Long> factorial = new ArrayList<>();
            final ArrayList<Long> invFactorial = new ArrayList<>();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.add(1L);
                invFactorial.add(1L);
            }

            public long normalize(long x) {
                x %= modulus();
                if (x < 0)
                    x += modulus();
                return x;
            }

            public long add(long a, long b) {
                long v = a + b;
                return v < modulus() ? v : v - modulus();
            }

            public long mult(long a, long b) {
                return (a * b) % modulus();
            }

            public long pow(long x, long e) {
                if (e < 0) {
                    x = inv(x);
                    e *= -1;
                }
                if (e == 0)
                    return 1;
                if ((e & 1) > 0)
                    return mult(x, pow(x, e - 1));
                return pow(mult(x, x), e / 2);
            }

            public long inv(long value) {
                long g = modulus(), x = 0, y = 1;
                for (long r = value; r != 0; ) {
                    long q = g / r;
                    g %= r;

                    long temp = g;
                    g = r;
                    r = temp;

                    x -= q * y;

                    temp = x;
                    x = y;
                    y = temp;
                }

                ASSERT(g == 1);
                ASSERT(y == modulus() || y == -modulus());

                return normalize(x);
            }

        }

        public static class Mod107 extends NumberTheory.Modulus<NumberTheory.Mod107> {
            public long modulus() {
                return 1_000_000_007L;
            }

        }

        public static class ModM extends NumberTheory.Modulus<NumberTheory.ModM> {
            private final long modulus;

            public ModM(long modulus) {
                this.modulus = modulus;
            }

            public long modulus() {
                return modulus;
            }

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

        public int distinct() {
            return count.size();
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }

    static class LongSegmentTree {
        public final int size;
        public final long[] value;
        protected final LongSegmentTree.Combiner combiner;
        protected final long identityElement;

        public LongSegmentTree(int size, LongSegmentTree.Combiner combiner, long identityElement) {
            this.size = size;
            value = new long[2 * size];
            Arrays.fill(value, identityElement);
            this.combiner = combiner;
            this.identityElement = identityElement;
        }

        protected long combine(long a, long b) {
            return combiner.combine(a, b);
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = combine(value[2 * i], value[2 * i + 1]);
            }
        }

        public void update_LAZY(int i, long v) {
            i += size;
            value[i] = v;
        }

        public long query(int i, int j) {
            long res_left = identityElement, res_right = identityElement;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1)
                    res_left = combine(res_left, value[i++]);
                if ((j & 1) == 1)
                    res_right = combine(value[--j], res_right);
            }
            return combine(res_left, res_right);
        }

        public long queryExcept(int i) {
            if (i == 0)
                return query(i + 1, size);
            if (i == size - 1)
                return query(0, i);
            return combine(query(0, i), query(i + 1, size));
        }

        public interface Combiner {
            long combine(long a, long b);

        }

    }
}