import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        FBerlandBeauty solver = new FBerlandBeauty();
        solver.solve(1, in, out);
        out.close();
    }

    static class FBerlandBeauty {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            List<Integer>[] adj = Util.arrayOfLists(n);
            int[] u = new int[n - 1];
            int[] v = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                u[i] = in.nextInt() - 1;
                v[i] = in.nextInt() - 1;
                adj[u[i]].add(v[i]);
                adj[v[i]].add(u[i]);
            }
            LowestCommonAncestor lca = new LowestCommonAncestor(adj, 0);

            int[] answer = new int[n - 1];
            Arrays.fill(answer, 1);
            int m = in.nextInt();
            int[] x = new int[m];
            int[] y = new int[m];
            int[] g = new int[m];
            for (int k = 0; k < m; k++) {
                x[k] = in.nextInt() - 1;
                y[k] = in.nextInt() - 1;
                g[k] = in.nextInt();
            }

            int[][] distance = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    distance[i][j] = distance[j][i] = lca.distance(i, j);
                }
            }

            for (int k = 0; k < m; k++) {
                for (int i = 0; i < n - 1; i++) {
                    if (g[k] > answer[i] && distance[x[k]][y[k]] == distance[x[k]][u[i]] + distance[u[i]][y[k]] && distance[x[k]][y[k]] == distance[x[k]][v[i]] + distance[v[i]][y[k]])
                        answer[i] = g[k];
                }
            }

            for (int k = 0; k < m; k++) {
                int min = Integer.MAX_VALUE;
                for (int i = 0; i < n - 1; i++) {
                    if (answer[i] < min && distance[x[k]][y[k]] == distance[x[k]][u[i]] + distance[u[i]][y[k]] && distance[x[k]][y[k]] == distance[x[k]][v[i]] + distance[v[i]][y[k]])
                        min = answer[i];
                }

                if (min != g[k]) {
                    out.println(-1);
                    return;
                }
            }

            out.println(Util.join(answer));
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

    static class LowestCommonAncestor {
        public final int[] depth;
        public final int[] first;
        public final int[] last;
        public final int[] tour;
        private int tourLength = 0;
        private final IntSparseTable table;

        public LowestCommonAncestor(List<Integer>[] adj, int root) {
            int n = adj.length;
            depth = new int[n];
            first = new int[n];
            last = new int[n];
            tour = new int[n + (n - 1)];

            dfs(root, tour, -1, adj);

            table = new IntSparseTable(this.tour.length, (a, b) -> depth[tour[a]] < depth[tour[b]] ? a : b);
            for (int i = 0; i < table.size; i++) {
                table.update_LAZY(i, i);
            }
            table.rebuild();
        }

        public int lca(int u, int v) {
            u = first[u];
            v = first[v];

            if (u > v) {
                int t = u;
                u = v;
                v = t;
            }
            return tour[table.query(u, v + 1)];
        }

        public int distance(int u, int v) {
            return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        }

        private void dfs(int root, int[] tour, int parent, List<Integer>[] adj) {
            first[root] = last[root] = tourLength;
            tour[tourLength++] = root;
            for (int next : adj[root]) {
                if (next == parent)
                    continue;
                depth[next] = depth[root] + 1;
                dfs(next, tour, root, adj);
                last[root] = tourLength;
                tour[tourLength++] = root;
            }
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

        public static <T> List<T>[] arrayOfLists(int n) {
            List<T>[] array = new List[n];
            for (int i = 0; i < n; i++) {
                array[i] = new ArrayList<>(0);
            }
            return array;
        }

    }

    static class IntSparseTable {
        public final int size;
        public final int[] table;
        private final int maxLength;
        private final IntSparseTable.Combiner combiner;

        public IntSparseTable(int[] array, IntSparseTable.Combiner combiner) {
            this.size = array.length;
            this.combiner = combiner;

            maxLength = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(Math.max(size - 1, 1)));
            table = new int[maxLength * size];
            System.arraycopy(array, 0, table, 0, size);

            rebuild();
        }

        public IntSparseTable(int size, IntSparseTable.Combiner combiner) {
            this.size = size;
            this.combiner = combiner;

            maxLength = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(Math.max(size - 1, 1)));
            table = new int[maxLength * size];
        }

        public void rebuild() {
            for (int l = 0; l + 1 < maxLength; l++) {
                for (int i = 0; i < size; i++) {
                    table[index(l + 1, i)] = table[index(l, i)];
                    if (i + (1 << l) < size) {
                        table[index(l + 1, i)] = combine(table[index(l + 1, i)], table[index(l, i + (1 << l))]);
                    }
                }
            }
        }

        public void update_LAZY(int i, int v) {
            table[i] = v;
        }

        private int index(int length, int start) {
            return length * size + start;
        }

        private int combine(int a, int b) {
            return combiner.combine(a, b);
        }

        public int query(int i, int j) {
            Util.ASSERT(0 <= i && i < j && j <= size);
            int length = j - i - 1;
            int l = length == 0 ? 0 : Integer.numberOfTrailingZeros(Integer.highestOneBit(length));
            int left = table[index(l, i)];
            int right = table[index(l, j - (1 << l))];
            return combine(left, right);
        }

        public interface Combiner {
            int combine(int a, int b);

        }

    }
}