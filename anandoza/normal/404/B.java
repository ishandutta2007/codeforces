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
        BMarathon solver = new BMarathon();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMarathon {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            double a = in.nextDouble(), d = in.nextDouble();
            int n = in.nextInt();
            for (int i = 1; i <= n; i++) {
                double r = d * i;
                double s = r / a;
                long sides = (long) (s + 1e-10);
                double left = s - sides;

                double x = 0, y = 0;
                switch ((int) (sides % 4)) {
                    case 0:
                        x = left * a;
                        y = 0;
                        break;
                    case 1:
                        x = a;
                        y = left * a;
                        break;
                    case 2:
                        x = a * (1 - left);
                        y = a;
                        break;
                    case 3:
                        x = 0;
                        y = a * (1 - left);
                        break;
                }
                out.println(Util.formatDouble(x) + " " + Util.formatDouble(y));
            }
        }

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}