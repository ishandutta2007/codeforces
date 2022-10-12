import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
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
        FRedWhiteFence solver = new FRedWhiteFence();
        solver.solve(1, in, out);
        out.close();
    }

    static class FRedWhiteFence {
        static final NumberTheory.Mod998 mod = new NumberTheory.Mod998();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] red = in.readIntArray(k);
            int Q = in.nextInt();
            int[] q = in.readIntArray(Q);
            for (int i = 0; i < Q; i++)
                q[i] /= 2;
            final int MAX_DEGREE = Util.max(q) + 1;

            int[] count = new int[Util.max(a) + 1];
            for (int x : a) {
                count[x]++;
            }

            long[] answer = new long[MAX_DEGREE];
            for (int r : red) {
                int one = 0, two = 0;
                for (int x = 0; x < Math.min(r, count.length); x++) {
                    if (count[x] == 1)
                        one++;
                    else if (count[x] > 1)
                        two++;
                }

                Polynomial<NumberTheory.Mod998> o = new Polynomial<>(Math.max(0, MAX_DEGREE - r), mod);
                long pow2 = 1;
                for (int i = 0; i < o.coeff.length; i++, pow2 = mod.mult(pow2, 2)) {
                    o.coeff[i] = mod.mult(mod.ncr(one, i), pow2);
                    if (o.coeff[i] == 0) {
                        o = o.truncateDegree(i);
                        break;
                    }
                }
                Polynomial<NumberTheory.Mod998> t = new Polynomial<>(Math.max(0, MAX_DEGREE - r), mod);
                for (int i = 0; i < t.coeff.length; i++) {
                    t.coeff[i] = mod.ncr(2 * two, i);
                    if (t.coeff[i] == 0) {
                        t = t.truncateDegree(i);
                        break;
                    }
                }
                Polynomial<NumberTheory.Mod998> p = o.multFFT(t);
                for (int i = 0; i < p.coeff.length && i + r + 1 < answer.length; i++) {
                    answer[i + r + 1] = mod.add(answer[i + r + 1], p.coeff[i]);
                }
            }

            for (int x : q) {
                out.println(answer[x]);
            }
        }

    }

    static class Util {
        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

        public static void swap(long[] x, int i, int j) {
            long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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

            public long fact(int n) {
                while (factorial.size() <= n) {
                    factorial.add(mult(factorial.get(factorial.size() - 1), factorial.size()));
                }

                return factorial.get(n);
            }

            public long fInv(int n) {
                while (invFactorial.size() <= n) {
                    invFactorial.add(div(invFactorial.get(invFactorial.size() - 1), invFactorial.size()));
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

            public long mult(long a, long b) {
                return (a * b) % modulus();
            }

            public long div(long a, long b) {
                return mult(a, inv(b));
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

            public Polynomial<M> create(long... coeff) {
                return new Polynomial(this, coeff);
            }

            public long totient() {
                throw new UnsupportedOperationException("need to implement this");
            }

            public long generator() {
                throw new UnsupportedOperationException("need to implement this");
            }

            public long unityRoot(int degree) {
                ASSERT(totient() % degree == 0);
                return pow(generator(), totient() / degree);
            }

        }

        public static class Mod998 extends NumberTheory.Modulus<NumberTheory.Mod998> {
            public long modulus() {
                return 998_244_353L;
            }

            public long totient() {
                return modulus() - 1;
            }

            public long generator() {
                return 3;
            }

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

    static class Polynomial<M extends NumberTheory.Modulus<M>> {
        public final long[] coeff;
        public final int n;
        public final M m;

        public Polynomial(int degree, M modulus, long... coeff) {
            m = modulus;
            n = degree;
            this.coeff = new long[n + 1];
            for (int i = 0; i < Math.min(this.coeff.length, coeff.length); i++) {
                this.coeff[i] = coeff[i];
            }
        }

        public Polynomial(M modulus, long... coeff) {
            m = modulus;
            n = coeff.length - 1;
            this.coeff = new long[n + 1];
            for (int i = 0; i <= n; i++) {
                this.coeff[i] = coeff[i];
            }
        }

        public Polynomial<M> mult(Polynomial<M> other) {
            long[] result = new long[n + other.n + 1];
            long threshold = Long.MAX_VALUE - m.modulus() * m.modulus();
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= other.n; j++) {
                    result[i + j] += coeff[i] * other.coeff[j];
                    if (result[i + j] >= threshold) {
                        result[i + j] %= m.modulus();
                    }
                }
            }
            for (int i = 0; i < result.length; i++) {
                result[i] %= m.modulus();
            }
            return m.create(result);
        }

        public Polynomial<M> multFFT(Polynomial<M> other) {
            if (Math.min(n, other.n) < 100) {
                return this.mult(other);
            }

            int resultDegree = n + other.n;
            int resultLength = resultDegree + 1;
            int resultLengthBig = Integer.highestOneBit(resultLength);
            if (resultLengthBig == resultLength)
                resultLengthBig *= 2;
            resultLengthBig *= 2;
            int resultDegreeBig = resultLengthBig - 1;

            boolean eq = Arrays.equals(coeff, other.coeff);
            Polynomial<M> a = new Polynomial<>(resultDegreeBig, m, coeff);
            a.inPlaceFFT(false);
            if (!eq) {
                Polynomial<M> b = new Polynomial<>(resultDegreeBig, m, other.coeff);
                b.inPlaceFFT(false);
                for (int i = 0; i < a.coeff.length; i++) {
                    a.coeff[i] = m.mult(a.coeff[i], b.coeff[i]);
                }
            } else {
                for (int i = 0; i < a.coeff.length; i++) {
                    a.coeff[i] = m.mult(a.coeff[i], a.coeff[i]);
                }
            }
            a.inPlaceFFT(true);
            return new Polynomial<>(resultDegree, m, a.coeff);
        }

        public void inPlaceFFT(boolean inverse) {
            Util.ASSERT(Integer.bitCount(n + 1) == 1);

            for (int i = 1, j = 0; i < n + 1; i++) {
                for (int k = (n + 1) >> 1; (j ^= k) < k; k >>= 1)
                    ;

                if (i < j)
                    Util.swap(coeff, i, j);
            }

            for (int l = 1; l < n + 1; l <<= 1) {
                long[] unityRoots = new long[2 * l + 1];
                unityRoots[0] = 1;
                unityRoots[1] = m.unityRoot(2 * l);
                for (int i = 2; i < unityRoots.length; i++) {
                    unityRoots[i] = m.mult(unityRoots[i - 1], unityRoots[1]);
                }
                for (int i = 0; i < n + 1; i += 2 * l) {
                    for (int j = 0; j < l; j++) {
                        int wIndex = inverse ? 2 * l - j : j;
                        long w = unityRoots[wIndex];
                        long u = coeff[i + j];
                        long v = m.mult(coeff[i + j + l], w);
                        coeff[i + j] = m.add(u, v);
                        coeff[i + j + l] = m.subtract(u, v);
                    }
                }
            }

            if (inverse) {
                long nInv = m.inv(n + 1);
                for (int i = 0; i < n + 1; i++) {
                    coeff[i] = m.mult(coeff[i], nInv);
                }
            }
        }

        public Polynomial<M> truncateDegree(int newDegree) {
            if (newDegree >= n)
                return this;
            long[] result = new long[newDegree + 1];
            System.arraycopy(this.coeff, 0, result, 0, result.length);
            return m.create(result);
        }

        public String toString() {
            return Arrays.toString(coeff);
        }

    }
}