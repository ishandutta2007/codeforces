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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DOmkarAndBedWars solver = new DOmkarAndBedWars();
        solver.solve(1, in, out);
        out.close();
    }

    static class DOmkarAndBedWars {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] input = in.next().toCharArray();

            char[] s = null;
            for (int i = 0; i + 1 < n; i++) {
                if (input[i] != input[i + 1]) {
                    s = new char[n];
                    System.arraycopy(input, i + 1, s, 0, n - (i + 1));
                    System.arraycopy(input, 0, s, n - (i + 1), i + 1);
                    break;
                }
            }
            if (s == null) {
                out.println(1 + (n - 1) / 3);
                return;
            }

            int answer = 0;
            for (int i = 0, j = 0; i < n; i = j) {
                while (j < n && s[i] == s[j])
                    j++;

                answer += (j - i) / 3;
            }
            out.println(answer);
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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