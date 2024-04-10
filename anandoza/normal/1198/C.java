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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CMatchingVsIndependentSet solver = new CMatchingVsIndependentSet();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMatchingVsIndependentSet {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            int[] u = new int[m];
            int[] v = new int[m];
            for (int i = 0; i < m; i++) {
                u[i] = in.nextInt() - 1;
                v[i] = in.nextInt() - 1;
            }

            BitSet visited = new BitSet();
            List<Integer> matching = new ArrayList<>();

            for (int i = 0; i < m; i++) {
                if (visited.get(u[i]) || visited.get(v[i]))
                    continue;

                visited.set(u[i]);
                visited.set(v[i]);
                matching.add(i);

                if (matching.size() == n)
                    break;
            }

            if (matching.size() >= n) {
                out.println("Matching");
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    sb.append(matching.get(i) + 1);
                    sb.append(" ");
                }
                sb.deleteCharAt(sb.length() - 1);
                out.println(sb);
            } else {
                out.println("IndSet");
                StringBuilder sb = new StringBuilder();
                int index = 0;
                for (int i = 0; i < n; i++) {
                    while (visited.get(index))
                        index++;
                    sb.append(index + 1);
                    sb.append(" ");
                    index++;
                }
                sb.deleteCharAt(sb.length() - 1);
                out.println(sb);
            }
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