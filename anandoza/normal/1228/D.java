import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DCompleteTripartite solver = new DCompleteTripartite();
        solver.solve(1, in, out);
        out.close();
    }

    static class DCompleteTripartite {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[] component = new int[n]; // 0 = unassigned; 1,2,3 = assigned

            Set<Integer>[] adj = new Set[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new HashSet<>();
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                adj[a].add(b);
                adj[b].add(a);
            }

            for (int currentComponent = 1; currentComponent <= 3; currentComponent++) {
                for (int i = 0; i < n; i++) {
                    if (component[i] == 0) {
                        component[i] = currentComponent;
                        for (int j = 0; j < n; j++) {
                            if (j == i)
                                continue;
                            if (!adj[i].contains(j)) {
                                if (component[j] == 0) {
                                    component[j] = currentComponent;
                                } else {
                                    out.println(-1);
                                    return;
                                }
                            }
                        }

                        break;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j : adj[i]) {
                    if (component[i] == component[j]) {
                        out.println(-1);
                        return;
                    }
                }
            }

            int[] count = new int[4];
            for (int x : component) {
                count[x]++;
            }

            if (count[1] == 0 || count[2] == 0 || count[3] == 0) {
                out.println(-1);
                return;
            }

            if (count[0] != 0) {
                out.println(-1);
                return;
            }

            long totalEdges = count[1] * count[2] + count[2] * count[3] + count[3] * count[1];
            if (totalEdges != m) {
                out.println(-1);
                return;
            }

            out.println(Util.join(component));
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