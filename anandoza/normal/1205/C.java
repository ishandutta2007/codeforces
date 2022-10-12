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
        CPalindromicPaths solver = new CPalindromicPaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPalindromicPaths {
        InputReader in;
        PrintWriter out;
        private int[][] offsets = {
                {-1, -1}, {-2, 0}, {0, -2}
        };
        int queries = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(); // n is ODD
            this.in = in;
            this.out = out;

            int[][] grid = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = -1;
                }
            }
            grid[0][0] = 1;
            grid[n - 1][n - 1] = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != -1) {
                        continue;
                    }
                    if ((i + j) % 2 != 0) {
                        continue;
                    }

                    for (int[] off : offsets) {
                        int a = i + off[0];
                        int b = j + off[1];
                        if (a >= 0 && b >= 0) {
                            boolean q = ask(a, b, i, j);
                            int xor = q ? 0 : 1;
                            grid[i][j] = grid[a][b] ^ xor;
                            break;
                        }
                    }
                }
            }

            grid[0][1] = 0; // ASSUMING
            {
                int xor = ask(0, 1, 2, 1) ? 0 : 1;
                grid[2][1] = grid[0][1] ^ xor;
                xor = ask(1, 0, 2, 1) ? 0 : 1;
                grid[1][0] = grid[2][1] ^ xor;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != -1) {
                        continue;
                    }
                    if ((i + j) % 2 == 0) {
                        continue;
                    }

                    for (int[] off : offsets) {
                        int a = i + off[0];
                        int b = j + off[1];
                        if (a >= 0 && b >= 0) {
                            boolean q = ask(a, b, i, j);
                            int xor = q ? 0 : 1;
                            grid[i][j] = grid[a][b] ^ xor;
                            break;
                        }
                    }
                }
            }

            for (int start = 0; start < n; start += 2) {
                if (grid[start][start] == 1 && grid[start + 2][start + 2] == 0) {
                    int[][] subgrid = new int[3][3];
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            subgrid[i][j] = grid[start + i][start + j];
                        }
                    }

                    boolean A = isPalindrome(subgrid, 0, 0, 1, 2);
                    boolean B = isPalindrome(subgrid, 0, 1, 2, 2);

                    boolean A2 = ask(start, start, start + 1, start + 2);
                    boolean B2 = ask(start, start + 1, start + 2, start + 2);

                    int xor = A == A2 && B == B2 ? 0 : 1;

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if ((i + j) % 2 == 0)
                                continue;

                            grid[i][j] ^= xor;
                        }
                    }

                    break;
                }
            }

            out.println("!");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(grid[i][j]);
                }
                out.println();
            }
            out.flush();
        }

        boolean ask(int x1, int y1, int x2, int y2) {
            queries++;
            out.format("? %d %d %d %d%n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
            out.flush();
            int response = in.nextInt();
            return response == 1;
        }

        static boolean isPalindrome(int[][] grid, int x1, int y1, int x2, int y2) {
            if (grid[x1][y1] != grid[x2][y2])
                return false;

            if (x2 - x1 == 1) {
                return (grid[x1][y1 + 1] == grid[x1][y1 + 2] || grid[x1][y1 + 1] == grid[x1 + 1][y1 + 1] || grid[x1 + 1][y1] == grid[x1 + 1][y1 + 1]);
            } else {
                return (grid[x1 + 1][y1] == grid[x1 + 2][y1] || grid[x1 + 1][y1] == grid[x1 + 1][y1 + 1] || grid[x1][y1 + 1] == grid[x1 + 1][y1 + 1]);
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