import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        CPlusesAndMinuses solver = new CPlusesAndMinuses();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPlusesAndMinuses {
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
                s[i] = input[i] == '+' ? 1 : -1;
            }

            int[] min = new int[n + 2];
            Arrays.fill(min, Integer.MAX_VALUE);
            for (int i = 0, sum = 0; i < n; i++) {
                sum += s[i];
                if (sum < 0) {
                    min[-sum] = Math.min(min[-sum], i);
                }
            }

            long answer = 0;
            for (int i = 1; min[i] != Integer.MAX_VALUE; i++) {
                answer += min[i];
                answer++;
            }
            answer += n;

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