import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
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
        CPrimesAndMultiplication solver = new CPrimesAndMultiplication();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPrimesAndMultiplication {
        NumberTheory.Mod107 m = new NumberTheory.Mod107();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int x = in.nextInt();
            long n = in.nextLong();

            long[] primes = primes(x);

            long answer = 1;
            for (long p : primes) {
                answer = m.mult(answer, m.pow(p, count(p, n)));
            }

            out.println(answer);
        }

        private long count(long p, long n) {
            long result = 0;
            while (n > 0) {
                n /= p;
                result += n;
            }
            return result;
        }

        private long[] primes(int x) {
            HashSet<Integer> primes = new HashSet<>();
            for (int i = 2; i * i <= x; i++) {
                while (x % i == 0) {
                    x /= i;
                    primes.add(i);
                }
            }

            if (x != 1) {
                primes.add(x);
            }

            long[] arr = new long[primes.size()];
            int index = 0;
            for (int i : primes) {
                arr[index++] = i;
            }

            return arr;
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

            public long mult(long a, long b) {
                return normalize(a * b);
            }

            public long pow(long x, long e) {
                if (e == 0)
                    return 1;
                if ((e & 1) > 0)
                    return mult(x, pow(x, e - 1));
                return pow(mult(x, x), e / 2);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}