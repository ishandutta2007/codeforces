import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.ArrayDeque;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        final int Inf = 0x3f3f3f3f;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt(), b = in.nextInt();
            TaskA.Node start = nextPoint(in);
            TaskA.Node finish = nextPoint(in);

            int N = in.nextInt();
            TaskA.Node[] nodes = new TaskA.Node[N + 2];
            nodes[0] = start;
            nodes[N + 1] = finish;

            for (int i = 1; i <= N; ++i) {
                int x1 = in.nextInt(), y1 = in.nextInt();
                int x2 = in.nextInt(), y2 = in.nextInt();
                if (x1 > x2) {
                    int aux = x1;
                    x1 = x2;
                    x2 = aux;
                }
                if (y1 > y2) {
                    int aux = y1;
                    y1 = y2;
                    y2 = aux;
                }
                nodes[i] = new TaskA.Node(x1, y1, x2, y2);
            }

            for (int i = 0; i <= N + 1; ++i) {
                for (int j = 0; j <= N + 1; ++j) {
                    if (i == j) continue;
                    if (nodes[i].sqDist(nodes[j]) <= a * a)
                        nodes[i].adj.add(nodes[j]);
                }
                nodes[i].dist = Inf;
            }

            bfs(nodes[0]);

            if (nodes[N + 1].dist == Inf) out.println("-1");
            else {
                double ans = 1e99;
                for (TaskA.Node curr : nodes) {
                    if (!curr.adj.contains(nodes[N + 1])) continue;
                    double dist = (a + b) * curr.dist + Math.sqrt(curr.sqDist(nodes[N + 1]));
                    ans = Math.min(ans, dist);
                }

                out.println(String.format("%.14f", ans));
            }
        }

        private void bfs(TaskA.Node start) {
            start.dist = 0;
            Queue<TaskA.Node> Q = new ArrayDeque<>();
            Q.add(start);
            while (!Q.isEmpty()) {
                TaskA.Node node = Q.poll();

                for (TaskA.Node p : node.adj)
                    if (p.dist > node.dist + 1) {
                        p.dist = node.dist + 1;
                        Q.add(p);
                    }
            }
        }

        private TaskA.Node nextPoint(InputReader in) {
            int x = in.nextInt(), y = in.nextInt();
            return new TaskA.Node(x, y, x, y);
        }

        private class Node {
            int x1;
            int y1;
            int x2;
            int y2;
            int dist;
            List<TaskA.Node> adj;

            Node(int x1, int y1, int x2, int y2) {
                this.x1 = x1;
                this.y1 = y1;
                this.x2 = x2;
                this.y2 = y2;
                dist = 0;
                adj = new ArrayList<>();
            }

            private int sqDist(TaskA.Node other) {
                int dx, dy;
                if (x2 <= other.x1) dx = other.x1 - x2;
                else if (other.x2 <= x1) dx = x1 - other.x2;
                else dx = 0;
                if (y2 <= other.y1) dy = other.y1 - y2;
                else if (other.y2 <= y1) dy = y1 - other.y2;
                else dy = 0;
                return dx * dx + dy * dy;
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