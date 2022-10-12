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
        BDubiousCyrpto solver = new BDubiousCyrpto();
        solver.solve(1, in, out);
        out.close();
    }

    static class BDubiousCyrpto {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            long l = in.nextLong(), r = in.nextLong();
            long m = in.nextLong();

            for (long a = l; a <= r; a++) {
                {
                    long n = m / a;
                    long bMinusC = m - n * a;
                    if (n > 0 && bMinusC <= r - l) {
                        long c = l;
                        long b = bMinusC + c;
                        out.println(Util.join(a, b, c));
                        return;
                    }
                }
                {
                    long n = m / a + 1;
                    long cMinusB = -(m - n * a);
                    if (n > 0 && cMinusB <= r - l) {
                        long b = l;
                        long c = cMinusB + b;
                        out.println(Util.join(a, b, c));
                        return;
                    }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    static class Util {
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
}