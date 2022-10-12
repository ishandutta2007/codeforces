import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
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
        CSkyFullOfStars solver = new CSkyFullOfStars();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSkyFullOfStars {
        NumberTheory.Mod998 mod = new NumberTheory.Mod998();
        private static final int Z = 3;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            long first = 0;
            long zN = mod.pow(Z, n);
            long zK = 1;
            long zNNK = mod.pow(zN, n);
            long zNinv = mod.inv(zN);
            for (int k = 0; k <= n; k++) {
                long term = mod.mult(mod.ncr(n, k), zK, zNNK, parity(k));
                first = mod.add(first, term);
                zK = mod.mult(zK, Z);
                zNNK = mod.mult(zNNK, zNinv);
            }
            first = mod.mult(first, 2);
            long zNN = mod.pow(Z, (long) n * n);
            first = mod.subtract(first, zNN);

            long second = 0;
            long zKN = mod.pow(Z, 1 - n);
            long zNNKN = mod.mult(zNN, Z);
            for (int k = 1; k <= n; k++) {
                zNNKN = mod.mult(zNNKN, zNinv);
                long x = mod.mult(mod.ncr(n, k), zNNKN);
                if ((k & 1) == 1)
                    x = mod.negative(x);
                long summation = mod.add(mod.negative(1), mod.pow(mod.subtract(1, zKN), n));
                second = mod.add(second, mod.mult(x, summation));
                zKN = mod.mult(zKN, Z);
            }

            long answer = mod.add(first, second);
            answer = mod.subtract(zNN, answer);

            out.println(answer);
        }

        private long parity(int k) {
            return (k & 1) == 0 ? 1 : mod.negative(1);
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

    }

    static class NumberTheory {
        private static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            final IntStack factorial = new IntStack();
            final IntStack invFactorial = new IntStack();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.push(1);
                invFactorial.push(1);
            }

            public long fact(int n) {
                while (factorial.size() <= n) {
                    factorial.push((int) mult(factorial.get(factorial.size() - 1), factorial.size()));
                }

                return factorial.get(n);
            }

            public long fInv(int n) {
                int lastKnown = invFactorial.size() - 1;

                if (lastKnown < n) {
                    long[] fInv = new long[n - lastKnown];
                    fInv[0] = inv(fact(n));
                    for (int i = 1; i < fInv.length; i++) {
                        fInv[i] = mult(fInv[i - 1], n - i + 1);
                    }
                    for (int i = fInv.length - 1; i >= 0; i--) {
                        invFactorial.push((int) fInv[i]);
                    }
                }

                return invFactorial.get(n);
            }

            public long ncr(int n, int r) {
                ASSERT(n >= 0);
                if (r < 0 || n < r)
                    return 0;
                return mult(fact(n), mult(fInv(r), fInv(n - r)));
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

        public static class Mod998 extends NumberTheory.Modulus<NumberTheory.Mod998> {
            public long modulus() {
                return 998_244_353L;
            }

        }

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }

    static class IntStack {
        int[] array;
        int size = 0;

        public IntStack() {
            this(8);
        }

        public IntStack(int capacity) {
            array = new int[capacity];
        }

        public void push(int item) {
            if (size >= array.length)
                array = resize(array);
            array[size++] = item;
        }

        public int size() {
            return size;
        }

        public int get(int i) {
            Util.ASSERT(i < size);
            return array[i];
        }

        private static int[] resize(int[] array) {
            int[] newArray = new int[array.length << 1];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        public String toString() {
            int[] trimmed = new int[size];
            System.arraycopy(array, 0, trimmed, 0, size);
            return Arrays.toString(trimmed);
        }

    }
}