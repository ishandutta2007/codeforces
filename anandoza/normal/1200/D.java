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
        DWhiteLines solver = new DWhiteLines();
        solver.solve(1, in, out);
        out.close();
    }

    static class DWhiteLines {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            int[][] black = new int[n][n];
            for (int i = 0; i < n; i++) {
                char[] row = in.next().toCharArray();
                for (int j = 0; j < n; j++) {
                    black[i][j] = row[j] == 'B' ? 1 : 0;
                }
            }

            int[][] scores = compute(black, k);

            int[][] blackTransposed = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    blackTransposed[i][j] = black[j][i];
                }
            }

            int[][] scoresTransposed = compute(blackTransposed, k);

            int answer = 0;
            int s = n - (k - 1);
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < s; j++) {
                    answer = Math.max(answer, scores[i][j] + scoresTransposed[j][i]);
                }
            }

            boolean[] blackRows = new boolean[n];
            boolean[] blackCols = new boolean[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (black[i][j] > 0) {
                        blackRows[i] = true;
                        blackCols[j] = true;
                    }
                }
            }

            for (boolean b : blackRows) {
                if (!b)
                    answer++;
            }
            for (boolean b : blackCols) {
                if (!b)
                    answer++;
            }

            out.println(answer);
        }

        private int[][] compute(int[][] black, int k) {
            int n = black.length;
            int s = n - (k - 1);

            int[][] horiz = new int[n][s];
            for (int i = 0; i < n; i++) {
                int left = Integer.MAX_VALUE;
                int right = Integer.MIN_VALUE;
                for (int j = 0; j < n; j++) {
                    if (black[i][j] > 0) {
                        left = Math.min(left, j);
                        right = Math.max(right, j);
                    }
                }

                for (int j = 0; j < s; j++) {
                    if (j <= left && right <= j + (k - 1) && left != Integer.MAX_VALUE) {
                        horiz[i][j] = 1;
                    }
                }
            }

            int[][] score = new int[s][s];
            for (int j = 0; j < s; j++) {
                int[] prefix = new int[n + 1];
                for (int i = 0; i < n; i++) {
                    prefix[i + 1] = prefix[i] + horiz[i][j];
                }

                for (int i = 0; i < s; i++) {
                    score[i][j] = prefix[i + k] - prefix[i];
                }
            }

            return score;
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