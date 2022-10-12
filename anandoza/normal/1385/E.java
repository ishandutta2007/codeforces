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
        EDirectingEdges solver = new EDirectingEdges();
        solver.solve(1, in, out);
        out.close();
    }

    static class EDirectingEdges {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            List<Integer>[] adj = new List[n];
            List<Pii> undirected = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                int t = in.nextInt();
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                if (t == 0) {
                    undirected.add(Pii.of(u, v));
                } else {
                    adj[u].add(v);
                }
            }

            int[] topo = Graphs.topologicalSort(adj);
            if (topo.length < n) {
                out.println("NO");
                return;
            }

            out.println("YES");
            for (int i = 0; i < adj.length; i++) {
                for (int j : adj[i]) {
                    out.println(Util.join(i + 1, j + 1));
                }
            }

            int[] index = Permutations.inverse(topo);
            for (Pii p : undirected) {
                int u = p.first, v = p.second;
                if (index[u] > index[v]) {
                    int t = u;
                    u = v;
                    v = t;
                }

                out.println(Util.join(u + 1, v + 1));
            }
        }

    }

    static class Pii implements Comparable<Pii> {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pii o) {
            if (first != o.first)
                return Integer.compare(first, o.first);
            return Integer.compare(second, o.second);
        }

    }

    static class Permutations {
        public static int[] inverse(int[] permutation) {
            int n = permutation.length;
            int[] inverse = new int[n];
            for (int i = 0; i < n; i++) {
                inverse[permutation[i]] = i;
            }
            return inverse;
        }

        private Permutations() {
        }

    }

    static class Graphs {
        public static int[] topologicalSort(List<Integer>[] adj) {
            final int n = adj.length;
            int[] inDegree = new int[n];
            int[] answer = new int[n];
            int size = 0;

            for (int i = 0; i < n; i++) {
                for (int j : adj[i])
                    inDegree[j]++;
            }

            for (int i = 0; i < n; i++) {
                if (inDegree[i] == 0)
                    answer[size++] = i;
            }

            int q = 0;
            while (q < size) {
                int cur = answer[q++];
                for (int next : adj[cur]) {
                    if (--inDegree[next] == 0)
                        answer[size++] = next;
                }
            }

            if (size < answer.length)
                return Arrays.copyOf(answer, size);

            return answer;
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
}