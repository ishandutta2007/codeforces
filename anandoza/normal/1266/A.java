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
        ACompetitiveProgrammer solver = new ACompetitiveProgrammer();
        solver.solve(1, in, out);
        out.close();
    }

    static class ACompetitiveProgrammer {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            char[] input = in.next().toCharArray();
            int[] y = new int[input.length];
            for (int i = 0; i < input.length; i++) {
                y[i] = input[i] - '0';
            }

            int zero = 0, even = 0, sum = 0;
            for (int x : y) {
                if (x == 0)
                    zero++;
                if (x % 2 == 0)
                    even++;
                sum += x;
            }

            boolean answer = zero > 0 && even >= 2 && sum % 3 == 0;

            out.println(answer ? "red" : "cyan");
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