import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.function.BooleanSupplier;

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
        ABoboniuLikesToColorBalls solver = new ABoboniuLikesToColorBalls();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABoboniuLikesToColorBalls {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int[] a = in.readIntArray(4);

            BooleanSupplier good = () -> {
                int odd = 0;
                for (int x : a) {
                    if (x % 2 == 1)
                        odd++;
                }
                return odd <= 1 && Util.min(a) >= 0;
            };

            boolean answer = good.getAsBoolean();
            for (int i = 0; i < 3; i++) {
                a[i]--;
            }
            a[3] += 3;
            answer |= good.getAsBoolean();

            out.println(answer ? "Yes" : "No");
        }

    }

    static class Util {
        public static int min(int... x) {
            int min = Integer.MAX_VALUE;
            for (int i : x) {
                min = Math.min(i, min);
            }
            return min;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}