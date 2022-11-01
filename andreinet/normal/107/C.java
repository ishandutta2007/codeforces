import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStream;

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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        long[][] dp;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long y = in.nextLong() - 2000;
            int m = in.nextInt();

            final String noSolution = "The times have changed";

            boolean[][] graph = new boolean[n][n];
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1, t = in.nextInt() - 1;
                graph[x][t] = true;
            }

            boolean[][] accesible = new boolean[n][n];
            for (int i = 0; i < n; ++i) {
                dfs(graph, accesible[i], i);
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && accesible[i][j] && accesible[j][i]) {
                        out.println(noSolution);
                        return;
                    }
                }
            }

            int[] g = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (accesible[i][j])
                        g[i] |= 1 << j;
                }
            }

            dp = new long[n + 1][1 << n];
            int[] pos = new int[n];
            Arrays.fill(pos, -1);

            if (count(pos, g) < y) {
                out.println(noSolution);
                return;
            }

            int[] fans = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (pos[j] != -1) continue;

                    pos[j] = i;
                    long x = count(pos, g);
                    if (x < y) {
                        y -= x;
                    } else {
                        fans[i] = j;
                        break;
                    }
                    pos[j] = -1;
                }
            }

            for (int i = 0; i < n; ++i)
                out.print((fans[i] + 1) + " ");
            out.println();
        }

        private void dfs(boolean[][] graph, boolean[] accesible, int node) {
            accesible[node] = true;
            for (int i = 0; i < graph.length; ++i) {
                if (graph[node][i] && !accesible[i]) {
                    dfs(graph, accesible, i);
                }
            }
        }

        private long count(int[] pos, int[] g) {
            int n = pos.length;
            int used = 0;
            for (int i = 0; i < n; ++i) {
                if (pos[i] != -1)
                    used |= 1 << pos[i];
            }
            for (long[] p : dp) {
                Arrays.fill(p, 0);
            }
            dp[0][0] = 1;
            for (int i = 0; i < n; ++i) {
                for (int conf = 0; conf < 1 << n; ++conf) {
                    if (dp[i][conf] == 0) continue;
                    for (int j = 0; j < n; ++j) {
                        if ((conf & g[j]) != 0) continue;
                        if ((pos[i] == -1 && (used & (1 << j)) == 0) ||
                                pos[i] == j) {
                            dp[i + 1][conf | (1 << j)] += dp[i][conf];
                        }
                    }
                }
            }
            return dp[n][(1 << n) - 1];
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}