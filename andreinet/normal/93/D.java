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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        final int MOD = (int) 1e9 + 7;
        int invMod2 = invmod(2);
        private final int sz = 22;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int l = in.nextInt(), r = in.nextInt();

            int ans = solve(r) - solve(l - 1);
            if (ans < 0) ans += MOD;

            out.println(ans);
        }

        private int pow(int x, int y) {
            int ret = 1;
            for (; y > 0; y >>= 1) {
                if ((y & 1) != 0) ret = (int) ((long) ret * x % MOD);
                x = (int) ((long) x * x % MOD);
            }
            return ret;
        }

        private int invmod(int x) {
            return pow(x, MOD - 2);
        }

        private boolean good(int a, int b) {
            return !(a == b ||
                    a == 0 && b == 3 ||
                    a == 3 && b == 0 ||
                    a == 1 && b == 2 ||
                    a == 2 && b == 1);
        }

        private boolean good(int a, int b, int c) {
            return !(a == 1 && b == 0 && c == 2 ||
                    a == 2 && b == 0 && c == 1);
        }

        private int solve(int n) {
            if (n <= 1) return 4 * n;

            Matrix A = new Matrix();
            for (int i = 0; i <= 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        if (!good(i, j) || !good(j, k) || !good(i, j, k))
                            continue;
                        A.a[5 * k + j][5 * j + i] = 1;
                    }
                }
            }
            for (int i = 0; i < 4; ++i) {
                A.a[5 * i + 4][20] = 1;
            }
            A.a[21][21] = 1;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= 4; ++j) {
                    if (good(i, j)) {
                        A.a[21][5 * i + j] = 1;
                    }
                }
            }

            int ans = pow(A, n + 1).a[21][20];
            if (n >= 2) {
                int add = pow(A, (n + 1) / 2 + 1).a[21][20];
                ans = (ans + add) % MOD;
                ans = (int) ((long) ans * invMod2 % MOD);
            }

            return ans;
        }

        private Matrix pow(Matrix x, int y) {
            Matrix ret = new Matrix();
            for (int i = 0; i < sz; ++i)
                ret.a[i][i] = 1;
            for (; y > 0; y >>= 1) {
                if ((y & 1) != 0) ret = ret.mul(x);
                x = x.mul(x);
            }
            return ret;
        }

        private class Matrix {
            int[][] a;

            Matrix() {
                a = new int[sz][sz];
            }

            public Matrix mul(Matrix o) {
                Matrix r = new Matrix();
                for (int i = 0; i < sz; ++i) {
                    for (int j = 0; j < sz; ++j) {
                        for (int k = 0; k < sz; ++k) {
                            r.a[i][j] = (int) ((r.a[i][j] +
                                    (long) a[i][k] * o.a[k][j]) % MOD);
                        }
                    }
                }
                return r;
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