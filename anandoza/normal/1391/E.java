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
import java.util.function.IntSupplier;
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
        EPairsOfPairs solver = new EPairsOfPairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPairsOfPairs {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            final int target = (n + 1) / 2;
            List<Integer>[] adj = GraphIO.readUndirectedAdjacencyList(in, n, m);

            EPairsOfPairs.DFSTree tree = new EPairsOfPairs.DFSTree(adj, 0);

            for (int i = 0; i < n; i++) {
                if (tree.depth[i] + 1 >= target) {
                    out.println("PATH");
                    out.println(target);
                    for (int j = 0; j < target; j++) {
                        out.print((i + 1) + " ");
                        i = tree.parent[i];
                    }
                    out.println();
                    return;
                }
            }

            int[] degree = new int[n];
            Queue<Integer> leaves = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                degree[i] = tree.children[i].size();
                if (degree[i] == 0)
                    leaves.add(i);
            }

            IntSupplier remove = () -> {
                int c = leaves.poll();
                int p = tree.parent[c];
                if (p != c && --degree[p] == 0) {
                    leaves.add(p);
                }
                return c;
            };

            IntStack paired = new IntStack();
            while (!leaves.isEmpty()) {
                if (leaves.size() <= 1)
                    break;

                paired.push(remove.getAsInt());
                paired.push(remove.getAsInt());

                if (paired.size() >= target)
                    break;
            }

            out.println("PAIRING");
            out.println(paired.size() / 2);
            for (int i = 0; i < paired.size(); i += 2) {
                out.println(Util.join(paired.get(i) + 1, paired.get(i + 1) + 1));
            }
        }

        private static class DFSTree {
            public final int n;
            public final int root;
            public final int[] parent;
            public final int[] depth;
            public final List<Integer>[] children;
            public final List<Integer>[] adj;

            public DFSTree(List<Integer>[] adj, int root) {
                n = adj.length;
                this.adj = adj;
                this.root = root;
                parent = new int[n];
                Arrays.fill(parent, -1);
                depth = new int[n];
                children = Util.arrayOfLists(n);

                parent[root] = root;
                dfs(root);
            }

            private void dfs(int cur) {
                for (int next : adj[cur]) {
                    if (parent[next] != -1)
                        continue;

                    parent[next] = cur;
                    depth[next] = depth[cur] + 1;
                    children[cur].add(next);
                    dfs(next);
                }
            }

        }

    }

    static class IntStack {
        int[] array;
        int size = 0;

        public IntStack() {
            this(8);
        }

        public IntStack(int capacity) {
            array = new int[capacity];
        }

        public void push(int item) {
            if (size >= array.length)
                array = resize(array);
            array[size++] = item;
        }

        public int size() {
            return size;
        }

        public int get(int i) {
            Util.ASSERT(i < size);
            return array[i];
        }

        private static int[] resize(int[] array) {
            int[] newArray = new int[array.length << 1];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        public String toString() {
            int[] trimmed = new int[size];
            System.arraycopy(array, 0, trimmed, 0, size);
            return Arrays.toString(trimmed);
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
}