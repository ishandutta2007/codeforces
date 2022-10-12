import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DShichikujiAndPowerGrid solver = new DShichikujiAndPowerGrid();
        solver.solve(1, in, out);
        out.close();
    }

    static class DShichikujiAndPowerGrid {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            long[] x = new long[n];
            long[] y = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            long[] c = in.readLongArray(n);
            long[] k = in.readLongArray(n);

            List<Graphs.LEdge> edges = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                edges.add(new Graphs.LEdge(i, n, c[i]));
            }

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long w = Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]);
                    edges.add(new Graphs.LEdge(i, j, w * (k[i] + k[j])));
                }
            }

            List<Graphs.LEdge> mst = Graphs.findMSTUsingKruskalLong(n + 1, edges);

            List<Integer> powerStations = new ArrayList<>();
            List<Graphs.LEdge> connections = new ArrayList<>();
            long answer = 0;
            for (Graphs.LEdge e : mst) {
                answer += e.cost;
                if (e.j == n) {
                    powerStations.add(e.i + 1);
                } else {
                    connections.add(e);
                }
            }

            out.println(answer);

            out.println(powerStations.size());
            out.println(Util.join(powerStations));

            out.println(connections.size());
            for (Graphs.LEdge e : connections) {
                out.println(Util.join(e.i + 1, e.j + 1));
            }
        }

    }

    static class UnionFind {
        private int[] __rep;
        private int[] __size;

        public UnionFind(int n) {
            __rep = new int[n];
            __size = new int[n];
            for (int i = 0; i < n; i++) {
                __rep[i] = i;
                __size[i] = 1;
            }
        }

        public int rep(int x) {
            if (__rep[x] == x) {
                return x;
            }

            int r = rep(__rep[x]);
            __rep[x] = r;
            return r;
        }

        public int size(int x) {
            return __size[rep(x)];
        }

        public boolean union(int x, int y) {
            x = rep(x);
            y = rep(y);

            if (x == y) {
                return false;
            }

            if (size(x) < size(y)) {
                int t = x;
                x = y;
                y = t;
            }

            // now size(x) >= size(y)

            __rep[y] = x;
            __size[x] += __size[y];
            return true;
        }

    }

    static class InputReader {
        public BufferedReader reader;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

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

    }

    static class Graphs {
        public static List<Graphs.LEdge> findMSTUsingKruskalLong(int n, List<Graphs.LEdge> edges) {
            edges.sort(Comparator.comparingLong(i -> i.cost));

            UnionFind uf = new UnionFind(n);
            List<Graphs.LEdge> mst = new ArrayList<>();

            for (Graphs.LEdge e : edges) {
                if (uf.rep(e.i) != uf.rep(e.j)) {
                    mst.add(e);
                    uf.union(e.i, e.j);
                }
            }

            return mst;
        }

        public static class LEdge {
            public final int i;
            public final int j;
            public final long cost;

            public LEdge(int i, int j, long cost) {
                this.i = i;
                this.j = j;
                this.cost = cost;
            }

            public String toString() {
                return String.format("[(%d, %d): %d]", i, j, cost);
            }

        }

    }
}