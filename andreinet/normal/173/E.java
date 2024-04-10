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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            Person[] members = new Person[n];
            Person[] init = new Person[n];
            for (int i = 0; i < n; ++i) {
                members[i] = new Person(0, in.nextInt());
            }
            for (int i = 0; i < n; ++i) {
                members[i].a = in.nextInt();
                init[i] = members[i];
            }

            Arrays.sort(members, (o1, o2) -> Integer.compare(o1.a, o2.a));
            int[] as = new int[n];
            for (int i = 0; i < n; ++i) {
                members[i].pos = i;
                as[i] = members[i].a;
            }

            FenwickTree t = new FenwickTree(n);
            int[] count = new int[n];

            Arrays.sort(members, (o1, o2) -> Integer.compare(o1.r, o2.r));
            for (int i = 0, j; i < n; i = j) {
                for (j = i; j < n && members[j].r == members[i].r; ++j)
                    t.update(members[j].pos, 1);
                for (int p = i; p < j; ++p) {
                    int l = search(as, members[p].a - k);
                    int r = search(as, members[p].a + k + 1) - 1;
                    if (l <= r) {
                        count[members[p].pos] = t.query(l, r);
                    }
                }
            }

            int q = in.nextInt();
            Query[] queries = new Query[q];
            for (int i = 0; i < q; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int left = Math.max(init[x].a, init[y].a) - k;
                int right = Math.min(init[x].a, init[y].a) + k;
                int l = search(as, left);
                int r = search(as, right + 1) - 1;
                int up = Math.max(init[x].r, init[y].r);
                queries[i] = new Query(l, r, up, i);
            }

            SegmentTree T = new SegmentTree(n);

            int[] fans = new int[q];
            Arrays.sort(queries, (o1, o2) -> -Integer.compare(o1.up, o2.up));
            for (int i = 0, j = n - 1; i < q; ++i) {
                Query curr = queries[i];
                while (j >= 0 && members[j].r >= curr.up) {
                    int x = members[j--].pos;
                    T.update(x, count[x]);
                }
                if (curr.left <= curr.right) {
                    fans[curr.pos] = T.query(curr.left, curr.right);
                }
            }

            for (int p : fans) {
                if (p == 0) --p;
                out.println(p);
            }
        }

        private int search(int[] a, int e) {
            int pos = -1, step;
            for (step = 1; step < a.length; step *= 2) ;
            for (; step > 0; step /= 2) {
                if (pos + step < a.length && a[pos + step] < e)
                    pos += step;
            }
            return pos + 1;
        }

        private class FenwickTree {
            int[] tree;

            FenwickTree(int n) {
                tree = new int[n + 1];
            }

            public void update(int pos, int value) {
                for (++pos; pos < tree.length; pos += pos & -pos)
                    tree[pos] += value;
            }

            public int query(int pos) {
                int ret = 0;
                for (++pos; pos > 0; pos -= pos & -pos)
                    ret += tree[pos];
                return ret;
            }

            public int query(int left, int right) {
                return query(right) - query(left - 1);
            }

        }

        private class SegmentTree {
            int[] tree;
            int size;

            SegmentTree(int n) {
                tree = new int[4 * n];
                size = n;
            }

            private void update(int node, int left, int right, int pos, int val) {
                if (left == right) {
                    tree[node] = val;
                } else {
                    int mid = (left + right) / 2;
                    if (pos <= mid) update(2 * node + 1, left, mid, pos, val);
                    else update(2 * node + 2, mid + 1, right, pos, val);
                    tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
                }
            }

            private int query(int node, int left, int right, int lq, int rq) {
                if (lq <= left && right <= rq) {
                    return tree[node];
                } else {
                    int mid = (left + right) / 2, ret = 0;
                    if (lq <= mid) {
                        ret = query(2 * node + 1, left, mid, lq, rq);
                    }
                    if (rq > mid) {
                        ret = Math.max(ret,
                                query(2 * node + 2, mid + 1, right, lq, rq));
                    }
                    return ret;
                }
            }

            public void update(int pos, int value) {
                update(0, 0, size - 1, pos, value);
            }

            public int query(int left, int right) {
                return query(0, 0, size - 1, left, right);
            }

        }

        private class Person {
            int a;
            int r;
            int pos;

            Person(int a, int r) {
                this.a = a;
                this.r = r;
                this.pos = 0;
            }

        }

        private class Query {
            int left;
            int right;
            int up;
            int pos;

            Query(int left, int right, int up, int pos) {
                this.left = left;
                this.right = right;
                this.up = up;
                this.pos = pos;
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