import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            int n = in.nextInt(), m = in.nextInt();
            int[] A = new int[n];
            for (int i = 0; i < n; ++i) {
                A[i] = in.nextInt();
            }
            ArraysUtils.sort(A);
            Segment[] updates = new Segment[m];
            for (int i = 0; i < m; ++i) {
                int lval = in.nextInt(), rval = in.nextInt();
                int left = search(A, lval);
                int right = search(A, rval + 1);
                updates[i] = new Segment(left, right - 1);
            }

            Arrays.sort(updates, (o1, o2) -> Integer.compare(o1.left, o2.left));
            SegmentTree t = new SegmentTree(n);

            long[] count1 = new long[n], count2 = new long[n];

            for (int i = 0, j = 0; i < n; ++i) {
                while (j < m && updates[j].left <= i) {
                    t.update(updates[j].left, updates[j].right);
                    j++;
                }
                count1[i] = t.query(i + 1, n - 1) & ((1L << 32) - 1);
            }

            Arrays.sort(updates, (o1, o2) -> -Integer.compare(o1.right, o2.right));
            t.clear();

            for (int i = n - 1, j = 0; i >= 0; --i) {
                while (j < m && updates[j].right >= i) {
                    t.update(updates[j].left, updates[j].right);
                    j++;
                }
                count2[i] = t.query(0, i - 1) >> 32;
            }

            long ans = (long) n * (n - 1) * (n - 2) / 6;
            for (int i = 0; i < n; ++i) {
                long s = count1[i] + count2[i];
                ans -= s * (s - 1) / 2;
            }

            out.println(ans);
        }

        private int search(int[] A, int value) {
            int pos = -1, step;
            for (step = 1; step < A.length; step *= 2) ;
            for (; step > 0; step /= 2) {
                if (pos + step < A.length && A[pos + step] < value)
                    pos += step;
            }
            return pos + 1;
        }

        private class Segment {
            int left;
            int right;

            Segment(int left, int right) {
                this.left = left;
                this.right = right;
            }

        }

        private class SegmentTree {
            private int[] even;
            private int[] odd;
            private boolean[] lazy;
            int size;

            SegmentTree(int n) {
                even = new int[4 * n];
                odd = new int[4 * n];
                lazy = new boolean[4 * n];
                size = n;
                build(0, 0, n - 1);
            }

            private void updateNode(int node) {
                even[node] = even[2 * node + 1] + even[2 * node + 2];
                odd[node] = odd[2 * node + 1] + odd[2 * node + 2];
            }

            private void build(int node, int left, int right) {
                lazy[node] = false;
                if (left == right) {
                    even[node] = 1;
                    odd[node] = 0;
                } else {
                    int mid = (left + right) / 2;
                    build(2 * node + 1, left, mid);
                    build(2 * node + 2, mid + 1, right);
                    updateNode(node);
                }
            }

            private void split(int node, int left, int right) {
                if (!lazy[node]) return;
                int aux = even[node];
                even[node] = odd[node];
                odd[node] = aux;
                if (left < right) {
                    lazy[2 * node + 1] ^= true;
                    lazy[2 * node + 2] ^= true;
                }
                lazy[node] = false;
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

            private long query(int node, int left, int right, int lq, int rq) {
                split(node, left, right);
                if (lq <= left && right <= rq) {
                    return even[node] | (((long) odd[node]) << 32);
                } else {
                    int mid = (left + right) / 2;
                    long result = 0;
                    if (lq <= mid) {
                        result = query(2 * node + 1, left, mid, lq, rq);
                    }
                    if (rq > mid) {
                        result += query(2 * node + 2, mid + 1, right, lq, rq);
                    }
                    return result;
                }
            }

            public void update(int left, int right) {
                left = Math.max(left, 0);
                right = Math.min(right, size - 1);
                if (left > right) return;
                update(0, 0, size - 1, left, right);
            }

            public long query(int left, int right) {
                left = Math.max(left, 0);
                right = Math.min(right, size - 1);
                if (left > right) return 0L;
                return query(0, 0, size - 1, left, right);
            }

            public void clear() {
                build(0, 0, size - 1);
            }

        }

    }

    static class ArraysUtils {
        public static void randomShuffle(int[] A, int from, int to) {
            Random rnd = new Random();
            for (int i = from; i < to; ++i) {
                int pos = i + rnd.nextInt(to - i);
                swap(A, i, pos);
            }
        }

        public static void sort(int[] A, int from, int to) {
            randomShuffle(A, from, to);
            Arrays.sort(A, from, to);
        }

        public static void sort(int[] A) {
            sort(A, 0, A.length);
        }

        public static void swap(int[] A, int i, int j) {
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
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