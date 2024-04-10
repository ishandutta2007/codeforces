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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        GKThDivisor solver = new GKThDivisor();
        solver.solve(1, in, out);
        out.close();
    }

    static class GKThDivisor {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long k = in.nextLong();

            long count = 0;
            long i;
            for (i = 1; i * i < n; i++) {
                if (n % i != 0)
                    continue;
                count++;

                if (count == k) {
                    out.println(i);
                    return;
                }
            }
            if (i * i == n) {
                count++;
                if (count == k) {
                    out.println(i);
                    return;
                }
            }
            i--;

            for (; i >= 1; i--) {
                if (n % i != 0)
                    continue;
                count++;

                if (count == k) {
                    out.println(n / i);
                    return;
                }
            }

            out.println(-1);
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
}