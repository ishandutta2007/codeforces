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
        KIndivisibility solver = new KIndivisibility();
        solver.solve(1, in, out);
        out.close();
    }

    static class KIndivisibility {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long lcm = 1;
            for (int i = 2; i <= 10; i++) {
                lcm = NumberTheory.lcm(lcm, i);
            }
            long tot = 0;
            for (int i = 0; i < lcm; i++) {
                if (NumberTheory.gcd(i, lcm) == 1)
                    tot++;
            }
            long answer = n / lcm;
            answer *= tot;
            n %= lcm;
            for (int i = 0; i <= n; i++) {
                if (NumberTheory.gcd(i, lcm) == 1)
                    answer++;
            }

            out.println(answer);
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