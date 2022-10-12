import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        AKAmazingNumbers solver = new AKAmazingNumbers();
        solver.solve(1, in, out);
        out.close();
    }

    static class AKAmazingNumbers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                a[i]--;
            }

            int[] last = new int[n];
            int[] max = new int[n];
            Arrays.fill(max, Integer.MIN_VALUE);
            Arrays.fill(last, -1);
            for (int i = 0; i < n; i++) {
                int x = a[i];
                int dist = i - last[x];
                max[x] = Math.max(max[x], dist);
                last[x] = i;
            }
            for (int x = 0; x < n; x++) {
                int dist = n - last[x];
                max[x] = Math.max(max[x], dist);
            }
            int[] num = new int[n];
            Arrays.fill(num, Integer.MAX_VALUE);
            for (int x = 0; x < n; x++) {
                if (max[x] <= n)
                    num[max[x] - 1] = Math.min(num[max[x] - 1], x);
            }
            for (int i = 1; i < n; i++) {
                num[i] = Math.min(num[i], num[i - 1]);
            }
            for (int i = 0; i < n; i++) {
                if (num[i] == Integer.MAX_VALUE) {
                    num[i] = -1;
                } else {
                    num[i]++;
                }
            }
            out.println(Util.join(num));
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

        private Util() {
        }

    }
}