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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[] firstEdge;
        int[] nextEdge;
        int[] to;
        int[] type;
        boolean[] used;
        int[] values;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            firstEdge = new int[n];
            Arrays.fill(firstEdge, -1);
            nextEdge = new int[2 * m];
            to = new int[2 * m];
            type = new int[2 * m];
            for (int i = 0; i < m; ++i) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                this.to[2 * i] = to;
                nextEdge[2 * i] = firstEdge[from];
                firstEdge[from] = 2 * i;
                type[2 * i] = +1;

                this.to[2 * i + 1] = from;
                nextEdge[2 * i + 1] = firstEdge[to];
                firstEdge[to] = 2 * i + 1;
                type[2 * i + 1] = -1;
            }

            used = new boolean[n];
            values = new int[n];
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    dfs(i);
                }
            }

            int min = n;
            for (int i = 0; i < n; ++i)
                min = Math.min(min, values[i]);
            for (int i = 0; i < n; ++i)
                values[i] -= min;

            int fans = 0;
            for (int i = 0; i < n; ++i) {
                for (int e = firstEdge[i]; e != -1; e = nextEdge[e]) {
                    int to = this.to[e];
                    fans = gcd(fans, Math.abs(values[to] - type[e] - values[i]));
                }
            }
            if (fans == 0) fans = n;

            out.println(fans);
        }

        private void dfs(int node) {
            used[node] = true;
            for (int e = firstEdge[node]; e != -1; e = nextEdge[e]) {
                int to = this.to[e];
                if (!used[to]) {
                    values[to] = values[node] + type[e];
                    dfs(to);
                }
            }
        }

        private int gcd(int a, int b) {
            while (b != 0) {
                int c = a % b;
                a = b;
                b = c;
            }
            return a;
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