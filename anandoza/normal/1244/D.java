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
        DPaintTheTree solver = new DPaintTheTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPaintTheTree {
        List<Integer>[] adj;
        long[][] c;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            c = new long[3][];
            for (int i = 0; i < 3; i++)
                c[i] = in.readLongArray(n);

            adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }

            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                adj[a].add(b);
                adj[b].add(a);
            }

            int maxDeg = 0;
            for (int i = 0; i < n; i++) {
                maxDeg = Math.max(maxDeg, adj[i].size());
            }

            if (maxDeg > 2) {
                out.println(-1);
                return;
            }

            int firstNode = -1;
            for (int i = 0; i < n; i++) {
                if (adj[i].size() == 1) {
                    firstNode = i;
                    break;
                }
            }

            List<Integer> vertices = new ArrayList<>();
            int root = firstNode;
            int parent = -1;
            while (vertices.size() < n) {
                vertices.add(root);
                for (int next : adj[root]) {
                    if (next == parent)
                        continue;

                    parent = root;
                    root = next;
                    break;
                }
            }

            long answer = Long.MAX_VALUE;
            int[] colorPerm = new int[3];
            int[] best = null;
            for (colorPerm[0] = 0; colorPerm[0] < 3; colorPerm[0]++) {
                for (colorPerm[1] = 0; colorPerm[1] < 3; colorPerm[1]++) {
                    if (colorPerm[1] == colorPerm[0])
                        continue;
                    colorPerm[2] = 0 + 1 + 2 - colorPerm[0] - colorPerm[1];
                    long score = score(colorPerm, vertices);
                    if (score < answer) {
                        answer = score;
                        best = colorPerm.clone();
                    }
                }
            }

            int[] colors = new int[n];
            for (int i = 0; i < n; i++) {
                colors[vertices.get(i)] = 1 + best[i % 3];
            }

            out.println(answer);
            out.println(Util.join(colors));
        }

        private long score(int[] colorPerm, List<Integer> vertices) {
            long sum = 0;
            for (int i = 0; i < vertices.size(); i++) {
                sum += c[colorPerm[i % 3]][vertices.get(i)];
            }
            return sum;
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
}