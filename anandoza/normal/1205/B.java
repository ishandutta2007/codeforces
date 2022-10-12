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
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BShortestCycle solver = new BShortestCycle();
        solver.solve(1, in, out);
        out.close();
    }

    static class BShortestCycle {
        private static final int K = 64;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] input = in.readLongArray(n);

            n = 0;
            for (long x : input) {
                if (x != 0) {
                    n++;
                }
            }
            long[] a = new long[n];
            for (int i = 0, j = 0; i < input.length; i++) {
                if (input[i] != 0) {
                    a[j++] = input[i];
                }
            }

            if (n > K * 2) {
                out.println(3);
                return;
            }

            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        continue;

                    if ((a[i] & a[j]) != 0) {
                        adj[i].add(j);
                    }
                }
            }

            UnionFind uf = new UnionFind(n);
            for (int i = 0; i < n; i++) {
                for (int j : adj[i]) {
                    uf.union(i, j);
                }
            }

            int answer = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int len = findCycleBFS(adj, i);
                if (len != -1)
                    answer = Math.min(answer, len);
            }

            if (answer == Integer.MAX_VALUE)
                answer = -1;

            out.println(answer);
        }

        private static int findCycleBFS(List<Integer>[] adj, int start) {
            final int n = adj.length;
            int[] distance = new int[n];
            int[] parent = new int[n];
            Arrays.fill(distance, -1);
            Arrays.fill(parent, -1);
            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            distance[start] = 0;

            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int next : adj[cur]) {
                    if (distance[next] != -1) {
                        if (next != parent[cur]) {
                            return 1 + distance[next] + distance[cur];
                        }
                        continue;
                    }

                    q.add(next);
                    distance[next] = distance[cur] + 1;
                    parent[next] = cur;
                }
            }

            return -1;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }

    static class UnionFind {
        private int[] __rep;
        private int[] __size;

        public UnionFind(int n) {
            __rep = new int[n];
            __size = new int[n];
            for (int i = 0; i < n; i++) {
                __rep[i] = i;
                __size[i] = 1;
            }
        }

        public int rep(int x) {
            if (__rep[x] == x) {
                return x;
            }

            int r = rep(__rep[x]);
            __rep[x] = r;
            return r;
        }

        public int size(int x) {
            return __size[rep(x)];
        }

        public boolean union(int x, int y) {
            x = rep(x);
            y = rep(y);

            if (x == y) {
                return false;
            }

            if (size(x) < size(y)) {
                int t = x;
                x = y;
                y = t;
            }

            // now size(x) >= size(y)

            __rep[y] = x;
            __size[x] += __size[y];
            return true;
        }

    }
}