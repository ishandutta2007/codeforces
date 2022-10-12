import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.BitSet;
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
        GRunningCompetition solver = new GRunningCompetition();
        solver.solve(1, in, out);
        out.close();
    }

    static class GRunningCompetition {
        private static final int CAP = 200_000;
        private static final NumberTheory.Mod998 mod = new NumberTheory.Mod998();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
            int[] a = in.readIntArray(n + 1);

            BitSet possible = getAllDifferences(a);

            int q = in.nextInt();
            for (int query = 0; query < q; query++) {
                int l = in.nextInt() / 2;

                List<Integer> divisors = new ArrayList<>();
                for (int d = 1; d * d <= l; d++) {
                    if (l % d != 0)
                        continue;

                    divisors.add(d);
                    divisors.add(l / d);
                }

                int answer = -1;
                for (int d : divisors) {
                    if (d - y > 0 && possible.get(d - y))
                        answer = Math.max(answer, 2 * d);
                }

                out.print(answer + " ");
            }
            out.println();
        }

        private static BitSet getAllDifferences(int[] a) {
            final int n = a.length;

            Polynomial<NumberTheory.Mod998> poly = new Polynomial<>(CAP, mod);
            for (int x : a) {
                poly.coeff[x]++;
            }
            Polynomial<NumberTheory.Mod998> poly2 = new Polynomial<>(CAP, mod);
            for (int x : a) {
                poly2.coeff[CAP - x]++;
            }
            Polynomial<NumberTheory.Mod998> sums = poly.multFFT(poly2);

            BitSet possible = new BitSet();
            for (int i = 1; i <= CAP; i++) {
                if (sums.coeff[i + CAP] != 0)
                    possible.set(i);
            }

            return possible;
        }

    }

    static class Util {
        public static void swap(long[] x, int i, int j) {
            long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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

    static class Polynomial<M extends NumberTheory.Modulus<M>> {
        public final long[] coeff;
        public final int n;
        public final M m;

        public Polynomial(int degree, M modulus, long... coeff) {
            m = modulus;
            n = degree;
            this.coeff = new long[n + 1];
            if (Math.min(this.coeff.length, coeff.length) >= 0)
                System.arraycopy(coeff, 0, this.coeff, 0, Math.min(this.coeff.length, coeff.length));
        }

        public Polynomial(M modulus, long... coeff) {
            m = modulus;
            n = coeff.length - 1;
            this.coeff = new long[n + 1];
            System.arraycopy(coeff, 0, this.coeff, 0, n + 1);
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

        public String toString() {
            return Arrays.toString(coeff);
        }

    }
}