import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        final int maxSize = 31;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();

            int[] values = new int[n];
            for (int i = 0; i < n; ++i)
                values[i] = in.nextInt();

            SegmentTree t = new SegmentTree(values);
            while (q-- > 0) {
                int type = in.nextInt();
                if (type == 1) {
                    int left = in.nextInt() - 1, right = in.nextInt() - 1, value = in.nextInt();
                    t.update(left, right, value);
                } else {
                    int left = in.nextInt() - 1, right = in.nextInt() - 1;
                    DArray result = t.query(left, right);

                    out.println(1 << result.cnt);
                }
            }
        }

        private int merge(int[] a, int sa, int[] b, int sb, int[] dest) {
            int[] result = new int[sa + sb];
            int sr = sa + sb;

            for (int i = 0; i < sa; ++i) result[i] = a[i];
            for (int i = sa; i < sr; ++i) result[i] = b[i - sa];
            for (int i = 0; i < sr; ++i) {
                int p = biggestOneBit(result[i]);
                for (int j = 0; j < sr; ++j)
                    if (j != i && (result[j] & (1 << p)) != 0)
                        result[j] ^= result[i];
            }
            int k = sr;
            sr = 0;
            for (int i = 0; i < k; ++i)
                if (result[i] != 0)
                    result[sr++] = result[i];
            System.arraycopy(result, 0, dest, 0, sr);
            return sr;
        }

        private int biggestOneBit(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

        private class SegmentTree {
            private int[][] tree;
            private int[] treeSize;
            private int[] lazy;
            int size;

            public SegmentTree(int[] values) {
                this.size = values.length;
                tree = new int[4 * size + 5][maxSize];
                treeSize = new int[4 * size + 5];
                lazy = new int[size + 1];
                build(0, 0, size - 1, modify(values));
                for (int i = 0; i < size; ++i)
                    lazyUpdate(i + 1, i + 1, values[i]);
            }

            private int[] modify(int[] values) {
                int[] result = values.clone();
                for (int i = 1; i < values.length; ++i)
                    result[i] ^= values[i - 1];
                return result;
            }

            private void updateNode(int node) {
                treeSize[node] = merge(tree[2 * node + 1], treeSize[2 * node + 1],
                        tree[2 * node + 2], treeSize[2 * node + 2],
                        tree[node]);
            }

            private void build(int node, int left, int right, int[] values) {
                if (left == right) {
                    tree[node][0] = values[left];
                    treeSize[node] = values[left] != 0 ? 1 : 0;
                } else {
                    int mid = (left + right) / 2;
                    build(2 * node + 1, left, mid, values);
                    build(2 * node + 2, mid + 1, right, values);
                    updateNode(node);
                }
            }

            private void cupdate(int node, int left, int right, int pos, int value) {
                if (left == right) {
                    tree[node][0] ^= value;
                    treeSize[node] = tree[node][0] != 0 ? 1 : 0;
                } else {
                    int mid = (left + right) / 2;

                    if (pos <= mid) cupdate(2 * node + 1, left, mid, pos, value);
                    else cupdate(2 * node + 2, mid + 1, right, pos, value);
                    updateNode(node);
                }
            }

            private void cquery(int node, int left, int right, int lq, int rq, DArray dest) {
                if (lq <= left && right <= rq) {
                    dest.cnt = merge(dest.a.clone(), dest.cnt, tree[node], treeSize[node], dest.a);
                } else {
                    int mid = (left + right) / 2;
                    if (lq <= mid) cquery(2 * node + 1, left, mid, lq, rq, dest);
                    if (rq > mid) cquery(2 * node + 2, mid + 1, right, lq, rq, dest);
                }
            }

            private void lazyUpdate(int pos, int value) {
                for (; pos < lazy.length; pos += pos & -pos)
                    lazy[pos] ^= value;
            }

            private void lazyUpdate(int left, int right, int value) {
                lazyUpdate(left, value);
                if (right + 1 <= size) lazyUpdate(right + 1, value);
            }

            private int lazyQuery(int pos) {
                int ret = 0;
                for (; pos > 0; pos -= pos & -pos)
                    ret ^= lazy[pos];
                return ret;
            }

            public void update(int left, int right, int value) {
                cupdate(0, 0, size - 1, left, value);
                if (right + 1 < size) cupdate(0, 0, size - 1, right + 1, value);
                lazyUpdate(left + 1, right + 1, value);
            }

            public DArray query(int left, int right) {
                DArray result = new DArray();
                if (left < right) cquery(0, 0, size - 1, left + 1, right, result);
                int x = lazyQuery(left + 1);
                result.cnt = merge(result.a.clone(), result.cnt, new int[]{x}, 1, result.a);
                return result;
            }

        }

        private class DArray {
            int[] a;
            int cnt;

            DArray() {
                a = new int[maxSize];
                cnt = 0;
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