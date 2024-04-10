import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.function.LongBinaryOperator;
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
        FNumberOfSubsequences solver = new FNumberOfSubsequences();
        solver.solve(1, in, out);
        out.close();
    }

    static class FNumberOfSubsequences {
        NumberTheory.Mod107 mod = new NumberTheory.Mod107();
        private static final char A = 'a';
        private static final char B = 'b';
        private static final char C = 'c';
        private static final char Q = '?';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();

            int[] a = new int[n + 1];
            for (int i = 0; i < n; i++) {
                a[i + 1] = a[i] + (s[i] == A ? 1 : 0);
            }
            int[] c = new int[n + 1];
            for (int i = 0; i < n; i++) {
                c[i + 1] = c[i] + (s[i] == C ? 1 : 0);
            }
            int[] q = new int[n + 1];
            for (int i = 0; i < n; i++) {
                q[i + 1] = q[i] + (s[i] == Q ? 1 : 0);
            }

            long ans = 0;
            long[] threes = new long[n + 1];
            threes[0] = 1;
            for (int i = 1; i < threes.length; i++) {
                threes[i] = mod.mult(threes[i - 1], 3);
            }
            LongBinaryOperator count = (letters, questions) -> {
                long res = mod.mult(letters, threes[(int) questions]);
                if (questions > 0)
                    res = mod.add(res, mod.mult(questions, threes[(int) (questions - 1)]));
                return res;
            };
            for (int i = 1; i + 1 < n; i++) {
                if (s[i] != B && s[i] != Q)
                    continue;

                long left = count.applyAsLong(a[i], q[i]);
                long right = count.applyAsLong(c[n] - c[i + 1], q[n] - q[i + 1]);

                ans = mod.add(ans, mod.mult(left, right));
            }

            out.println(ans);
        }

    }

    static class IntStack {
        public int[] array;
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

    static class NumberTheory {
        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            final IntStack factorial = new IntStack();
            final IntStack invFactorial = new IntStack();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.push(1);
                invFactorial.push(1);
            }

            public long add(long a, long b) {
                long v = a + b;
                return v < modulus() ? v : v - modulus();
            }

            public long mult(long a, long b) {
                return (a * b) % modulus();
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

    }
}