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
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BIrreducibleAnagrams solver = new BIrreducibleAnagrams();
        solver.solve(1, in, out);
        out.close();
    }

    static class BIrreducibleAnagrams {
        char[] s;
        int[][] prefix;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            s = in.next().toCharArray();
            final int n = s.length;

            prefix = new int[26][n + 1];
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < n; j++) {
                    prefix[i][j + 1] = prefix[i][j] + (s[j] - 'a' == i ? 1 : 0);
                }
            }

            int q = in.nextInt();
            for (int query = 0; query < q; query++) {
                int l = in.nextInt() - 1;
                int r = in.nextInt();
                // half-open [l, r)

                boolean answer = fl(l, r) || len1(l, r) || three(l, r);
                out.println(answer ? "Yes" : "No");
            }
        }

        private boolean three(int l, int r) {
            int count = 0;
            for (int[] p : prefix) {
                if (p[r] - p[l] > 0)
                    count++;
            }
            return count >= 3;
        }

        private boolean len1(int l, int r) {
            return r - l == 1;
        }

        private boolean fl(int l, int r) {
            return s[l] != s[r - 1];
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