import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        EHyakugokuAndLadders solver = new EHyakugokuAndLadders();
        solver.solve(1, in, out);
        out.close();
    }

    static class EHyakugokuAndLadders {
        static final int size = 10;
        static final int n = 100;
        static final int d = 6;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] ladder = new int[n];
            Arrays.fill(ladder, -1);
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int realIndex = map(i);
                if (x > 0) {
                    int dest = map(kUp(i, x));
                    ladder[realIndex] = dest;
                }
            }

            double[] exp = new double[n];
            Arrays.fill(exp, Double.POSITIVE_INFINITY);
            exp[n - 1] = 0;

            for (int cur = n - 2; cur >= 0; cur--) {
                double val = 0;

                int fail = 0;
                for (int roll = 1; roll <= d; roll++) {
                    int next = cur + roll;
                    if (next >= n) {
                        fail++;
                        continue;
                    }
                    double choice = exp[next];
                    if (ladder[next] >= 0) {
                        choice = Math.min(choice, exp[ladder[next]]);
                    }
                    val += choice;
                    val++;
                }

                val /= (d - fail);

                val += ((double) fail) / (6 - fail);

                exp[cur] = val;
            }

            out.println(Util.formatDouble(exp[0]));
        }

        private static int map(int i) {
            int row = i / size;
            int col = i % size;
            if (row % 2 == 1) {
                col = size - 1 - col;
            }
            int val = row * size + col;

            return size * size - 1 - val;
        }

        private static int kUp(int i, int k) {
            int row = i / size;
            int col = i % size;
            row -= k;
            return row * size + col;
        }

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}