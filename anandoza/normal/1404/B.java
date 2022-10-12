import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BTreeTag solver = new BTreeTag();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTreeTag {
        private static final String ALICE = "Alice";
        private static final String BOB = "Bob";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            int da = in.nextInt(), db = in.nextInt();
            List<Integer>[] adj = GraphIO.readUndirectedAdjacencyList(in, n, n - 1);

            if (db < 2 * da + 1) {
                out.println(ALICE);
                return;
            }

            int[] distance = Graphs.distanceViaBFS(adj, a);
            if (distance[b] <= da) {
                out.println(ALICE);
                return;
            }

            int index = 0;
            for (int i = 0; i < distance.length; i++) {
                if (distance[i] > distance[index]) {
                    index = i;
                }
            }
            int[] d2 = Graphs.distanceViaBFS(adj, index);
            int diameter = Util.max(d2);

            db = Math.min(db, diameter);
            if (db < 2 * da + 1) {
                out.println(ALICE);
                return;
            }
            out.println(BOB);
        }

    }

    static class Util {
        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
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

    static class Graphs {
        public static int[] distanceViaBFS(Iterable<Integer>[] adj, int start) {
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

    }
}