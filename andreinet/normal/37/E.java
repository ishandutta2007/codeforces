import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Collections;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        final int INF = 0x3f3f3f3f;
        String[] matrix;
        int[][] zoneIndex;
        int zones;
        int[] dx = new int[]{-1, 0, 1, 0};
        int[] dy = new int[]{0, 1, 0, -1};
        int blackNodes;
        List<Integer>[] graph;

        @SuppressWarnings("unchecked")
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            matrix = new String[n];
            for (int i = 0; i < n; ++i)
                matrix[i] = in.next();

            zoneIndex = new int[n][m];
            for (int[] p : zoneIndex) Arrays.fill(p, -1);
            zones = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (matrix[i].charAt(j) == 'B' && zoneIndex[i][j] == -1) {
                        dfs(i, j);
                        zones++;
                    }
                }
            }
            blackNodes = zones;
            if (zones <= 1) {
                out.println(zones);
                return;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (matrix[i].charAt(j) == 'W' && zoneIndex[i][j] == -1) {
                        dfs(i, j);
                        zones++;
                    }
                }
            }

            graph = new List[zones];
            for (int i = 0; i < zones; ++i)
                graph[i] = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    getEdges(i, j);
                }
            }
            for (int i = 0; i < zones; ++i) {
                Collections.sort(graph[i]);
                List<Integer> adj = new ArrayList<>();
                int prev = -1;
                for (int p : graph[i]) {
                    if (p != prev) {
                        adj.add(p);
                        prev = p;
                    }
                }
                graph[i] = adj;
            }

            Queue<Integer> q = new ArrayDeque<>();
            int ans = INF;
            for (int i = 0; i < zones; ++i) {
                int[] dist = new int[zones];
                dist[i] = 1;
                q.add(i);
                int mdist = 1;
                while (!q.isEmpty()) {
                    int node = q.poll();
                    mdist = dist[node];
                    for (int p : graph[node]) {
                        if (dist[p] == 0) {
                            dist[p] = dist[node] + 1;
                            q.add(p);
                        }
                    }
                }
                if (i >= blackNodes) mdist &= ~1;
                else mdist -= (mdist & 1) ^ 1;
                ans = Math.min(ans, mdist);
            }

            out.println(ans);
        }

        private void dfs(int x, int y) {
            zoneIndex[x][y] = zones;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (0 <= nx && nx < matrix.length &&
                        0 <= ny && ny < matrix[0].length() &&
                        matrix[x].charAt(y) == matrix[nx].charAt(ny) &&
                        zoneIndex[nx][ny] == -1) {
                    dfs(nx, ny);
                }
            }
        }

        private void getEdges(int x, int y) {
            int node = zoneIndex[x][y];
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!(0 <= nx && nx < matrix.length &&
                        0 <= ny && ny < matrix[0].length())) continue;
                int p = zoneIndex[nx][ny];
                if (p != node) {
                    graph[node].add(p);
                }
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