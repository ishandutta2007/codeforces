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
        CPaintTheTree solver = new CPaintTheTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPaintTheTree {
        int n;
        int k;
        Graphs.Edge[] edges;
        Tree tree;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();

            edges = new Graphs.Edge[n - 1];
            for (int i = 0; i < n - 1; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                int w = in.nextInt();
                edges[i] = new Graphs.Edge(u, v, w);
            }
            tree = new Tree(n, edges);

            Object[] dp = tree.computeForAllSubtrees(this::eval);

            long answer = ((long[]) dp[dp.length - 1])[0];

            out.println(answer);
        }

        private long[] eval(int currentNodeIndex, List<long[]> childrenValues) {
            List<Long> diffs = new ArrayList<>();
            long[] result = new long[2];
            int e = 0;
            for (long[] child : childrenValues) {
                int cost = edges[tree.adj[currentNodeIndex].get(e++)].cost;
                if (child == null)
                    continue;
                diffs.add(Math.max(0, cost + child[1] - child[0]));
                result[1] += child[0];
            }

            diffs.sort(Comparator.reverseOrder());
            for (int i = 0; i < k - 1 && i < diffs.size(); i++) {
                result[1] += diffs.get(i);
            }
            result[0] = result[1];
            if (k - 1 < diffs.size()) {
                result[0] += diffs.get(k - 1);
            }
            return result;
        }

    }

    static class Tree {
        public int[] v;
        public List<Integer>[] adj;
        public Graphs.Edge[] edges;

        public Tree(int[] v, Graphs.Edge[] edges) {
            this(v.length, edges);
        }

        public Tree(int n, Graphs.Edge[] edges) {
            Util.ASSERT(edges.length == n - 1);

            v = new int[n];

            this.edges = edges;

            this.adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int edgeIndex = 0; edgeIndex < edges.length; edgeIndex++) {
                adj[edges[edgeIndex].i].add(edgeIndex);
                adj[edges[edgeIndex].j].add(edgeIndex);
            }
        }

        public <T> T[] computeForAllSubtrees(Tree.NodeEvaluator<T> evaluator) {
            int root = 0;
            T[] dp = (T[]) new Object[2 * edges.length + 1];

            dp[2 * edges.length] = computeForAllSubtreesHelper(root, -1, dp, evaluator);

            return dp;
        }

        private <T> T computeForAllSubtreesHelper(int root, int parent, T[] dp, Tree.NodeEvaluator<T> evaluator) {
            ArrayList<T> children = new ArrayList<>();
            for (int e : adj[root]) {
                int child = edges[e].i + edges[e].j - root;
                if (child == parent) {
                    children.add(null);
                    continue;
                }

                children.add(computeForAllSubtreesHelper(child, root, dp, evaluator));
                dp[e + edges[e].i == root ? 0 : edges.length] = children.get(children.size() - 1);
            }

            T result = evaluator.eval(root, children);
            return result;
        }

        public interface NodeEvaluator<T> {
            T eval(int currentNodeIndex, List<T> childrenValues);

        }

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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
}