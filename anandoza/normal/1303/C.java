import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CPerfectKeyboard solver = new CPerfectKeyboard();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPerfectKeyboard {
        private static final int S = 26;
        private static final String NO = "NO";
        private static final String YES = "YES";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            char[] input = in.next().toCharArray();
            final int n = input.length;
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = input[i] - 'a';
            }

            int[][] pieces = new int[S][1];
            for (int i = 0; i < S; i++) {
                pieces[i][0] = i;
            }
            boolean[][] done = new boolean[S][S];
            for (int i = 0; i + 1 < s.length; i++) {
                int a = s[i];
                int b = s[i + 1];
                if (done[a][b])
                    continue;

                if (pieces[a] == null || pieces[b] == null || pieces[a] == pieces[b]) {
                    out.println(NO);
                    return;
                }

                int[] u = pieces[a];
                if (u[0] == a) {
                    Util.reverse(u);
                }
                int[] v = pieces[b];
                if (v[0] != b) {
                    Util.reverse(v);
                }
                pieces[u[0]] = pieces[u[u.length - 1]] = null;
                pieces[v[0]] = pieces[v[v.length - 1]] = null;

                int[] combined = new int[u.length + v.length];
                System.arraycopy(u, 0, combined, 0, u.length);
                System.arraycopy(v, 0, combined, u.length, v.length);

                pieces[combined[0]] = pieces[combined[combined.length - 1]] = combined;

                done[a][b] = done[b][a] = true;
            }

            out.println(YES);
            StringBuilder answer = new StringBuilder();
            for (int i = 0; i < S; i++) {
                if (pieces[i] == null)
                    continue;

                int[] u = pieces[i];
                for (int j : u) {
                    answer.append((char) ('a' + j));
                }
                pieces[u[0]] = pieces[u[u.length - 1]] = null;
            }
            Util.ASSERT(answer.length() == S);
            out.println(answer);
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

    static class Util {
        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(int[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }
}