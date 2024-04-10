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
        DStringMark solver = new DStringMark();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStringMark {
        private static final NumberTheory.Mod107 mod = new NumberTheory.Mod107();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] aInput = in.next().toCharArray();
            char[] bInput = in.next().toCharArray();
            final int n = aInput.length;

            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = aInput[i] - 'a';
                b[i] = bInput[i] - 'a';
            }

            int[] larger = new int[n];
            int[] count = new int[26];
            for (int i = 0; i < n; i++) {
                count[a[i]]++;
            }
            int index = 0;
            for (int i = 0; i < n; i++) {
                int next = -1;
                if (count[b[i]] > 0) {
                    next = b[i];
                } else {
                    for (int j = b[i]; j >= 0; j--) {
                        if (count[j] > 0) {
                            next = j;
                            break;
                        }
                    }
                }
                if (next == -1) {
                    index = i;
                    break;
                }
                larger[i] = next;
                count[next]--;
                if (next < b[i]) {
                    index = i + 1;
                    break;
                }
            }

            for (int i = count.length - 1; i >= 0; i--) {
                while (count[i] > 0) {
                    larger[index++] = i;
                    count[i]--;
                }
            }

            long upper = rank(larger, mod);
            long lower = rank(a, mod);
            long answer = mod.add(upper, mod.negative(lower));

            answer = mod.subtract(answer, 1);
            for (int i = 0; i < n; i++) {
                if (larger[i] != b[i]) {
                    if (larger[i] < b[i])
                        answer = mod.add(answer, 1);
                    break;
                }
            }

            out.println(answer);
        }

        public static long rank(int[] p, NumberTheory.Modulus mod) {
            final int MAX = 26;
            final int n = p.length;

            int[] count = new int[MAX];
            for (int i = 0; i < n; i++) {
                count[p[i]]++;
            }
            IntSumSegmentTree sum = new IntSumSegmentTree(MAX);
            for (int i = 0; i < MAX; i++) {
                sum.update_LAZY(i, count[i]);
            }
            sum.rebuild();

            long rank = 0;
            long total = mod.fact(n);
            for (int i = 0; i < MAX; i++) {
                total = mod.mult(total, mod.fInv(count[i]));
            }

            long[] modInv = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                modInv[i] = mod.inv(i);
            }
            for (int i = 0; i < n; i++) {
                int cur = p[i];
                long earlier = 0;
                long less = sum.query(0, cur);
                earlier = mod.add(earlier, mod.mult(total, less, modInv[n - i]));
                rank = mod.add(rank, earlier);
                total = mod.mult(total, sum.get(cur), modInv[n - i]);
                sum.update(cur, sum.get(cur) - 1);
            }

            return rank;
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

            public long negative(long x) {
                return x == 0 ? 0 : modulus() - x;
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

    static class IntSumSegmentTree {
        public int size;
        public int[] value;

        public IntSumSegmentTree(int size) {
            this.size = size;
            value = new int[2 * size];
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = value[2 * i] + value[2 * i + 1];
            }
        }

        public int get(int i) {
            return value[size + i];
        }

        public void update(int i, int v) {
            i += size;
            value[i] = v;
            while (i > 1) {
                i /= 2;
                value[i] = value[2 * i] + value[2 * i + 1];
            }
        }

        public void update_LAZY(int i, int v) {
            i += size;
            value[i] = v;
        }

        public int query(int i, int j) {
            int res_left = 0, res_right = 0;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1) {
                    int b = value[i++];
                    res_left = res_left + b;
                }
                if ((j & 1) == 1) {
                    int a = value[--j];
                    res_right = a + res_right;
                }
            }
            return res_left + res_right;
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

    }
}