import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.function.Predicate;
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
        FSpyString solver = new FSpyString();
        solver.solve(1, in, out);
        out.close();
    }

    static class FSpyString {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] s = new char[n][];
            for (int i = 0; i < n; i++) {
                s[i] = in.next().toCharArray();
            }

            Predicate<char[]> verify = ans -> {
                for (char[] r : s) {
                    int count = 0;
                    for (int i = 0; i < m; i++) {
                        if (r[i] != ans[i])
                            count++;
                    }
                    if (count > 1)
                        return false;
                }
                return true;
            };

            char[] ans = new char[m];
            System.arraycopy(s[0], 0, ans, 0, m);
            for (int i = 0; i < m; i++) {
                char t = ans[i];
                for (char x = 'a'; x <= 'z'; x++) {
                    ans[i] = x;
                    if (verify.test(ans)) {
                        out.println(String.valueOf(ans));
                        return;
                    }
                }
                ans[i] = t;
            }

            out.println(-1);
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