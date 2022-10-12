import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        EVasyasFunction solver = new EVasyasFunction();
        solver.solve(1, in, out);
        out.close();
    }

    static class EVasyasFunction {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long a = in.nextLong(), b = in.nextLong();

            long answer = 0;
            while (b > 0) {
                long g = NumberTheory.gcd(a, b);
                a /= g;
                b /= g;
                if (a == 1) {
                    answer += b;
                    break;
                }
                List<Long> factors = new ArrayList<>();
                for (long i = 2; i * i <= a; i++) {
                    if (a % i == 0) {
                        factors.add(i);
                        factors.add(a / i);
                    }
                }
                factors.add(a);
                long next = 0;
                for (long f : factors) {
                    next = Math.max(next, (b - 1) / f * f);
                }
                answer += (b - next);
                b = next;
            }

            out.println(answer);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}