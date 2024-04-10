import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.function.IntBinaryOperator;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.ArrayDeque;
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
        ALinovaAndKingdom solver = new ALinovaAndKingdom();
        solver.solve(1, in, out);
        out.close();
    }

    static class ALinovaAndKingdom {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            List<Integer>[] adj = GraphIO.readUndirectedAdjacencyList(in, n, n - 1);

            int[] size = Graphs.subtreeSizes(adj, 0);
            int[] depth = Graphs.distanceViaBFS(adj, 0);

            int[] scores = new int[n];
            for (int i = 0; i < n; i++) {
                scores[i] = size[i] - 1 - depth[i];
            }

            Util.safeSort(scores);
            Util.reverse(scores);

            long answer = 0;
            for (int i = 0; i < n - k; i++) {
                answer += scores[i];
            }

            out.println(answer);
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
        public static void safeSort(int[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(int[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(int[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        private Util() {
        }

    }

    static class GraphIO {
        public static List<Integer>[] readUndirectedAdjacencyList(InputReader in, int n, int m) {
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                adj[u].add(v);
                adj[v].add(u);
            }
            return adj;
        }

        private GraphIO() {
        }

    }

    static class Graphs {
        public static int[] distanceViaBFS(List<Integer>[] adj, int start) {
            final int n = adj.length;
            int[] distance = new int[n];
            Arrays.fill(distance, -1);
            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            distance[start] = 0;

            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int next : adj[cur]) {
                    if (distance[next] != -1)
                        continue;

                    q.add(next);
                    distance[next] = distance[cur] + 1;
                }
            }

            return distance;
        }

        public static int[] preorder(List<Integer>[] adj, int root) {
            final int n = adj.length;
            int[] preorder = new int[n];

            IntBinaryOperator dfs = new IntBinaryOperator() {
                int index = 0;

                public int applyAsInt(int cur, int parent) {
                    preorder[index++] = cur;
                    for (int j : adj[cur]) {
                        if (j == parent)
                            continue;

                        this.applyAsInt(j, cur);
                    }

                    return 0;
                }
            };

            dfs.applyAsInt(root, -1);

            return preorder;
        }

        public static int[] postorder(List<Integer>[] adj, int root) {
            int[] postorder = preorder(adj, root);
            Util.reverse(postorder);
            return postorder;
        }

        public static int[] subtreeSizes(List<Integer>[] adj, int root) {
            final int n = adj.length;
            int[] size = new int[n];

            int[] postorder = postorder(adj, root);
            for (int i : postorder) {
                for (int j : adj[i]) {
                    size[i] += size[j];
                }
                size[i]++;
            }

            return size;
        }

    }
}