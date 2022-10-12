import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.BitSet;
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
        ESkiAccidents solver = new ESkiAccidents();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESkiAccidents {
        private static final boolean DEBUG = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            List<Integer>[] adj = GraphIO.readDirectedAdjacencyList(in, n, m);

            BitSet one = new BitSet();
            BitSet two = new BitSet();

            List<Integer> answer = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (two.get(i)) {
                    answer.add(i + 1);
                    continue;
                }

                for (int next : adj[i]) {
                    one.set(next);
                    if (one.get(i))
                        two.set(next);
                }
            }

            if (DEBUG) {
                one.clear();
                two.clear();
                for (int i = 0; i < n; i++) {
                    if (answer.contains(i + 1))
                        continue;
                    if (two.get(i)) {
                        Util.ASSERT(false);
                    }

                    for (int next : adj[i]) {
                        one.set(next);
                        if (one.get(i))
                            two.set(next);
                    }
                }
            }

            out.println(answer.size());
            out.println(Util.join(answer));
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }

    static class GraphIO {
        public static List<Integer>[] readDirectedAdjacencyList(InputReader in, int n, int m) {
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                adj[u].add(v);
            }
            return adj;
        }

        private GraphIO() {
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
}