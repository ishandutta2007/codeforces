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
        DTicketGame solver = new DTicketGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTicketGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            int diff = 0;
            int first = 0, second = 0;
            for (int i = 0; i < n / 2; i++) {
                if (s[i] == '?') {
                    first++;
                } else {
                    diff += s[i] - '0';
                }
            }
            for (int i = n / 2; i < n; i++) {
                if (s[i] == '?') {
                    second++;
                } else {
                    diff -= s[i] - '0';
                }
            }

            boolean answer = canBeMadeEqual(first, second, diff);
            out.println(answer ? "Bicarp" : "Monocarp");
        }

        private boolean canBeMadeEqual(int first, int second, int diff) {
            return diff + 9 * (first - second) / 2 == 0;
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