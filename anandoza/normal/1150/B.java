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
        BTilingChallenge solver = new BTilingChallenge();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTilingChallenge {
        int[][] offsets = {{0, 0}, {1, 0}, {1, -1}, {1, 1}, {2, 0}};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            boolean[][] board = new boolean[n][n];

            for (int i = 0; i < n; i++) {
                String line = in.next();
                for (int j = 0; j < n; j++) {
                    board[i][j] = line.charAt(j) == '#';
                }
            }

            if (isPossible(board, n)) {
                out.println("YES");
            } else {
                out.println("NO");
            }

        }

        private boolean isPossible(boolean[][] board, int n) {

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j]) continue;

                    for (int[] offset : offsets) {
                        int i2 = i + offset[0], j2 = j + offset[1];
                        if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= n || board[i2][j2]) {
                            return false;
                        }

                        board[i2][j2] = true;
                    }
                }
            }

            return true;
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