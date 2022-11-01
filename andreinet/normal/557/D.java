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
        int[] color;
        boolean hasCycle;
        int[] cntCol;
        long total;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt(), M = in.nextInt();

            G = new List[N];
            for (int i = 0; i < N; ++i)
                G[i] = new ArrayList<>();

            for (int i = 0; i < M; ++i) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1;
                G[x].add(y);
                G[y].add(x);
            }

            color = new int[N];
            hasCycle = false;
            total = 0;
            for (int i = 0; i < N; ++i) {
                if (color[i] == 0) {
                    cntCol = new int[2];
                    dfs(i, 1);
                }
            }

            if (hasCycle) {
                out.println("0 1");
                return;
            }

            boolean oneEdge = false, treeEdges = true;
            for (int i = 0; i < N; ++i) {
                if (G[i].size() > 0) treeEdges = false;
                if (G[i].size() > 1) oneEdge = true;
            }

            if (treeEdges) {
                long ans = (long) N * (N - 1) * (N - 2) / 6;
                out.println("3 " + ans);
            } else if (oneEdge) {
                out.println("1 " + total);
            } else {
                long ans = (long) M * (N - 2);
                out.println("2 " + ans);
            }
        }

        private void dfs(int node, int col) {
            color[node] = col;
            total += cntCol[col - 1];
            cntCol[col - 1]++;
            for (int p : G[node]) {
                if (color[p] == color[node]) {
                    hasCycle = true;
                } else if (color[p] == 0) {
                    dfs(p, 3 - col);
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