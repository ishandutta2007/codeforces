import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.function.LongUnaryOperator;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        CYetAnotherCountingProblem solver = new CYetAnotherCountingProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class CYetAnotherCountingProblem {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            long a = in.nextLong(), b = in.nextLong();

            int q = in.nextInt();

            long lcm = NumberTheory.lcm(a, b);
            long max = Math.max(a, b);

            LongUnaryOperator same = n -> {
                long ans = 0;
                ans += (n / lcm) * max;
                n %= lcm;
                ans += Math.min(n, max);
                return ans;
            };

            for (int i = 0; i < q; i++) {
                long l = in.nextLong(), r = in.nextLong() + 1;
                long answer = same.applyAsLong(r) - same.applyAsLong(l);
                answer = (r - l) - answer;
                out.print(answer + " ");
            }
            out.println();
        }

    }

    static class NumberTheory {
        public static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            long c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
        }

        public static long lcm(long a, long b) {
            return (a / gcd(a, b)) * b;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}