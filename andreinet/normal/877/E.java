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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int[] firstEdge;
        int[] nextEdge;
        int[] to;
        int edges;
        int[] valuesOfNodes;
        int eulerPos;
        int[] left;
        int[] right;
        int[] eulerValues;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            edges = 0;
            firstEdge = new int[n];
            Arrays.fill(firstEdge, -1);
            nextEdge = new int[n - 1];
            to = new int[n - 1];
            for (int i = 1; i < n; ++i) {
                int f = in.nextInt() - 1;
                addEdge(f, i);
            }
            valuesOfNodes = new int[n];
            for (int i = 0; i < n; ++i) {
                valuesOfNodes[i] = in.nextInt();
            }
            eulerPos = 0;
            left = new int[n];
            right = new int[n];
            eulerValues = new int[n];
            dfs(0);

            SegmentTree t = new SegmentTree(eulerValues);
            int q = in.nextInt();
            while (q-- > 0) {
                String type = in.next();
                int node = in.nextInt() - 1;
                if (type.equals("get")) {
                    out.println(t.query(left[node], right[node]));
                } else {
                    t.update(left[node], right[node]);
                }
            }
        }

        private void dfs(int node) {
            eulerValues[eulerPos] = valuesOfNodes[node];
            left[node] = eulerPos++;
            for (int e = firstEdge[node]; e != -1; e = nextEdge[e]) {
                dfs(this.to[e]);
            }
            right[node] = eulerPos - 1;
        }

        private void addEdge(int from, int to) {
            this.to[edges] = to;
            nextEdge[edges] = firstEdge[from];
            firstEdge[from] = edges++;
        }

        private class SegmentTree {
            int[] tree;
            boolean[] lazy;
            int n;

            SegmentTree(int[] values) {
                n = values.length;
                tree = new int[4 * n + 5];
                lazy = new boolean[4 * n + 5];
                build(0, 0, n - 1, values);
            }

            void update(int left, int right) {
                update(0, 0, n - 1, left, right);
            }

            int query(int left, int right) {
                return query(0, 0, n - 1, left, right);
            }

            private void build(int node, int left, int right, int[] values) {
                if (left == right) {
                    tree[node] = values[left];
                } else {
                    int mid = (left + right) / 2;
                    build(2 * node + 1, left, mid, values);
                    build(2 * node + 2, mid + 1, right, values);
                    updateNode(node);
                }
            }

            private void update(int node, int left, int right, int lq, int rq) {
                split(node, left, right);
                if (lq <= left && right <= rq) {
                    lazy[node] ^= true;
                } else {
                    int mid = (left + right) / 2;
                    if (lq <= mid) {
                        update(2 * node + 1, left, mid, lq, rq);
                    }
                    if (rq > mid) {
                        update(2 * node + 2, mid + 1, right, lq, rq);
                    }
                    split(2 * node + 1, left, mid);
                    split(2 * node + 2, mid + 1, right);
                    updateNode(node);
                }
            }

            private int query(int node, int left, int right, int lq, int rq) {
                split(node, left, right);
                if (lq <= left && right <= rq) {
                    return tree[node];
                } else {
                    int mid = (left + right) / 2, ret = 0;
                    if (lq <= mid) {
                        ret = query(2 * node + 1, left, mid, lq, rq);
                    }
                    if (rq > mid) {
                        ret += query(2 * node + 2, mid + 1, right, lq, rq);
                    }
                    return ret;
                }
            }

            private void updateNode(int node) {
                tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            }

            private void split(int node, int left, int right) {
                if (lazy[node]) {
                    if (left < right) {
                        lazy[2 * node + 1] ^= true;
                        lazy[2 * node + 2] ^= true;
                    }
                    tree[node] = (right - left + 1) - tree[node];
                    lazy[node] = false;
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