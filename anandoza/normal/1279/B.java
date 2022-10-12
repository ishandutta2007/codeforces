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
        BVerseForSanta solver = new BVerseForSanta();
        solver.solve(1, in, out);
        out.close();
    }

    static class BVerseForSanta {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long s = in.nextInt();
            long[] a = in.readLongArray(n);
            long[] sum = new long[n + 1];
            long[] max = new long[n + 1];
            int[] maxInd = new int[n + 1];
            for (int i = 0; i < n; i++) {
                sum[i + 1] = sum[i] + a[i];
            }
            for (int i = 0; i < n; i++) {
                if (a[i] > max[i]) {
                    max[i + 1] = a[i];
                    maxInd[i + 1] = i;
                } else {
                    max[i + 1] = max[i];
                    maxInd[i + 1] = maxInd[i];
                }
            }

            int answer = -1;
            int opt = 0;
            for (int i = 0; i <= n; i++) {
                if (sum[i] - max[i] <= s) {
                    if (i - 1 > opt) {
                        answer = maxInd[i];
                        opt = i - 1;
                    }
                }
                if (sum[i] <= s) {
                    if (i >= opt) {
                        answer = -1;
                        opt = i;
                    }
                }
            }
            out.println(answer + 1);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}