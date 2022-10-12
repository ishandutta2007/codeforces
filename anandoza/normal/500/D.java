import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DNewYearSantaNetwork solver = new DNewYearSantaNetwork();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNewYearSantaNetwork {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            Graphs.Edge[] edges = new Graphs.Edge[n - 1];
            for (int i = 0; i < n - 1; i++) {
                edges[i] = new Graphs.Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
                adj[edges[i].i].add(i);
                adj[edges[i].j].add(i);
            }

            int[] subtrees = new int[n - 1];
            dfs(subtrees, edges, adj, 0, -1);

            double[] weight = new double[n - 1];
            for (int i = 0; i < subtrees.length; i++) {
                long a = subtrees[i];
                long b = n - a;

                weight[i] = (double) a * b / Util.nc2(n);
            }

            for (int i = 0; i < weight.length; i++) {
                weight[i] *= 3;
            }

            double[] cost = new double[n - 1];
            for (int i = 0; i < n - 1; i++) {
                cost[i] = edges[i].cost;
            }
            double answer = 0;
            for (int i = 0; i < n - 1; i++) {
                answer += weight[i] * cost[i];
            }

            int q = in.nextInt();
            for (int query = 0; query < q; query++) {
                int j = in.nextInt() - 1;
                double w = in.nextInt();

                double diff = w - cost[j];
                cost[j] = w;

                answer += diff * weight[j];
                out.println(Util.formatDouble(answer));
            }
        }

        private void dfs(int[] subtrees, Graphs.Edge[] edges, List<Integer>[] adjLists, int root, int edge) {
            int weight = 1;
            for (int i : adjLists[root]) {
                if (i == edge)
                    continue;
                int next = edges[i].i ^ edges[i].j ^ root;

                dfs(subtrees, edges, adjLists, next, i);
                weight += subtrees[i];
            }
            if (edge >= 0)
                subtrees[edge] = weight;
        }

    }

    static class Graphs {
        public static class Edge {
            public final int i;
            public final int j;
            public final int cost;

            public Edge(int i, int j, int cost) {
                this.i = i;
                this.j = j;
                this.cost = cost;
            }

            public String toString() {
                return String.format("[(%d, %d): %d]", i, j, cost);
            }

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

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
        }

        public static long nc2(long n) {
            return n * (n - 1) / 2;
        }

    }
}