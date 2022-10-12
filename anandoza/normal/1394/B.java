import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        BBoboniuWalksOnGraph solver = new BBoboniuWalksOnGraph();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBoboniuWalksOnGraph {
        int k;
        int k2;
        long[][] sum;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            Random r = new Random();
            long[] w = new long[n];
            for (int i = 0; i < n; i++) {
                w[i] = r.nextLong();
            }

            k = in.nextInt();
            Pair<Graphs.Edge[], List<Integer>[]> graph = GraphIO.readWeightedDirectedAdjacencyList(in, n, m);
            Graphs.Edge[] edges = graph.first;
            List<Integer>[] adj = graph.second;
            for (int i = 0; i < n; i++) {
                adj[i].sort(Comparator.comparingInt(j -> edges[j].cost));
            }

            k2 = k * (k + 1) / 2;

            sum = new long[k][k];
            for (int i = 0; i < n; i++) {
                int d = adj[i].size() - 1;
                for (int l = 0; l <= d; l++) {
                    int j = edges[adj[i].get(l)].j;
                    sum[d][l] ^= w[i] ^ w[j];
                }
            }

            int answer = dfs(0, 0);
            out.println(answer);
        }

        private int dfs(int index, long sum) {
            if (index == k) {
                return sum == 0 ? 1 : 0;
            }
            int answer = 0;
            for (int i = 0; i <= index; i++) {
                answer += dfs(index + 1, sum ^ this.sum[index][i]);
            }
            return answer;
        }

    }

    static class GraphIO {
        public static Pair<Graphs.Edge[], List<Integer>[]> readWeightedDirectedAdjacencyList(InputReader in, int n, int m) {
            Graphs.Edge[] edges = new Graphs.Edge[m];
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int t = in.nextInt();
                edges[i] = new Graphs.Edge(a, b, t);
                adj[a].add(i);
            }

            return Pair.of(edges, adj);
        }

        private GraphIO() {
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

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
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

    }
}