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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        final int INF = 0x3f3f3f3f;
        int[] edg1h;
        int[] edg1t;
        int[] edg2h;
        int[] edg2t;
        int[][] dp;
        boolean[][] enter;
        boolean[][] exit;
        int cpos;
        boolean hasCycle = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt(), t = in.nextInt(), R = in.nextInt();

            int n = in.nextInt();
            edg1h = new int[n];
            edg1t = new int[n];
            for (int i = 0; i < n; ++i) {
                edg1h[i] = in.nextInt();
                edg1t[i] = in.nextInt();
            }

            int m = in.nextInt();
            edg2h = new int[m];
            edg2t = new int[m];
            for (int i = 0; i < m; ++i) {
                edg2h[i] = in.nextInt();
                edg2t[i] = in.nextInt();
            }

            dp = new int[R + 1][R + 1];
            bfs(h, t, R);

            if (dp[0][0] != INF) {
                out.println("Ivan");
                out.println(dp[0][0]);
                return;
            }

            int ans = checkCycles(h, t, R);
            if (ans == -1) {
                out.println("Draw");
            } else {
                out.println("Zmey\n" + ans);
            }
        }

        private int dfs(int ih, int it, int R) {
            if (exit[ih][it]) {
                return dp[ih][it];
            }
            enter[ih][it] = true;

            int cost = 1;
            for (int i = 1; i <= edg1h.length && i <= ih && !hasCycle; ++i) {
                int nh = ih - i + edg1h[i - 1];
                int nt = it + edg1t[i - 1];
                if (nh + nt > R) continue;
                if (enter[nh][nt] && !exit[nh][nt]) {
                    hasCycle = true;
                    return -1;
                }
                cost = Math.max(cost, dfs(nh, nt, R) + 1);
            }
            for (int i = 1; i <= edg2h.length && i <= it && !hasCycle; ++i) {
                int nh = ih + edg2h[i - 1];
                int nt = it - i + edg2t[i - 1];
                if (nh + nt > R) continue;
                if (enter[nh][nt] && !exit[nh][nt]) {
                    hasCycle = true;
                    return -1;
                }
                cost = Math.max(cost, dfs(nh, nt, R) + 1);
            }
            exit[ih][it] = true;

            return hasCycle ? -1 : (dp[ih][it] = cost);
        }

        private int checkCycles(int h, int t, int R) {
            enter = new boolean[R + 1][R + 1];
            exit = new boolean[R + 1][R + 1];
            cpos = 0;
            return dfs(h, t, R);
        }

        private void bfs(int h, int t, int R) {
            for (int[] p : dp) {
                Arrays.fill(p, INF);
            }
            dp[h][t] = 0;
            Queue<Node> q = new ArrayDeque<>();
            q.add(new Node(h, t, 0));

            while (!q.isEmpty()) {
                Node node = q.poll();

                for (int i = 1; i <= edg1h.length && i <= node.h; ++i) {
                    int nh = node.h - i + edg1h[i - 1];
                    int nt = node.t + edg1t[i - 1];
                    if (nh + nt > R) continue;
                    if (dp[nh][nt] > dp[node.h][node.t] + 1) {
                        dp[nh][nt] = dp[node.h][node.t] + 1;
                        q.add(new Node(nh, nt, dp[nh][nt]));
                    }
                }
                for (int i = 1; i <= edg2h.length && i <= node.t; ++i) {
                    int nh = node.h + edg2h[i - 1];
                    int nt = node.t - i + edg2t[i - 1];
                    if (nh + nt > R) continue;
                    if (dp[nh][nt] > dp[node.h][node.t] + 1) {
                        dp[nh][nt] = dp[node.h][node.t] + 1;
                        q.add(new Node(nh, nt, dp[nh][nt]));
                    }
                }
            }
        }

        private class Node {
            int h;
            int t;

            Node(int h, int t, int dist) {
                this.h = h;
                this.t = t;
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