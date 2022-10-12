import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        JDivisibility solver = new JDivisibility();
        solver.solve(1, in, out);
        out.close();
    }

    static class JDivisibility {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long lcm = 1;
            for (int i = 2; i <= 10; i++) {
                lcm = NumberTheory.lcm(lcm, i);
            }
            out.println(n / lcm);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    static class NumberTheory {
        public static long gcd(long a, long b) {
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
}