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
import java.util.BitSet;
import java.io.BufferedReader;
import java.util.Comparator;
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
        AJohnnyAndContribution solver = new AJohnnyAndContribution();
        solver.solve(1, in, out);
        out.close();
    }

    static class AJohnnyAndContribution {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            List<Integer>[] adj = GraphIO.readUndirectedAdjacencyList(in, n, m);

            int[] t = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                t[i]--;
            }

            Pii[] pairs = new Pii[n];
            for (int i = 0; i < n; i++) {
                pairs[i] = Pii.of(i, t[i]);
            }
            Arrays.sort(pairs, Comparator.comparingInt(p -> p.second));

            boolean[] covered = new boolean[n];
            BitSet processed = new BitSet();
            for (Pii p : pairs) {
                int i = p.first;
                int target = p.second;

                for (int j = 0; j < target; j++) {
                    covered[j] = false;
                }

                for (int j : adj[i]) {
                    if (!processed.get(j))
                        continue;

                    if (t[j] == target) {
                        out.println(-1);
                        return;
                    }

                    covered[t[j]] = true;
                }

                int count = 0;
                for (int j = 0; j < target; j++) {
                    if (covered[j])
                        count++;
                }

                if (count < target) {
                    out.println(-1);
                    return;
                }

                processed.set(i);
            }

            int[] answer = new int[n];
            for (int i = 0; i < n; i++) {
                answer[i] = pairs[i].first + 1;
            }
            out.println(Util.join(answer));
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
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

    static class Pii {
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

    }
}