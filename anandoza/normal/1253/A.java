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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ASinglePush solver = new ASinglePush();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASinglePush {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] b = in.readIntArray(n);

            int[] d = new int[n];

            boolean answer = solve(a, b);

            out.println(answer ? "YES" : "NO");
        }

        private static boolean solve(int[] a, int[] b) {
            int n = a.length;
            int[] d = new int[n];

            int count = 0;
            int min = Integer.MAX_VALUE;
            int max = -1;
            int val = -1;
            for (int i = 0; i < n; i++) {
                d[i] = b[i] - a[i];
                if (d[i] == 0)
                    continue;

                if (d[i] < 0)
                    return false;

                count++;
                min = Math.min(min, i);
                max = Math.max(max, i);
                if (val == -1) {
                    val = d[i];
                }
                if (val != d[i])
                    return false;
            }

            if (count == 0)
                return true;

            return max - min + 1 == count;
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