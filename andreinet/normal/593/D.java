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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[] firstEdge;
        int[] nextEdge;
        int[] edgeTo;
        long[] edgeCost;
        int[] edgeSon;
        int countEdges;
        long[] nodeCost;
        int[] level;
        int[] father;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            firstEdge = new int[n];
            Arrays.fill(firstEdge, -1);

            nextEdge = new int[2 * n - 2];
            edgeTo = new int[2 * n - 2];
            edgeCost = new long[2 * n - 2];
            countEdges = 0;

            for (int i = 1; i < n; ++i) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1;
                long cost = in.nextLong();

                addEdge(x, y, cost);
                addEdge(y, x, cost);
            }

            nodeCost = new long[n];
            level = new int[n];
            father = new int[n];
            edgeSon = new int[n - 1];
            dfs(0, -1, 1);

            DSU sets = new DSU(level);
            for (int i = 0; i < n; ++i) {
                if (nodeCost[i] == 1) {
                    for (int p = firstEdge[i]; p != -1; p = nextEdge[p]) {
                        int to = edgeTo[p];
                        if (nodeCost[to] == 1)
                            sets.unite(i, to);
                    }
                }
            }

            while (q-- > 0) {
                int type = in.nextInt();
                if (type == 1) {
                    int x = in.nextInt() - 1;
                    int y = in.nextInt() - 1;
                    long v = in.nextLong();

                    if (nodeCost[x] == 1) x = father[sets.find(x)];
                    if (nodeCost[y] == 1) y = father[sets.find(y)];

                    while (x != y && v > 0) {
                        if (level[x] < level[y]) {
                            int aux = x;
                            x = y;
                            y = aux;
                        }
                        v /= nodeCost[x];
                        x = father[x];
                        if (nodeCost[x] == 1) x = father[sets.find(x)];
                    }

                    out.println(v);
                } else {
                    int x = edgeSon[in.nextInt() - 1];
                    long v = in.nextLong();
                    nodeCost[x] = v;
                    if (nodeCost[x] == 1) {
                        for (int p = firstEdge[x]; p != -1; p = nextEdge[p]) {
                            int to = edgeTo[p];
                            if (nodeCost[to] == 1)
                                sets.unite(x, to);
                        }
                    }
                }
            }
        }

        private void addEdge(int from, int to, long cost) {
            edgeTo[countEdges] = to;
            edgeCost[countEdges] = cost;
            nextEdge[countEdges] = firstEdge[from];
            firstEdge[from] = countEdges++;
        }

        private void dfs(int node, int prev, int level) {
            father[node] = prev;
            this.level[node] = level;

            for (int p = firstEdge[node]; p != -1; p = nextEdge[p]) {
                int to = edgeTo[p];
                long cost = edgeCost[p];
                if (to == prev) continue;
                nodeCost[to] = cost;
                dfs(to, node, level + 1);
                edgeSon[p / 2] = to;
            }
        }

        private class DSU {
            int[] father;
            int[] criteria;

            DSU(int[] criteria) {
                this.criteria = criteria.clone();
                father = new int[criteria.length];
                for (int i = 0; i < father.length; ++i)
                    father[i] = i;
            }

            public int find(int x) {
                int y = father[x];
                while (y != father[y]) y = father[y];

                for (int p; x != y; x = p) {
                    p = father[x];
                    father[x] = y;
                }
                return y;
            }

            public void unite(int x, int y) {
                x = find(x);
                y = find(y);
                if (criteria[x] < criteria[y])
                    father[y] = x;
                else
                    father[x] = y;
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