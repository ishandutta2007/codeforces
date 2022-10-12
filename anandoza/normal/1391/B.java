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
        BFixYou solver = new BFixYou();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFixYou {
        private static final char R = 'R';
        private static final char D = 'D';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] grid = new char[n][];
            for (int i = 0; i < n; i++) {
                grid[i] = in.next().toCharArray();
            }

            int answer = 0;
            for (int i = 0; i < n - 1; i++) {
                if (grid[i][m - 1] == R)
                    answer++;
            }
            for (int j = 0; j < m - 1; j++) {
                if (grid[n - 1][j] == D)
                    answer++;
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