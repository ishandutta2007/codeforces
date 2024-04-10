import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.IntPredicate;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.BitSet;
import java.util.Comparator;
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
        E1WeightsDivisionEasyVersion solver = new E1WeightsDivisionEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1WeightsDivisionEasyVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long S = in.nextLong();
            List<Integer>[] adj = Util.arrayOfLists(n);
            int[] u = new int[n - 1];
            int[] v = new int[n - 1];
            int[] w = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                u[i] = in.nextInt() - 1;
                v[i] = in.nextInt() - 1;
                w[i] = in.nextInt();
                adj[u[i]].add(v[i]);
                adj[v[i]].add(u[i]);
            }

            int[] size = Graphs.subtreeLeafCounts(adj, 0);
            int[] depth = Graphs.distanceViaBFS(adj, 0);

            List<Long> scores = new ArrayList<>();
            long tot = 0;
            for (int i = 0; i < n - 1; i++) {
                int sz = depth[u[i]] < depth[v[i]] ? size[v[i]] : size[u[i]];
                tot += (long) w[i] * sz;
                while (w[i] > 0) {
                    scores.add((long) (w[i] + 1) / 2 * sz);
                    w[i] /= 2;
                }
            }
            scores.sort(Comparator.reverseOrder());
            long[] prefix = new long[scores.size() + 1];
            for (int i = 0; i < prefix.length - 1; i++) {
                prefix[i + 1] = prefix[i] + scores.get(i);
            }

            long needed = tot - S;
            int answer = BinarySearch.binarySearch(i -> prefix[i] >= needed, prefix.length);

            out.println(answer);
        }

    }

    static class Util {
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

        public static <T> List<T>[] arrayOfLists(int n) {
            List<T>[] array = new List[n];
            for (int i = 0; i < n; i++) {
                array[i] = new ArrayList<>(0);
            }
            return array;
        }

    }

    static class BinarySearch {
        public static int binarySearch(IntPredicate bigEnough, int passingValue) {
            int tooSmall = 0, tooBig = passingValue;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            if (!bigEnough.test(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.test(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
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

        public long nextLong() {
            return Long.parseLong(next());
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
            int[] stack = new int[n];
            BitSet visited = new BitSet();
            int top = -1;
            visited.set(root);
            stack[++top] = root;

            int index = 0;
            while (top >= 0) {
                int cur = stack[top--];
                preorder[index++] = cur;
                for (int i = adj[cur].size() - 1; i >= 0; i--) {
                    int j = adj[cur].get(i);
                    if (visited.get(j))
                        continue;

                    stack[++top] = j;
                    visited.set(j);
                }
            }

            return preorder;
        }

        public static int[] postorder(List<Integer>[] adj, int root) {
            int[] postorder = preorder(adj, root);
            Util.reverse(postorder);
            return postorder;
        }

        public static int[] subtreeLeafCounts(List<Integer>[] adj, int root) {
            final int n = adj.length;
            int[] size = new int[n];

            int[] postorder = postorder(adj, root);
            for (int i : postorder) {
                for (int j : adj[i]) {
                    size[i] += size[j];
                }
                if (size[i] == 0)
                    size[i]++;
            }

            return size;
        }

    }
}