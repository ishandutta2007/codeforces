import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CJeremyBearimy solver = new CJeremyBearimy();
        solver.solve(1, in, out);
        out.close();
    }

    static class CJeremyBearimy {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            final int k = in.nextInt();
            final int n = 2 * k;
            Graphs.Edge[] edges = new Graphs.Edge[n - 1];
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int t = in.nextInt();
                edges[i] = new Graphs.Edge(a, b, t);
                adj[a].add(i);
                adj[b].add(i);
            }

            Pair<Long, Long> answer = solve(edges, adj);

            out.println(Util.join(answer.first, answer.second));
        }

        private Pair<Long, Long> solve(Graphs.Edge[] edges, List<Integer>[] adjLists) {
            final int n = adjLists.length;
            int[] subtrees = new int[n - 1];

            dfs(subtrees, edges, adjLists, 0, -1);

            long min = 0, max = 0;
            for (int i = 0; i < subtrees.length; i++) {
                long a = subtrees[i];
                long b = n - a;

                max += edges[i].cost * Math.min(a, b);
                min += edges[i].cost * (a % 2);
            }

            return Pair.of(min, max);
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
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

    }
}