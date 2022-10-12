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
        AOddSelection solver = new AOddSelection();
        solver.solve(1, in, out);
        out.close();
    }

    static class AOddSelection {
        private static final String NO = "No";
        private static final String YES = "Yes";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), x = in.nextInt();
            int[] a = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                a[i] %= 2;
            }

            boolean[][] odd = new boolean[n + 1][n + 1];
            boolean[][] even = new boolean[n + 1][n + 1];

            even[0][0] = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    odd[i + 1][j] |= odd[i][j];
                    even[i + 1][j] |= even[i][j];
                    if (a[i] % 2 == 0) {
                        odd[i + 1][j + 1] |= odd[i][j];
                        even[i + 1][j + 1] |= even[i][j];
                    } else {
                        even[i + 1][j + 1] |= odd[i][j];
                        odd[i + 1][j + 1] |= even[i][j];
                    }
                }
            }

            out.println(odd[n][x] ? YES : NO);
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