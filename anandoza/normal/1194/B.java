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
        BYetAnotherCrossesProblem solver = new BYetAnotherCrossesProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class BYetAnotherCrossesProblem {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++)
                solve(in, out);
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[][] grid = new int[n][m];
            for (int i = 0; i < n; i++) {
                char[] c = in.next().toCharArray();
                for (int j = 0; j < m; j++) {
                    grid[i][j] = (c[j] == '*') ? 1 : 0;
                }
            }

            int[] r = new int[n];
            int[] c = new int[m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    r[i] += grid[i][j];
                }
            }
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    c[j] += grid[i][j];
                }
            }

            int answer = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int score = (n + m - 1) - (r[i] + c[j] - grid[i][j]);
                    answer = Math.min(answer, score);
                }
            }

            out.println(answer);
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