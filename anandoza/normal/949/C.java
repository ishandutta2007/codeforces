import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.function.IntUnaryOperator;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CDataCenterMaintenance solver = new CDataCenterMaintenance();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDataCenterMaintenance {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), h = in.nextInt();

            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++)
                adj[i] = new ArrayList<>();

            int[] u = new int[n];

            for (int i = 0; i < n; i++) {
                u[i] = in.nextInt();
            }

            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                if ((u[a] + 1) % h == u[b]) {
                    adj[a].add(b);
                }
                if ((u[b] + 1) % h == u[a]) {
                    adj[b].add(a);
                }
            }

            Pair<Integer, int[]> scc = Graphs.scc(adj);
            int numComponents = scc.first;
            int[] components = scc.second;

            int[] size = new int[n];
            for (int i = 0; i < n; i++) {
                size[components[i]]++;
            }

            boolean[] bad = new boolean[n];

            for (int i = 0; i < n; i++) {
                for (int j : adj[i]) {
                    if (components[j] != components[i])
                        bad[components[i]] = true;
                }
            }

            int best = -1;
            for (int i = 0; i < numComponents; i++) {
                if (bad[i]) {
                    continue;
                }

                if (best == -1 || size[i] < size[best]) {
                    best = i;
                }
            }

            out.println(size[best]);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                if (components[i] == best) {
                    sb.append((i + 1) + " ");
                }
            }
            sb.deleteCharAt(sb.length() - 1);
            out.println(sb);
        }

    }

    static class Graphs {
        public static Pair<Integer, int[]> scc(List<Integer>[] adj) {
            final int n = adj.length;

            int[] components = new int[n];
            Arrays.fill(components, -1);
            int[] index = new int[n];
            Arrays.fill(index, -1);
            int[] stack = new int[n + 1];
            Arrays.fill(stack, -1);

            IntUnaryOperator tarjan = new IntUnaryOperator() {
                public int c = 0, v = 0, top = 0;

                public int applyAsInt(int i) {
                    stack[top++] = i;
                    int low = index[i] = v++;
                    for (int next : adj[i]) {
                        if (index[next] == -1)
                            low = Math.min(low, applyAsInt(next));
                        else if (components[next] == -1)
                            low = Math.min(low, index[next]);
                    }
                    if (low == index[i]) {
                        while (stack[top] != i)
                            components[stack[--top]] = c;
                        c++;
                    }
                    return low;
                }
            };

            for (int i = 0; i < n; i++) {
                if (index[i] == -1) {
                    tarjan.applyAsInt(i);
                }
            }

            return Pair.of(Util.max(components) + 1, components);
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

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }
}