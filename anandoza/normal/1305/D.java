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
import java.util.BitSet;
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
        DKuroniAndTheCelebration solver = new DKuroniAndTheCelebration();
        solver.solve(1, in, out);
        out.close();
    }

    static class DKuroniAndTheCelebration {
        InputReader in;
        PrintWriter out;
        int queries = 0;
        List<Integer>[] adj;
        int n;
        boolean[] valid;
        int validCount;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            n = in.nextInt();
            adj = GraphIO.readUndirectedAdjacencyList(in, n, n - 1);
            valid = new boolean[n];
            Arrays.fill(valid, true);
            validCount = n;

            while (validCount > 1) {
                if (validCount == 2) {
                    int prev = -1;
                    for (int i = 0; i < n; i++) {
                        if (!valid[i])
                            continue;
                        if (prev == -1) {
                            prev = i;
                        } else {
                            int x = query(prev, i);
                            invalidate(prev + i - x);
                        }
                    }
                    continue;
                }

                for (int i = 0; i < n; i++) {
                    if (!valid[i])
                        continue;

                    if (adj[i].size() >= 2) {
                        int u = adj[i].get(0);
                        int v = adj[i].get(1);
                        int good = query(u, v);
                        if (good == i) {
                            fillInvalid(u, i);
                            fillInvalid(v, i);
                        } else {
                            fillInvalid(i, good);
                        }
                        break;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (valid[i]) {
                    guess(i);
                }
            }
        }

        private void invalidate(int i) {
            if (valid[i]) {
                validCount--;
                valid[i] = false;
            }
        }

        private void fillInvalid(int cur, int parent) {
            adj[cur].remove((Integer) parent);
            adj[parent].remove((Integer) cur);
            BitSet bitSet = Graphs.reachabilityViaBFS(n, adj, cur);
            for (int i = 0; i < n; i++) {
                if (bitSet.get(i)) {
                    invalidate(i);
                }
            }
        }

        private int query(int i, int j) {
            queries++;
            out.println("? " + Util.join(i + 1, j + 1));
            out.flush();
            int x = in.nextInt() - 1;
            return x;
        }

        private void guess(int i) {
            out.println("! " + (i + 1));
            out.flush();
        }

    }

    static class Graphs {
        public static BitSet reachabilityViaBFS(int n, List<Integer>[] adj, int start) {
            BitSet visited = new BitSet();
            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            visited.set(start);

            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int next : adj[cur]) {
                    if (visited.get(next))
                        continue;

                    q.add(next);
                    visited.set(next);
                }
            }

            return visited;
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