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
        CCowAndMessage solver = new CCowAndMessage();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCowAndMessage {
        private static final int L = 26;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] sInput = in.next().toCharArray();
            final int n = sInput.length;
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = sInput[i] - 'a';
            }

            long[][] count = new long[L][L];
            int[] freq = new int[L];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < L; j++) {
                    count[j][s[i]] += freq[j];
                }
                freq[s[i]]++;
            }

            long answer = 0;
            for (long[] row : count) {
                for (long x : row) {
                    answer = Math.max(answer, x);
                }
            }
            for (long x : freq) {
                answer = Math.max(answer, x);
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

    }
}