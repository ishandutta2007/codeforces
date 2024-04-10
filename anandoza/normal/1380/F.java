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
import java.util.function.IntFunction;

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
        FStrangeAddition solver = new FStrangeAddition();
        solver.solve(1, in, out);
        out.close();
    }

    static class FStrangeAddition {
        private static final NumberTheory.Mod998 mod = new NumberTheory.Mod998();
        private static final int[] ways = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[] c = in.next().toCharArray();

            FastSegmentTree<FStrangeAddition.V> st = new FastSegmentTree<>(n, FStrangeAddition.V::new, true);

            for (int i = 0; i < c.length; i++) {
                st.value.create(c[i] - '0');
                st.update_LAZY(i);
            }
            st.rebuild();

            for (int i = 0; i < m; i++) {
                int x = in.nextInt() - 1;
                int d = in.nextInt();
                st.value.create(d);
                st.update(x);

                out.println(st.value.answer[1]);
            }
        }

        public static final class V implements FastSegmentTree.Storage<FStrangeAddition.V> {
            final long[] answer;
            final long[] answerExceptLeft;
            final long[] answerExceptRight;
            final long[] answerExceptBoth;
            final int[] left;
            final int[] right;

            public V(int capacity) {
                answer = new long[capacity];
                answerExceptLeft = new long[capacity];
                answerExceptRight = new long[capacity];
                answerExceptBoth = new long[capacity];
                left = new int[capacity];
                right = new int[capacity];
            }

            public void clear(int i) {
                answer[i] = -1;
            }

            public void set(int to, int from) {
                left[to] = left[from];
                right[to] = right[from];
                answer[to] = answer[from];
                answerExceptLeft[to] = answerExceptLeft[from];
                answerExceptRight[to] = answerExceptRight[from];
                answerExceptBoth[to] = answerExceptBoth[from];
            }

            public void combine(int target, int l, int r) {
                if (answer[l] == -1) {
                    set(target, r);
                    return;
                }
                if (answer[r] == -1) {
                    set(target, l);
                    return;
                }
                left[target] = left[l];
                right[target] = right[r];
                int middleDigit = right[l] * 10 + left[r];
                long w = middleDigit < ways.length ? ways[middleDigit] : 0;
                if (right[l] == 0)
                    w = 0;
                answerExceptRight[target] = mod.add(mod.mult(answer[l], answerExceptRight[r]), mod.mult(answerExceptRight[l], answerExceptBoth[r], w));
                answerExceptLeft[target] = mod.add(mod.mult(answerExceptLeft[l], answer[r]), mod.mult(answerExceptBoth[l], answerExceptLeft[r], w));
                answerExceptBoth[target] = mod.add(mod.mult(answerExceptLeft[l], answerExceptRight[r]), mod.mult(answerExceptBoth[l], answerExceptBoth[r], w));
                answer[target] = mod.add(mod.mult(answer[l], answer[r]), mod.mult(answerExceptRight[l], answerExceptLeft[r], w));
            }

            public void create(int digit) {
                left[0] = right[0] = digit;
                answerExceptLeft[0] = answerExceptRight[0] = 1;
                answerExceptBoth[0] = 0;
                answer[0] = ways[digit];
            }

        }

    }

    static class NumberTheory {
        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            final ArrayList<Long> factorial = new ArrayList<>();
            final ArrayList<Long> invFactorial = new ArrayList<>();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.add(1L);
                invFactorial.add(1L);
            }

            public long add(long a, long b) {
                long v = a + b;
                return v < modulus() ? v : v - modulus();
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

        }

        public static class Mod998 extends NumberTheory.Modulus<NumberTheory.Mod998> {
            public long modulus() {
                return 998_244_353L;
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

    }

    static class FastSegmentTree<T extends FastSegmentTree.Storage<T>> {
        public final int size;
        public final T value;

        public FastSegmentTree(int size, IntFunction<T> constructor) {
            this.size = size;
            value = constructor.apply(2 * size + 4);
            for (int i = 0; i < 2 * size + 2; i++) {
                value.clear(i);
            }
        }

        public FastSegmentTree(int size, IntFunction<T> constructor, boolean powerOfTwo) {
            this(powerOfTwo ? powerOfTwo(size) : size, constructor);
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value.combine(i, 2 * i, 2 * i + 1);
            }
        }

        public void update(int i) {
            i += size;
            value.set(i, 0);
            while (i > 1) {
                i /= 2;
                value.combine(i, 2 * i, 2 * i + 1);
            }
        }

        public void update_LAZY(int i) {
            i += size;
            value.set(i, 0);
        }

        private static int powerOfTwo(int n) {
            int powerOfTwo = Integer.highestOneBit(n);
            if (powerOfTwo < n)
                powerOfTwo *= 2;
            return powerOfTwo;
        }

        public interface Storage<T extends FastSegmentTree.Storage<T>> {
            void clear(int i);

            void set(int to, int from);

            void combine(int target, int left, int right);

        }

    }
}