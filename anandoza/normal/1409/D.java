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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DDecreaseTheSumOfDigits solver = new DDecreaseTheSumOfDigits();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDecreaseTheSumOfDigits {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            long n = in.nextLong();
            int s = in.nextInt();

            long answer = Long.MAX_VALUE;
            for (int zeros = 0; zeros <= 18; zeros++) {
                long tens = 1;
                for (int i = 0; i < zeros; i++) {
                    tens *= 10;
                }
                long nextMultipleOfTens = ((n + tens - 1) / tens) * tens;
                if (sum(nextMultipleOfTens) > s)
                    continue;
                answer = Math.min(answer, nextMultipleOfTens - n);
            }
            out.println(answer);
        }

        private int sum(long x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
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