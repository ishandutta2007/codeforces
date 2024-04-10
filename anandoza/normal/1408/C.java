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
        CDiscreteAcceleration solver = new CDiscreteAcceleration();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDiscreteAcceleration {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int l = in.nextInt();
            int[] a = in.readIntArray(n);

            double t = 0;
            double left = 1, right = 1;
            int i = 0, j = n - 1;
            double x = 0, y = l;
            while (x < y) {
                if (i > j) {
                    t += Math.abs(x - y) / (left + right);
                    break;
                }
                double t1 = Math.abs(a[i] - x) / left;
                double t2 = Math.abs(a[j] - y) / right;
                double d = Math.min(t1, t2);
                x += d * left;
                y -= d * right;
                t += d;

                if (t1 < t2) {
                    i++;
                    left++;
                } else {
                    j--;
                    right++;
                }
            }

            out.println(Util.formatDouble(t));
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
        }

        private Util() {
        }

    }
}