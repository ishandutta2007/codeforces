import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        AStringTransformation1 solver = new AStringTransformation1();
        solver.solve(1, in, out);
        out.close();
    }

    static class AStringTransformation1 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] a = in.next().toCharArray();
            char[] b = in.next().toCharArray();

            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    out.println(-1);
                    return;
                }
            }

            final int S = 20;
            TreeSet<Integer>[] adj = new TreeSet[S];
            for (int i = 0; i < S; i++) {
                adj[i] = new TreeSet<>();
            }
            for (int i = 0; i < n; i++) {
                if (a[i] < b[i]) {
                    adj[a[i] - 'a'].add(b[i] - 'a');
                }
            }

            int answer = 0;
            for (int i = 0; i < S; i++) {
                if (adj[i].isEmpty())
                    continue;
                answer++;

                int firstHop = adj[i].pollFirst();
                for (int j : adj[i]) {
                    adj[firstHop].add(j);
                }
            }

            out.println(answer);
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