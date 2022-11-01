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
        final int maxVal = 1000_000;
        final int Mod = (int) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] numbers = new int[n];
            for (int i = 0; i < n; ++i) numbers[i] = in.nextInt();

            int[] primes = new int[maxVal + 1];
            int[] smallestDivisor = new int[maxVal + 1];
            int[] invmods = new int[maxVal + 1];
            int countPrimes = 0;

            invmods[1] = 1;
            for (int i = 2; i <= maxVal; ++i) {
                if (smallestDivisor[i] == 0) {
                    invmods[i] = invmod(i);
                    smallestDivisor[i] = i;
                    primes[countPrimes++] = i;
                }
                int limit = smallestDivisor[i];
                for (int j = 0; j < countPrimes && primes[j] <= limit
                        && i * primes[j] <= maxVal; ++j) {
                    smallestDivisor[i * primes[j]] = primes[j];
                    invmods[i * primes[j]] = (int)
                            ((long) invmods[i] * invmods[primes[j]] % Mod);
                }
            }

            int q = in.nextInt();
            Query[] queries = new Query[q];
            for (int i = 0; i < q; ++i)
                queries[i] = new Query(in.nextInt() - 1, in.nextInt() - 1, i);
            Arrays.sort(queries, (o1, o2) -> o1.right - o2.right);

            SegmentTree t = new SegmentTree(n);
            int[] answers = new int[q];

            int lastPos = -1;
            int[] last = new int[maxVal + 1];
            Arrays.fill(last, -1);
            for (Query current : queries) {
                for (int i = lastPos + 1; i <= current.right; ++i) {
                    int x = numbers[i];
                    int prod = 1;
                    while (x != 1) {
                        int dv = smallestDivisor[x];
                        int lastp = last[dv];
                        if (lastp != -1) {
                            t.update(lastp, (int) ((long) invmods[dv - 1] *
                                    dv % Mod));
                        }
                        last[dv] = i;

                        x /= dv;
                        prod = (int) ((long) prod * (dv - 1) % Mod);
                        while (x % dv == 0) {
                            x /= dv;
                            prod = (int) ((long) prod * dv % Mod);
                        }
                    }
                    t.update(i, prod);
                }
                answers[current.pos] = t.query(current.left, current.right);
                lastPos = current.right;
            }

            for (int answer : answers) out.println(answer);
        }

        private int Pow(int x, int y) {
            int ret = 1;
            while (y > 0) {
                if ((y & 1) != 0) ret = (int) ((long) ret * x % Mod);
                x = (int) ((long) x * x % Mod);
                y /= 2;
            }
            return ret;
        }

        private int invmod(int x) {
            return Pow(x, Mod - 2);
        }

        private class Query {
            int left;
            int right;
            int pos;

            Query(int left, int right, int pos) {
                this.left = left;
                this.right = right;
                this.pos = pos;
            }

        }

        private class SegmentTree {
            int[] tree;
            int size;

            SegmentTree(int size) {
                this.size = size;
                tree = new int[4 * size + 5];
                Arrays.fill(tree, 1);
            }

            public void update(int pos, int value) {
                update(0, 0, size - 1, pos, value);
            }

            private void update(int node, int left, int right, int pos, int value) {
                if (left == right) {
                    tree[node] = (int) ((long) tree[node] * value % Mod);
                } else {
                    int mid = (left + right) / 2;
                    if (pos <= mid) update(2 * node + 1, left, mid, pos, value);
                    else update(2 * node + 2, mid + 1, right, pos, value);
                    tree[node] = (int) ((long) tree[2 * node + 1] *
                            tree[2 * node + 2] % Mod);
                }
            }

            public int query(int left, int right) {
                return query(0, 0, size - 1, left, right);
            }

            private int query(int node, int left, int right, int lq, int rq) {
                if (lq <= left && right <= rq) {
                    return tree[node];
                } else {
                    int mid = (left + right) / 2, ret = 1;
                    if (lq <= mid) ret = query(2 * node + 1, left, mid, lq, rq);
                    if (rq > mid) ret = (int) ((long) ret *
                            query(2 * node + 2, mid + 1, right, lq, rq) % Mod);
                    return ret;
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