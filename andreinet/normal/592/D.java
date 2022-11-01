import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        List<Integer>[] G;
        int[] hmax;
        long[] dp;
        long[] finald;
        boolean[] special;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            G = new List[n];
            for (int i = 0; i < n; ++i) {
                G[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                G[x].add(y);
                G[y].add(x);
            }
            special = new boolean[n];
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1;
                special[x] = true;
            }

            hmax = new int[n];
            dp = new long[n];
            dfs1(0, -1);
            finald = new long[n];
            dfs2(0, -1, 0, 0);

            int node = 0;
            for (int i = 1; i < n; ++i)
                if (finald[i] < finald[node])
                    node = i;

            out.println(node + 1);
            out.println(finald[node]);
        }

        private void dfs1(int node, int prev) {
            hmax[node] = special[node] ? 0 : -1;
            for (int to : G[node]) {
                if (to == prev) continue;
                dfs1(to, node);
                if (hmax[to] != -1) {
                    hmax[node] = Math.max(hmax[node], hmax[to] + 1);
                    dp[node] += dp[to] + 2 + hmax[to];
                }
            }
            dp[node] -= hmax[node];
        }

        private void dfs2(int node, int prev, long add, int hhmax) {
            finald[node] = dp[node] + hmax[node] +
                    add - Math.max(hhmax, hmax[node]);
            int chmax = -1, chmax2 = -1;
            if (special[node]) chmax = 0;
            for (int to : G[node]) {
                int ghmax = to == prev ? hhmax - 1 : hmax[to];
                if (ghmax < 0) continue;
                ghmax++;
                if (ghmax > chmax) {
                    chmax2 = chmax;
                    chmax = ghmax;
                } else if (ghmax > chmax2) {
                    chmax2 = ghmax;
                }
            }
            for (int to : G[node]) {
                if (to == prev) continue;
                long nadd = finald[node] + Math.max(hhmax, hmax[node]);
                int nhmax;
                if (hmax[to] != -1) {
                    nadd -= dp[to] + 2 + hmax[to];
                    nhmax = hmax[to] + 1 == chmax ? chmax2 : chmax;
                } else {
                    nhmax = chmax;
                }
                if (nhmax != -1) {
                    nhmax++;
                    nadd += 2;
                }
                dfs2(to, node, nadd, nhmax);
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