import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        BJohnnyAndGrandmaster solver = new BJohnnyAndGrandmaster();
        solver.solve(1, in, out);
        out.close();
    }

    static class BJohnnyAndGrandmaster {
        NumberTheory.Mod107 m = new NumberTheory.Mod107();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long p = in.nextLong();

            int[] k = in.readIntArray(n);
            Util.safeSort(k);
            Util.reverse(k);

            if (p == 1) {
                out.println(n % 2);
                return;
            }

            int[] diff = new int[n];
            long d = 0;
            int finalDirection = 0;

            for (int i = 0; i < n; i++) {
                int mult;
                if (finalDirection == 0) {
                    mult = d > 0 ? -1 : 1;
                } else {
                    mult = finalDirection > 0 ? -1 : 1;
                }

                diff[i] = mult;
                d += mult;

                if (d != 0) {
                    if (finalDirection == 0 && i + 1 < n && k[i + 1] != k[i]) {
                        for (int j = 0; j < k[i] - k[i + 1]; j++) {
                            if (finalDirection == 0 && Math.abs(d) > n) {
                                finalDirection = d > 0 ? 1 : -1;
                                break;
                            }
                            d *= p;
                        }
                    }
                }
            }

            long answer = 0;
            for (int i = 0; i < n; i++) {
                answer = m.add(answer, m.normalize(diff[i]));

                if (i + 1 < n && k[i + 1] != k[i]) {
                    answer = m.mult(answer, m.pow(p, k[i] - k[i + 1]));
                }
            }
            answer = m.mult(answer, m.pow(p, k[n - 1]));

            if (finalDirection < 0 || finalDirection == 0 && d < 0) {
                answer = m.negative(answer);
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
            ArrayList<Long> factorial = new ArrayList<>();
            ArrayList<Long> invFactorial = new ArrayList<>();

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

            public long negative(long x) {
                return x == 0 ? 0 : modulus() - x;
            }

            public long pow(long x, int e) {
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

    }

    static class Util {
        public static void safeSort(int[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(int[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(int[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        private Util() {
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}