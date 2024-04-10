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
        DTheMinimalUniqueSubstring solver = new DTheMinimalUniqueSubstring();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTheMinimalUniqueSubstring {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            out.println(solve(n, k));
        }

        private static String solve(int n, int k) {
            int zeros = (n - k) / 2;

            StringBuilder answer = new StringBuilder();
            StringBuilder repeated = new StringBuilder();

            for (int i = 0; i < zeros; i++) {
                repeated.append("0");
            }
            repeated.append("1");

            String r = repeated.toString();

            while (answer.length() < n) {
                answer.append(r);
            }

            return answer.substring(0, n);
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