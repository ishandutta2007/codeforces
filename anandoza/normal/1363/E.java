import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.function.IntConsumer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.BitSet;
import java.util.Queue;
import java.io.BufferedReader;
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
        ETreeShuffling solver = new ETreeShuffling();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETreeShuffling {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] target = new int[n];
            int[] start = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                target[i] = in.nextInt();
                start[i] = in.nextInt();
            }

            List<Integer>[] adj = GraphIO.readUndirectedAdjacencyList(in, n, n - 1);

            int bSum = 0, cSum = 0;
            for (int i = 0; i < n; i++) {
                bSum += target[i];
                cSum += start[i];
            }
            if (bSum != cSum) {
                out.println(-1);
                return;
            }

            // update costs
            {
                BitSet visited = new BitSet();
                Queue<Integer> q = new ArrayDeque<>();
                visited.set(0);
                q.add(0);
                while (!q.isEmpty()) {
                    int cur = q.poll();
                    for (int next : adj[cur]) {
                        if (visited.get(next))
                            continue;

                        a[next] = Math.min(a[cur], a[next]);
                        q.add(next);
                        visited.set(next);
                    }
                }
            }

            int[] surplus = new int[n];
            final long[] answer = {0};
            IntConsumer dfs = new IntConsumer() {
                BitSet visited = new BitSet();

                public void accept(int cur) {
                    visited.set(cur);
                    List<Integer> imbalances = new ArrayList<>();
                    imbalances.add(start[cur] - target[cur]);
                    for (int next : adj[cur]) {
                        if (visited.get(next))
                            continue;

                        accept(next);
                        imbalances.add(surplus[next]);
                    }
                    for (int x : imbalances)
                        surplus[cur] += x;
                    int neg = 0;
                    int pos = 0;
                    for (int x : imbalances) {
                        if (x < 0)
                            neg += Math.abs(x);
                        else
                            pos += Math.abs(x);
                    }
                    int move = Math.min(neg, pos);
                    long cost = (long) a[cur] * move * 2;
                    answer[0] += cost;
                }
            };

            dfs.accept(0);
            out.println(answer[0]);
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