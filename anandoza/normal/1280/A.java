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
        ACutAndPaste solver = new ACutAndPaste();
        solver.solve(1, in, out);
        out.close();
    }

    static class ACutAndPaste {
        static final NumberTheory.Mod107 mod = new NumberTheory.Mod107();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int x = in.nextInt();
            char[] input = in.next().toCharArray();

            long answer = solve(x, input);
            out.println(answer);
        }

        private static long solve(int x, char[] input) {
            x--;
            int n = input.length;
            int[] s = new int[Math.max(x + 1, n)];
            for (int i = 0; i < n; i++) {
                s[i] = input[i] - '0';
            }
            long length = n;
            int cursor = -1;

            while (cursor < x) {
                cursor++;
                int reps = s[cursor] - 1;
                int cutLength = (int) (length - 1 - cursor);
                for (int p = (int) length; p < length + cutLength * reps; p++) {
                    if (p >= s.length)
                        break;
                    s[p] = s[p - cutLength];
                }
                length = length + cutLength * reps;
                if (length >= s.length)
                    break;
            }

            mod.normalize(length);

            while (cursor < x) {
                cursor++;
                int reps = s[cursor] - 1;
                long cutLength = mod.normalize(mod.add(length, -1, -cursor));
                length = mod.add(length, mod.mult(cutLength, reps));
                if (cursor == x)
                    break;
            }

            return length;
        }

    }

    static class NumberTheory {
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

            public long add(long... x) {
                long r = 0;
                for (long i : x)
                    r = add(r, i);
                return r;
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
}