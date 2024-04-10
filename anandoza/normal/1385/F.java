import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FRemovingLeaves solver = new FRemovingLeaves();
        solver.solve(1, in, out);
        out.close();
    }

    static class FRemovingLeaves {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            List<Integer>[] adj = GraphIO.readUndirectedAdjacencyList(in, n, n - 1);

            if (k == 1) {
                out.println(n - 1);
                return;
            }

            int[] degree = new int[n];
            for (int i = 0; i < adj.length; i++) {
                degree[i] = adj[i].size();
            }
            int[] leaves = new int[n];
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1) {
                    leaves[adj[i].get(0)]++;
                }
            }

            Queue<Integer> q = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                if (leaves[i] >= k) {
                    q.add(i);
                }
            }

            int answer = 0;
            while (!q.isEmpty()) {
                int cur = q.poll();
                int moves = leaves[cur] / k;
                answer += moves;
                degree[cur] -= moves * k;
                leaves[cur] -= moves * k;
                if (degree[cur] == 1) {
                    for (int parent : adj[cur]) {
                        if (degree[parent] == 1)
                            continue;
                        leaves[parent]++;
                        if (leaves[parent] == k)
                            q.add(parent);
                    }
                }
            }

            out.println(answer);
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
}