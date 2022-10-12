import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        DBlockTower solver = new DBlockTower();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBlockTower {
        List<String> answer = new ArrayList<>();
        int n;
        int m;
        boolean[][] blocked;
        int[][] color;
        private static final int BLUE = 1;
        private static final int RED = 2;
        int[][] offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            blocked = new boolean[n][m];
            int count = 0;
            for (int i = 0; i < n; i++) {
                char[] row = in.next().toCharArray();
                for (int j = 0; j < m; j++) {
                    blocked[i][j] = row[j] == '#';
                    if (!blocked[i][j])
                        count++;
                }
            }

            color = new int[n][m];

            if (count == n * m) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        blue(i, j);
                    }
                }
                for (int i = n - 1; i >= 0; i--) {
                    for (int j = m - 1; j >= 1; j--) {
                        destroy(i, j);
                        red(i, j);
                    }
                }
                for (int i = n - 1; i >= 1; i--) {
                    destroy(i, 0);
                    red(i, 0);
                }

                out.println(answer.size());
                for (String s : answer) {
                    out.println(s);
                }
                return;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (color[i][j] > 0 || blocked[i][j])
                        continue;
                    dfs(i, j, true);
                }
            }

            out.println(answer.size());
            for (String s : answer) {
                out.println(s);
            }
        }

        private void red(int i, int j) {
            color[i][j] = RED;
//        answer.add("R " + Util.join(i + 1, j + 1));
            answer.add("R " + (i + 1) + " " + (j + 1));
        }

        private void blue(int i, int j) {
            color[i][j] = BLUE;
            answer.add("B " + (i + 1) + " " + (j + 1));
        }

        private void destroy(int i, int j) {
            answer.add("D " + (i + 1) + " " + (j + 1));
//        answer.add("D " + Util.join(i + 1, j + 1));
        }

        private void dfs(int i, int j, boolean first) {
            blue(i, j);

            for (int[] o : offsets) {
                int x = i + o[0], y = j + o[1];
                if (x >= n || x < 0 || y >= m || y < 0 || color[x][y] > 0 || blocked[x][y])
                    continue;
                dfs(x, y, false);
            }

            if (!first) {
                destroy(i, j);
                red(i, j);
            }
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

    }
}