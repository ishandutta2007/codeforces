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
        EOmkarAndDuck solver = new EOmkarAndDuck();
        solver.solve(1, in, out);
        out.close();
    }

    static class EOmkarAndDuck {
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.out = out;
            int n = in.nextInt();
            long[][] a = new long[n][n];
            for (int d = 1; d < 2 * n; d++) {
                long incr = 1L << d - 1;
                for (int i = 0; i <= d; i++) {
                    int j = d - i;
                    if (j >= n || i >= n)
                        continue;
                    a[i][j] = i % 2 == 0 ? 0 : incr;
                }
            }
            for (long[] row : a) {
                out.println(Util.join(row));
            }
            out.flush();

            int q = in.nextInt();
            for (int unused = 0; unused < q; unused++) {
                long k = in.nextLong();

                solve(a, k);
                out.flush();
            }
        }

        private void solve(long[][] a, long k) {
            final int n = a.length;

            int i = 0, j = 0; // starting location
            while (i < n - 1 || j < n - 1) {
                print(i, j);
                if (i % 2 == k % 2) {
                    j++;
                } else {
                    i++;
                }
                k /= 2;
            }
            print(i, j);
        }

        private void print(int i, int j) {
            out.println(Util.join(i + 1, j + 1));
            out.flush();
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        private Util() {
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