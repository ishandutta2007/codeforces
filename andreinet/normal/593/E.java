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
        private final int Mod = (int) 1e9 + 7;
        final int[] dx = new int[]{0, 0, -1, 0, 1};
        final int[] dy = new int[]{0, -1, 0, 1, 0};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            int k = n * m;

            int[] ways = new int[k];
            ways[0] = 1;

            int[][] cats = new int[n][m];

            int last = 1;
            while (q-- > 0) {
                int type = in.nextInt();
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int t = in.nextInt();

                int[][] routes = specificMatrix(cats);
                int time = t - last;

                int[][] nways = identity(k);
                while (time > 0) {
                    if ((time & 1) != 0) nways = mul(nways, routes);
                    routes = mul(routes, routes);
                    time /= 2;
                }

                int[] cways = new int[k];
                for (int i = 0; i < k; ++i)
                    for (int j = 0; j < k; ++j)
                        cways[j] = (int) ((cways[j] +
                                (long) ways[i] * nways[i][j]) % Mod);

                ways = cways;

                switch (type) {
                    case 1:
                        out.println(ways[x * m + y]);
                        break;
                    case 2:
                        cats[x][y]++;
                        break;
                    case 3:
                        cats[x][y]--;
                        break;
                }

                last = t;
            }
        }

        private int[][] mul(int[][] a, int[][] b) {
            int n = a.length;
            int[][] c = new int[n][n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int k = 0; k < n; ++k)
                        c[i][j] = (int) ((c[i][j] +
                                (long) a[i][k] * b[k][j]) % Mod);
            return c;
        }

        private int[][] identity(int n) {
            int[][] result = new int[n][n];
            for (int i = 0; i < n; ++i) result[i][i] = 1;
            return result;
        }

        private int[][] specificMatrix(int[][] a) {
            int n = a.length, m = a[0].length;
            int k = n * m;
            int[][] result = new int[k][k];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int code1 = i * m + j;
                    if (a[i][j] != 0) continue;

                    for (int p = 0; p < 5; ++p) {
                        int ni = i + dx[p], nj = j + dy[p];
                        int code2 = ni * m + nj;

                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        if (a[ni][nj] == 0) result[code1][code2] = 1;
                    }
                }
            }
            return result;
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