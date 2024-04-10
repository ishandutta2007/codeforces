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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ALongBeautifulInteger solver = new ALongBeautifulInteger();
        solver.solve(1, in, out);
        out.close();
    }

    static class ALongBeautifulInteger {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            char[] input = in.next().toCharArray();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = input[i] - '0';
            }

            String answer = solve(a, k);
            out.println(answer.length());
            out.println(answer);
        }

        private static String solve(int[] a, int k) {
            final int n = a.length;
            int[] answer = new int[n];
            int[] e = new int[k];
            int[] g = new int[k];
            for (int i = 0; i < k; i++) {
                g[i] = a[i];
            }
            for (int i = k - 1; i >= 0; i--) {
                if (g[i] < 9) {
                    g[i]++;
                    break;
                }
                g[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                if (e[i % k] > a[i])
                    break;
                e[i % k] = Math.max(e[i % k], a[i]);
            }

            boolean bump = false;
            for (int i = 0; i < k; i++) {
                if (g[i] != e[i]) {
                    bump = g[i] < e[i];
                    break;
                }
            }
            if (g[0] == 0)
                bump = false;

            if (bump)
                System.arraycopy(g, 0, answer, 0, g.length);
            else
                System.arraycopy(e, 0, answer, 0, g.length);

            for (int i = k; i < n; i++) {
                answer[i] = answer[i % k];
            }

            StringBuilder sb = new StringBuilder();
            for (int x : answer)
                sb.append(x);
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