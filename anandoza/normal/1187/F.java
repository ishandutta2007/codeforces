import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
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
        FExpectedSquareBeauty solver = new FExpectedSquareBeauty();
        solver.solve(1, in, out);
        out.close();
    }

    static class FExpectedSquareBeauty {
        NumberTheory.Mod107 mod = new NumberTheory.Mod107();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] l = in.readLongArray(n);
            long[] r = in.readLongArray(n);
            for (int i = 0; i < n; i++)
                r[i]++;
            long[] c = new long[n];
            for (int i = 0; i < n; i++)
                c[i] = r[i] - l[i];
            long[] o = new long[n - 1];
            for (int i = 0; i < n - 1; i++) {
                o[i] = Math.min(r[i], r[i + 1]) - Math.max(l[i], l[i + 1]);
                o[i] = Math.max(o[i], 0);
            }

            long[] p = new long[n - 1];
            long sum = 0;
            for (int i = 0; i < n - 1; i++) {
                p[i] = mod.subtract(1, mod.div(o[i], mod.mult(c[i], c[i + 1])));
                sum = mod.add(sum, p[i]);
            }

            // We want to find (1 + sum(p_i))^2, which is 1 + 2 * sum(p_i) + sum(p_i)^2
            long answer = 0;

            // sum(1 * 1)
            answer = mod.add(answer, 1);

            // 2 * sum(p_i)
            answer = mod.add(answer, mod.mult(2, sum));

            // sum(p_i * p_j) for |i-j| == 0
            answer = mod.add(answer, sum);

            // sum(p_i * p_j) for |i-j| == 1
            for (int i = 0; i + 2 < n; i++) {
                int j = i + 1, k = i + 2;

                long total = mod.mult(c[i], c[j], c[k]);

                long both = Util.min(r[i], r[j], r[k]) - Util.max(l[i], l[j], l[k]);
                both = Math.max(both, 0);

                long first = mod.mult(o[i], c[k]);
                long second = mod.mult(c[i], o[j]);

                // PIE: total - first - second + both
                long pr = mod.subtract(mod.add(total, both), mod.add(first, second));

                pr = mod.div(pr, total);

                // 2x since we can pick i < j or i > j
                answer = mod.add(answer, mod.mult(2, pr));
            }

            // sum(p_i * p_j) for |i-j| > 1
            for (int i = 0; i < n - 1; i++) {
                long pr_i = p[i];

                long tooClose = 0;
                tooClose = mod.add(tooClose, i - 1 >= 0 ? p[i - 1] : 0);
                tooClose = mod.add(tooClose, p[i]);
                tooClose = mod.add(tooClose, i + 1 < n - 1 ? p[i + 1] : 0);

                long pr_j = mod.subtract(sum, tooClose);
                answer = mod.add(answer, mod.mult(pr_i, pr_j));
            }

            out.println(answer);
        }

    }

    static class Util {
        public static long max(long... x) {
            long max = Long.MIN_VALUE;
            for (long i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

        public static long min(long... x) {
            long min = Long.MAX_VALUE;
            for (long i : x) {
                min = Math.min(i, min);
            }
            return min;
        }

        private Util() {
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

            public long subtract(long a, long b) {
                long v = a - b;
                return v < 0 ? v + modulus() : v;
            }

            public long mult(long... x) {
                long r = 1;
                for (long i : x)
                    r = mult(r, i);
                return r;
            }

            public long mult(long a, long b) {
                return (a * b) % modulus();
            }

            public long div(long a, long b) {
                return mult(a, inv(b));
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
}