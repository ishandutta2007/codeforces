import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.function.IntUnaryOperator;
import java.util.Deque;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.List;
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
        BSleepyGame solver = new BSleepyGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSleepyGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = 2 * in.nextInt(), m = in.nextInt();
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < adj.length; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < n / 2; i++) {
                int c = in.nextInt();
                for (int j = 0; j < c; j++) {
                    int v = in.nextInt() - 1;

                    adj[2 * i].add(2 * v + 1);
                    adj[2 * i + 1].add(2 * v);
                }
            }

            int start = (in.nextInt() - 1) * 2;

            BitSet visited = new BitSet();
            int[] parent = new int[n];
            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            visited.set(start);
            parent[start] = -1;

            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int next : adj[cur]) {
                    if (visited.get(next))
                        continue;

                    q.add(next);
                    visited.set(next);
                    parent[next] = cur;
                }
            }

            for (int i = 1; i < adj.length; i += 2) {
                if (adj[i].isEmpty() && visited.get(i)) {
                    out.println("Win");

                    Deque<Integer> answer = new ArrayDeque<>();
                    while (i != -1) {
                        answer.addFirst(i / 2 + 1);
                        i = parent[i];
                    }
                    out.println(Util.join(answer));

                    return;
                }
            }

            Pair<Integer, int[]> scc = Graphs.scc(adj);
            int components = scc.first;
            int[] comp = scc.second;
            int[] size = new int[n];
            for (int i = 0; i < n; i++) {
                size[comp[i]]++;
            }
            boolean draw = false;
            for (int i = 0; i < n; i++) {
                if (visited.get(i) && size[comp[i]] > 1) {
                    draw = true;
                    break;
                }
            }

            out.println(draw ? "Draw" : "Lose");
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
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

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