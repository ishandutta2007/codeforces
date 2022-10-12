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
        ERectangles solver = new ERectangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class ERectangles {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[][] grid = new int[n][];
            for (int i = 0; i < n; i++) {
                grid[i] = in.readIntArray(m);
            }

            long answer = n * m;

            answer += calc(grid);
            grid = transpose(grid);
            answer += calc(grid);

            out.println(answer);
        }

        private long calc(int[][] grid) {
            long r = 0;

            for (int[] row : grid) {
                int[] s = new int[2];
                for (int x : row)
                    s[x]++;

                for (int x : s) {
                    r += 1L << x;
                    r--;
                    r -= x;
                }
            }

            return r;
        }

        private int[][] transpose(int[][] grid) {
            final int n = grid.length, m = grid[0].length;
            int[][] r = new int[m][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    r[j][i] = grid[i][j];
                }
            }
            return r;
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