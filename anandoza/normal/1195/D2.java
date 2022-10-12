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
        D2SubmarineInTheRybinskSeaHardEdition solver = new D2SubmarineInTheRybinskSeaHardEdition();
        solver.solve(1, in, out);
        out.close();
    }

    static class D2SubmarineInTheRybinskSeaHardEdition {
        NumberTheory.ModM m = new NumberTheory.ModM(998244353);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();

            int MAX_DIGITS = 13;
            int[] count = new int[MAX_DIGITS + 1];
            for (int x : a) {
                count[countDigits(x)]++;
            }

            long answer = 0;

            for (int len = 1; len <= MAX_DIGITS; len++) {
                for (int x : a) {
                    long hundreds = 1;
                    int i = 0;
                    while (x > 0) {
                        long digit = x % 10;
                        long contrib = m.mult(count[len], m.mult(digit, hundreds));
                        answer = m.add(answer, contrib);
                        x /= 10;
                        if (i < len)
                            hundreds = m.mult(hundreds, 100);
                        else
                            hundreds = m.mult(hundreds, 10);
                        i++;
                    }
                }
            }

            for (int len = 1; len <= MAX_DIGITS; len++) {
                for (int x : a) {
                    long hundreds = 10;
                    int i = 1;
                    while (x > 0) {
                        long digit = x % 10;
                        long contrib = m.mult(count[len], m.mult(digit, hundreds));
                        answer = m.add(answer, contrib);
                        x /= 10;
                        if (i < len)
                            hundreds = m.mult(hundreds, 100);
                        else
                            hundreds = m.mult(hundreds, 10);
                        i++;
                    }
                }
            }

            out.println(answer);
        }

        static int countDigits(long x) {
            int result = 0;
            while (x > 0) {
                result++;
                x /= 10;
            }
            return result;
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

            public long add(long a, long b) {
                return normalize(a + b);
            }

            public long mult(long a, long b) {
                return normalize(a * b);
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