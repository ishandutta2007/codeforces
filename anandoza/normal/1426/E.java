import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        ERockPaperScissors solver = new ERockPaperScissors();
        solver.solve(1, in, out);
        out.close();
    }

    static class ERockPaperScissors {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(3);
            int[] b = in.readIntArray(3);

            out.println(Util.join(n - ld(a, b), w(a, b)));
        }

        private int ld(int[] a, int[] b) {
            MaxFlow mf = new MaxFlow(8);
            for (int i = 0; i < 3; i++) {
                mf.addEdge(0, 1 + i, a[i]);
                mf.addEdge(4 + i, 7, b[i]);
            }

            for (int i = 0; i < 3; i++) {
                mf.addEdge(1 + i, 4 + i, Long.MAX_VALUE);
            }
            for (int i = 0; i < 3; i++) {
                int j = (i + 2) % 3;
                mf.addEdge(1 + i, 4 + j, Long.MAX_VALUE);
            }

            return (int) mf.maxFlow(0, 7);
        }

        private int w(int[] a, int[] b) {
            MaxFlow mf = new MaxFlow(8);
            for (int i = 0; i < 3; i++) {
                mf.addEdge(0, 1 + i, a[i]);
                mf.addEdge(4 + i, 7, b[i]);
            }

            for (int i = 0; i < 3; i++) {
                int j = (i + 1) % 3;
                mf.addEdge(1 + i, 4 + j, Long.MAX_VALUE);
            }

            return (int) mf.maxFlow(0, 7);
        }

        class MaxFlow {
            private static final long INF = Long.MAX_VALUE;
            private final int n;
            private int m;
            private final java.util.ArrayList<CapEdge> edges;
            private final int[] count;
            private final CapEdge[][] g;

            public MaxFlow(int n) {
                this.n = n;
                this.edges = new java.util.ArrayList<>();
                this.count = new int[n];
                this.g = new CapEdge[n][];
            }

            public int addEdge(int from, int to, long cap) {
                rangeCheck(from, 0, n);
                rangeCheck(to, 0, n);
                nonNegativeCheck(cap, "Capacity");
                CapEdge e = new CapEdge(from, to, cap, count[to]);
                count[from]++;
                count[to]++;
                edges.add(e);
                return m++;
            }

            private void buildGraph() {
                for (int i = 0; i < n; i++) {
                    g[i] = new CapEdge[count[i]];
                }
                int[] idx = new int[n];
                for (CapEdge e : edges) {
                    g[e.to][idx[e.to]++] = new CapEdge(e.to, e.from, 0, idx[e.from]);
                    g[e.from][idx[e.from]++] = e;
                }
            }

            public long maxFlow(int s, int t) {
                return flow(s, t, INF);
            }

            public long flow(int s, int t, long flowLimit) {
                rangeCheck(s, 0, n);
                rangeCheck(t, 0, n);
                buildGraph();
                long flow = 0;
                int[] level = new int[n];
                int[] que = new int[n];
                int[] iter = new int[n];
                while (true) {
                    Arrays.fill(level, -1);
                    dinicBFS(s, t, level, que);
                    if (level[t] < 0)
                        return flow;
                    Arrays.fill(iter, 0);
                    while (true) {
                        long d = dinicDFS(t, s, flowLimit - flow, iter, level);
                        if (d <= 0)
                            break;
                        flow += d;
                        if (flow == flowLimit)
                            return flow;
                    }
                }
            }

            private void dinicBFS(int s, int t, int[] level, int[] que) {
                int hd = 0, tl = 0;
                que[tl++] = s;
                level[s] = 0;
                while (tl > hd) {
                    int u = que[hd++];
                    for (CapEdge e : g[u]) {
                        int v = e.to;
                        if (e.cap <= 0 || level[v] >= 0)
                            continue;
                        level[v] = level[u] + 1;
                        if (v == t)
                            return;
                        que[tl++] = v;
                    }
                }
            }

            private long dinicDFS(int cur, int s, long f, int[] iter, int[] level) {
                if (cur == s)
                    return f;
                long res = 0;
                while (iter[cur] < count[cur]) {
                    CapEdge er = g[cur][iter[cur]++];
                    int u = er.to;
                    CapEdge e = g[u][er.rev];
                    if (level[u] >= level[cur] || e.cap <= 0)
                        continue;
                    long d = dinicDFS(u, s, Math.min(f - res, e.cap), iter, level);
                    if (d <= 0)
                        continue;
                    e.cap -= d;
                    er.cap += d;
                    res += d;
                    if (res == f)
                        break;
                }
                return res;
            }

            private void rangeCheck(int i, int minInclusive, int maxExclusive) {
                if (i < 0 || i >= maxExclusive) {
                    throw new IndexOutOfBoundsException(String.format("Index %d out of bounds for length %d", i, maxExclusive));
                }
            }

            private void nonNegativeCheck(long cap, String attribute) {
                if (cap < 0) {
                    throw new IllegalArgumentException(String.format("%s %d is negative.", attribute, cap));
                }
            }

            public class CapEdge {
                private final int from;
                private final int to;
                private long cap;
                private final int rev;

                CapEdge(int from, int to, long cap, int rev) {
                    this.from = from;
                    this.to = to;
                    this.cap = cap;
                    this.rev = rev;
                }

            }

        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        private Util() {
        }

    }

    static class InputReader {
        public final BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}