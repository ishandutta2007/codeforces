import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
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
        BCountPairs solver = new BCountPairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class BCountPairs {
        NumberTheory.ModM m;
        long k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long p = in.nextInt();
            k = in.nextInt();

            m = new NumberTheory.ModM(p);

            HashMap<Long, Integer> count = new HashMap<>();

            for (int i = 0; i < n; i++) {
                long x = in.nextInt();
                long f = f(x);
                count.put(f, count.getOrDefault(f, 0) + 1);
            }

            long answer = 0;
            for (long c : count.values()) {
                answer += c * (c - 1) / 2;
            }

            out.println(answer);
        }

        long f(long x) {
            return m.subtract(m.pow(x, 4), m.mult(x, k));
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
        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            ArrayList<Long> factorial = new ArrayList<>();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.add(1L);
            }

            public long normalize(long x) {
                x %= modulus();
                if (x < 0)
                    x += modulus();
                return x;
            }

            public long subtract(long a, long b) {
                return normalize(a - b);
            }

            public long mult(long a, long b) {
                return normalize(a * b);
            }

            public long pow(long x, int e) {
                if (e == 0)
                    return 1;
                if ((e & 1) > 0)
                    return mult(x, pow(x, e - 1));
                return pow(mult(x, x), e / 2);
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