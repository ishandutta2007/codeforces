import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            double p = in.nextDouble();
            double q = in.nextDouble();
            double[][] A = new double[2][n];
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                A[0][i] = -x;
                A[1][i] = -y;
            }
            double[] b = new double[2];
            b[0] = -p;
            b[1] = -q;
            double[] c = new double[n];
            for (int i = 0; i < n; ++i) {
                c[i] = -1.0;
            }

            Simplex s = new Simplex(A, b, c);
            double[] x = new double[n];
            double ans = s.solve(x);
            if (ans == Simplex.INFEASIBLE || ans == Simplex.UNBOUNDED) {
                throw new RuntimeException();
            }
            out.println(String.format("%.15f", ans));
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

        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Simplex {
        public static double INFEASIBLE = Double.NEGATIVE_INFINITY;
        public static double UNBOUNDED = Double.POSITIVE_INFINITY;
        public static double EPS = 1e-9;
        private int n;
        private int m;
        private double[][] A;
        private double[] c;
        private int[] N;
        private int[] B;

        public static int compare(double a, double b) {
            if (Math.abs(a - b) < EPS) {
                return 0;
            } else {
                return a < b ? -1 : 1;
            }
        }

        public Simplex(double[][] A, double[] b, double[] c) {
            this.n = c.length;
            this.m = b.length;
            this.A = new double[this.m + 2][this.n + 2];
            this.N = new int[this.n + 1];
            this.B = new int[this.m];
            for (int i = 0; i < this.m; ++i) {
                this.B[i] = this.n + i;
                for (int j = 0; j < this.n; ++j) {
                    this.A[i][j] = A[i][j];
                }
                this.A[i][this.n] = -1.0;
                this.A[i][this.n + 1] = b[i];
            }
            this.c = new double[this.n + 2];
            for (int i = 0; i < this.n; ++i) {
                this.N[i] = i;
                this.c[i] = c[i];
            }
            this.A[this.m] = this.c;

            this.A[this.m + 1][this.n] = -1.0;
            this.N[this.n] = -1;
        }

        public double solve(double[] x) {
            int row = 0;
            for (int i = 1; i < m; ++i) {
                if (A[i][n + 1] < A[row][n + 1]) {
                    row = i;
                }
            }
            if (A[row][n + 1] < -EPS) {
                pivot(row, n);
                if (!simplex(0) || A[m + 1][n + 1] < -EPS) {
                    return Simplex.INFEASIBLE;
                }
                for (int i = 0; i < m; ++i) {
                    if (B[i] == -1) {
                        int col = -1;
                        for (int j = 0; j <= n; ++j) {
                            if (col == -1 || compare(A[i][j], A[i][col]) < 0 ||
                                    (compare(A[i][j], A[i][col]) == 0 && N[j] < N[col])) {
                                col = j;
                            }
                        }
                        pivot(i, col);
                    }
                }
            }

            if (!simplex(1)) {
                return Simplex.UNBOUNDED;
            }

            for (int i = 0; i < m; ++i) {
                if (B[i] < n) {
                    x[B[i]] = A[i][n + 1];
                }
            }
            return A[m][n + 1];
        }

        private boolean simplex(int phase) {
            int x = phase == 0 ? m + 1 : m;
            while (true) {
                int col = -1;
                for (int i = 0; i <= n; ++i) {
                    if (phase == 1 && N[i] == -1) {
                        continue;
                    }
                    if (col == -1 || compare(A[x][i], A[x][col]) > 0 ||
                            compare(A[x][i], A[x][col]) == 0 && N[i] < N[col]) {
                        col = i;
                    }
                }

                if (A[x][col] < EPS) {
                    return true;
                }

                int row = -1;
                for (int i = 0; i < m; ++i) {
                    if (A[i][col] < EPS) {
                        continue;
                    }
                    if (row == -1 ||
                            compare(A[i][n + 1] / A[i][col], A[row][n + 1] / A[row][col]) < 0 ||
                            compare(A[i][n + 1] / A[i][col], A[row][n + 1] / A[row][col]) == 0 && B[i] < B[row]) {
                        row = i;
                    }
                }

                if (row == -1) {
                    return false;
                }

                pivot(row, col);
            }
        }

        private void pivot(int row, int col) {
            for (int i = 0; i < m + 2; ++i) {
                if (i != row) {
                    double r = A[i][col] / A[row][col];
                    for (int j = 0; j < n + 2; ++j) {
                        if (j != col) {
                            A[i][j] -= A[row][j] * r;
                        }
                    }
                }
            }
            for (int j = 0; j < n + 2; ++j) {
                if (j != col) {
                    A[row][j] /= A[row][col];
                }
            }
            for (int i = 0; i < m + 2; ++i) {
                if (i != row) {
                    A[i][col] /= -A[row][col];
                }
            }
            A[row][col] = 1.0 / A[row][col];
            { // swap(B[row], N[col])
                int aux = B[row];
                B[row] = N[col];
                N[col] = aux;
            }
        }

    }
}