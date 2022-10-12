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
        ANEKOsMazeGame solver = new ANEKOsMazeGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class ANEKOsMazeGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();

            boolean[][] lava = new boolean[2][n];

            long blockers = 0;
            for (int i = 0; i < q; i++) {
                int r = in.nextInt() - 1, c = in.nextInt() - 1;

                lava[r][c] ^= true;
                int multiplier = lava[r][c] ? 1 : -1;
                int count = 0;
                for (int j = c - 1; j <= c + 1; j++) {
                    if (j < 0 || j >= n)
                        continue;
                    if (lava[1 - r][j])
                        count++;
                }

                blockers += count * multiplier;

                out.println(blockers == 0 ? "Yes" : "No");
            }
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