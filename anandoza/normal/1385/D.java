import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        DAGoodString solver = new DAGoodString();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAGoodString {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(); // power of 2
            char[] input = in.next().toCharArray();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = input[i] - 'a';
            }

            int answer = f(s, 0, n, 0);

            out.println(answer);
        }

        private int f(int[] s, int l, int r, int k) {
            if (r - l == 1) {
                return s[l] == k ? 0 : 1;
            }

            int ans = Integer.MAX_VALUE;
            int m = l + (r - l) / 2;

            {
                int cost = 0;
                for (int i = l; i < m; i++) {
                    if (s[i] != k)
                        cost++;
                }
                cost += f(s, m, r, k + 1);
                ans = Math.min(ans, cost);
            }

            {
                int cost = 0;
                for (int i = m; i < r; i++) {
                    if (s[i] != k)
                        cost++;
                }
                cost += f(s, l, m, k + 1);
                ans = Math.min(ans, cost);
            }

            return ans;
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