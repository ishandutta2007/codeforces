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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
        /*for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = in.nextInt();
                A[i] += x;
                B[j] += x;
            }
        }*/

            FenwickTree S1 = new FenwickTree(n);
            FenwickTree S2 = new FenwickTree(m);

            while (q-- > 0) {
                int type = in.nextInt();
                int x1 = in.nextInt() - 1, y1 = in.nextInt() - 1;
                int x2 = in.nextInt() - 1, y2 = in.nextInt() - 1;
                if (type == 1) {
                    long s1 = S1.query(0, x1 - 1) + S1.query(x2 + 1, n - 1) +
                            S2.query(0, y1 - 1) + S2.query(y2 + 1, m - 1);
                    long s2 = S1.query(x1, x2) + S2.query(y1, y2);
                    out.println((s2 - s1) / 2);
                } else {
                    int v = in.nextInt();
                    S1.update(x1, x2, (y2 - y1 + 1) * v);
                    S2.update(y1, y2, (x2 - x1 + 1) * v);
                }
            }
        }

        private class FenwickTree {
            private long[] sum;
            private long[] coef;
            private int size;

            FenwickTree(int n) {
                sum = new long[n + 1];
                coef = new long[n + 1];
                size = n;
            }

            public void update(int left, int right, int value) {
                ++left;
                ++right;
                for (int i = left; i <= size; i += i & -i) {
                    coef[i] += value;
                }
                for (int i = right + 1; i <= size; i += i & -i) {
                    coef[i] -= value;
                }
                long add = (long) (left - 1) * value;
                for (int i = left; i <= size; i += i & -i) {
                    sum[i] -= add;
                }
                for (int i = right + 1; i <= size; i += i & -i) {
                    sum[i] += add;
                    sum[i] += (long) (right - left + 1) * value;
                }
            }

            private long getSum(int pos) {
                long c = 0, s = 0;
                for (int i = ++pos; i > 0; i -= i & -i) {
                    c += coef[i];
                    s += sum[i];
                }
                return pos * c + s;
            }

            public long query(int left, int right) {
                return getSum(right) - getSum(left - 1);
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