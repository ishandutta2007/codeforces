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
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CTheFootballSeason solver = new CTheFootballSeason();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTheFootballSeason {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long p = in.nextLong();
            long w = in.nextLong();
            long d = in.nextLong();
            long g = NumberTheory.gcd(w, d);
            if (p % g != 0) {
                out.println(-1);
                return;
            }
            w /= g;
            d /= g;
            p /= g;

            NumberTheory.ModM modW = new NumberTheory.ModM(w);
            NumberTheory.ModM modD = new NumberTheory.ModM(d);

            long y0 = modW.div(modW.normalize(p), d); // y == y0 == p/d mod W
            long x0 = modD.div(modD.normalize(p), w); // x == x0 mod D

            long x = (p - y0 * d) / w;
            long y = y0;

            if (x + y > n || x < 0) {
                out.println(-1);
                return;
            }

            out.println(Util.join(x, y, n - x - y));
        }

    }

    static class Util {
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    static class NumberTheory {
        public static long gcd(long a, long b) {
            long c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
        }

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

            public long mult(long a, long b) {
                return normalize(a * b);
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
}