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
        CYetAnotherArrayRestoration solver = new CYetAnotherArrayRestoration();
        solver.solve(1, in, out);
        out.close();
    }

    static class CYetAnotherArrayRestoration {
        private static final int K = 51;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int x = in.nextInt(), y = in.nextInt();

            int answer = Integer.MAX_VALUE;
            for (int d = 1; d <= K; d++) {
                if ((y - x) % d != 0)
                    continue;

                int first = x % d;
                if (first == 0)
                    first = d;
                int last = first + (n - 1) * d;
                while (last < y) {
                    first += d;
                    last += d;
                }
                if (first > x)
                    continue;

                answer = Math.min(answer, last);
            }

            for (int d = 1; d <= K; d++) {
                if ((y - x) % d != 0)
                    continue;

                int first = x % d;
                if (first == 0)
                    first = d;
                int last = first + (n - 1) * d;
                while (last < y) {
                    first += d;
                    last += d;
                }
                if (first > x)
                    continue;

                if (last == answer) {
                    for (int i = first; i <= last; i += d) {
                        out.print(i + " ");
                    }
                    out.println();
                    return;
                }
            }
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

    }
}