import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

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
        int[] have;
        int[] need;
        int[] prev;
        List<Transfusion> fans = new ArrayList<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), v = in.nextInt(), m = in.nextInt();
            firstEdge = new int[n];
            Arrays.fill(firstEdge, -1);
            nextEdge = new int[2 * m];
            to = new int[2 * m];
            have = new int[n];
            need = new int[n];
            prev = new int[n];

            for (int i = 0; i < n; ++i) have[i] = in.nextInt();
            for (int i = 0; i < n; ++i) need[i] = in.nextInt();
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1;
                to[2 * i] = y;
                nextEdge[2 * i] = firstEdge[x];
                firstEdge[x] = 2 * i;

                to[2 * i + 1] = x;
                nextEdge[2 * i + 1] = firstEdge[y];
                firstEdge[y] = 2 * i + 1;
            }

            while (true) {
                int node = 0;
                while (node < n && have[node] >= need[node])
                    ++node;

                if (node == n) break;

                Arrays.fill(prev, -1);
                prev[node] = -2;
                int dest = dfs(node);
                if (dest == -1) break;

                int flow = Math.min(need[node] - have[node],
                        have[dest] - need[dest]);

                pushFlow(dest, node, flow);
            }

            for (int i = 0; i < n; ++i) {
                if (have[i] != need[i]) {
                    out.println("NO");
                    return;
                }
            }
            out.println(fans.size());
            for (Transfusion p : fans) {
                out.println((p.from + 1) + " " + (p.to + 1) + " " + p.flow);
            }
        }

        private void push(int from, int to, int flow) {
            have[from] -= flow;
            have[to] += flow;
            fans.add(new Transfusion(from, to, flow));
        }

        private void pushFlow(int from, int to, int flow) {
            int n = prev[from];
            if (n == to) {
                push(from, to, flow);
            } else {
                int remFlow = flow;
                if (have[n] < flow) {
                    int diff = flow - have[n];
                    push(from, n, diff);
                    remFlow -= diff;
                }
                pushFlow(n, to, flow);
                push(from, n, remFlow);
            }
        }

        private int dfs(int node) {
            if (have[node] > need[node]) {
                return node;
            }
            for (int p = firstEdge[node]; p != -1; p = nextEdge[p]) {
                int to = this.to[p];
                if (prev[to] == -1) {
                    prev[to] = node;
                    int x = dfs(to);
                    if (x != -1) return x;
                }
            }
            return -1;
        }

        private class Transfusion {
            int from;
            int to;
            int flow;

            Transfusion(int from, int to, int flow) {
                this.from = from;
                this.to = to;
                this.flow = flow;
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