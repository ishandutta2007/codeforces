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
        BSubsequenceHate solver = new BSubsequenceHate();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSubsequenceHate {
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
                s[i] = input[i] - '0';
            }

            int[] prefix = new int[n + 1];
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + s[i];
            }

            int answer = Integer.MAX_VALUE;
            for (int i = 0; i <= n; i++) {
                int zerosBefore = i - prefix[i];
                int onesAfter = prefix[n] - prefix[i];
                int cost = zerosBefore + onesAfter;
                answer = Math.min(answer, cost);
            }
            for (int i = 0; i < prefix.length; i++) {
                prefix[i] = i - prefix[i];
            }
            for (int i = 0; i <= n; i++) {
                int zerosBefore = i - prefix[i];
                int onesAfter = prefix[n] - prefix[i];
                int cost = zerosBefore + onesAfter;
                answer = Math.min(answer, cost);
            }
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
}