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
        FBalancedDominoPlacements solver = new FBalancedDominoPlacements();
        solver.solve(1, in, out);
        out.close();
    }

    static class FBalancedDominoPlacements {
        static final NumberTheory.ModM mod = new NumberTheory.ModM(998244353);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();
            int n = in.nextInt();

            boolean[] row = new boolean[h];
            boolean[] col = new boolean[w];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    int x = in.nextInt() - 1;
                    int y = in.nextInt() - 1;
                    row[x] = true;
                    col[y] = true;
                }
            }

            boolean[][] twoAllowed = new boolean[2][];
            twoAllowed[0] = findChunks(row);
            twoAllowed[1] = findChunks(col);

            long[][][] count = new long[2][][];
            for (int i = 0; i < 2; i++) {
                count[i] = populate(twoAllowed[i]);
            }

            long answer = 0;
            for (int a = 0; a <= h; a++) {
                for (int b = 0; b <= w; b++) {
                    long prod = mod.mult(count(count[0], a, b, twoAllowed[0].length), count(count[1], b, a, twoAllowed[1].length));
                    prod = mod.mult(prod, mod.mult(mod.fact(a), mod.fact(b)));
                    answer = mod.add(answer, prod);
                }
            }

            out.println(answer);
        }

        private long count(long[][] count, int one, int two, int total) {
            if (one >= count.length || two >= count.length)
                return 0;

            int ghost = total - one - 2 * two;
            if (ghost < 0)
                return 0;

            one += ghost;
            long result = count[one][two];
            result = mod.mult(result, mod.ncr(one, ghost));

            return result;
        }

        private long[][] populate(boolean[] twoAllowed) {
            long[][] count = new long[twoAllowed.length + 1][twoAllowed.length + 1];
            for (int one = 0, two = 0; f(one, two) < twoAllowed.length; one++) {
                count[one][0] = 1;
            }
            for (int one = 0, two = 1; f(one, two) < twoAllowed.length; two++) {
                if (twoAllowed[f(one, two)]) {
                    count[0][two] = count[0][two - 1];
                }
            }

            for (int one = 1; f(one, 0) < twoAllowed.length; one++) {
                for (int two = 1; f(one, two) < twoAllowed.length; two++) {
                    count[one][two] = mod.add(count[one][two], count[one - 1][two]);
                    if (twoAllowed[f(one, two)]) {
                        count[one][two] = mod.add(count[one][two], count[one][two - 1]);
                    }
                }
            }

            return count;
        }

        static int f(int one, int two) {
            return one + 2 * two - 1;
        }

        private boolean[] findChunks(boolean[] blocked) {
            List<Integer> chunks = new ArrayList<>();

            for (int i = 0, j = 0; i < blocked.length; i = j) {
                while (j < blocked.length && blocked[i] == blocked[j])
                    j++;

                if (!blocked[i]) {
                    chunks.add(j - i);
                }
            }

            int sum = 0;
            for (int x : chunks) {
                sum += x;
            }

            boolean[] twoAllowed = new boolean[sum];
            Arrays.fill(twoAllowed, true);
            for (int i = 0, index = 0; i < chunks.size(); i++) {
                twoAllowed[index] = false;
                index += chunks.get(i);
            }

            return twoAllowed;
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
                return normalize(a + b);
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