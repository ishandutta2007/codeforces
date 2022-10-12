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
        BGameGame solver = new BGameGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class BGameGame {
        private static final String WIN = "WIN";
        private static final String LOSE = "LOSE";
        private static final String DRAW = "DRAW";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            for (int bit = 1 << 30; bit > 0; bit >>= 1) {
                int count = 0;
                for (int x : a) {
                    if ((x & bit) > 0)
                        count++;
                }

                if (count % 2 == 0) {
                    // they have to tie on this bit, either both get or both don't get
                    continue;
                }

                if (count % 4 == 1) {
                    out.println(WIN);
                    return;
                }

                if (n % 2 == 0) {
                    out.println(WIN);
                    return;
                }

                out.println(LOSE);
                return;
            }

            out.println(DRAW);
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}