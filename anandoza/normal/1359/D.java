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
        DYetAnotherYetAnotherTask solver = new DYetAnotherYetAnotherTask();
        solver.solve(1, in, out);
        out.close();
    }

    static class DYetAnotherYetAnotherTask {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            final int MAX = Util.max(a), MIN = Util.min(a);

            int answer = 0;

            for (int cur = Math.max(0, MIN); cur <= MAX; cur++) {
                int sum = 0;
                for (int x : a) {
                    if (x > cur) {
                        sum = 0;
                        continue;
                    }
                    sum += x;
                    answer = Math.max(answer, sum - cur);
                    sum = Math.max(sum, 0);
                }
            }

            out.println(answer);
        }

    }

    static class Util {
        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}