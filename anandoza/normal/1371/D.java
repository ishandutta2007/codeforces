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
        DGrid00100 solver = new DGrid00100();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGrid00100 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            int[][] grid = new int[n][n];

            for (int count = 0, i = 0, j = 0; count < k; count++, i++, j++) {
                if (i == n) {
                    i = 0;
                }
                if (j == n) {
                    j = 0;
                }

                if (grid[i][j] == 1)
                    i++;

                grid[i][j] = 1;
            }

            int answer = 0;

            int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    t += grid[i][j];
                }
                min = Math.min(min, t);
                max = Math.max(max, t);
            }
            answer += (min - max) * (min - max);

            min = Integer.MAX_VALUE;
            max = Integer.MIN_VALUE;
            for (int j = 0; j < n; j++) {
                int t = 0;
                for (int i = 0; i < n; i++) {
                    t += grid[i][j];
                }
                min = Math.min(min, t);
                max = Math.max(max, t);
            }
            answer += (min - max) * (min - max);

            out.println(answer);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(grid[i][j]);
                }
                out.println();
            }
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