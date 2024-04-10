import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Queue;
import java.util.ArrayDeque;
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
        final int[] dx = new int[]{0, 1, 0, -1};
        final int[] dy = new int[]{1, 0, -1, 0};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            String[] map = new String[n];
            for (int i = 0; i < n; ++i) map[i] = in.next();

            int[][][] dist = new int[3][n][m];
            for (int i = 0; i < 3; ++i)
                getDistances(map, dist[i], i);

            int[][] cityDist = new int[3][3];
            for (int[] p : cityDist) Arrays.fill(p, -1);
            for (int k = 0; k < 3; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        char c = map[i].charAt(j);
                        if ('1' <= c && c <= '3') {
                            int p = c - '1';
                            if (cityDist[k][p] == -1 ||
                                    cityDist[k][p] > dist[k][i][j])
                                cityDist[k][p] = dist[k][i][j];
                        }
                    }
                }
            }

            for (int[] l : cityDist) {
                for (int p : l) {
                    if (p == -1) {
                        out.println(-1);
                        return;
                    }
                }
            }

            int ans;
            ans = cityDist[0][1] + cityDist[0][2] - 2;
            ans = Math.min(ans, cityDist[1][0] + cityDist[1][2] - 2);
            ans = Math.min(ans, cityDist[2][0] + cityDist[2][1] - 2);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int d0 = dist[0][i][j];
                    int d1 = dist[1][i][j];
                    int d2 = dist[2][i][j];

                    if (d0 == -1 || d1 == -1 || d2 == -1) continue;
                    if (ans > d0 + d1 + d2 - 2)
                        ans = d0 + d1 + d2 - 2;
                }
            }

            out.println(ans);

        }

        private void getDistances(String[] map, int[][] dist, int start) {
            for (int[] p : dist) Arrays.fill(p, -1);
            int n = map.length, m = map[0].length();
            Queue<Cell> q = new ArrayDeque<>();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (map[i].charAt(j) - '1' == start) {
                        q.add(new Cell(i, j));
                        dist[i][j] = 0;
                    }
                }
            }
            while (!q.isEmpty()) {
                Cell node = q.remove();
                for (int k = 0; k < 4; ++k) {
                    int nx = node.x + dx[k], ny = node.y + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (map[nx].charAt(ny) != '#' && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[node.x][node.y] + 1;
                        q.add(new Cell(nx, ny));
                    }
                }
            }
        }

        private class Cell {
            public int x;
            public int y;

            Cell(int x, int y) {
                this.x = x;
                this.y = y;
            }

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