import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        BFillingTheGrid solver = new BFillingTheGrid();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFillingTheGrid {
        static final int W = 1;
        static final int B = 2;
        int[][] grid;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt(), w = in.nextInt();

            int[] r = in.readIntArray(h);
            int[] c = in.readIntArray(w);

            grid = new int[h][w];
            boolean valid = true;
            for (int i = 0; i < r.length; i++) {
                for (int j = 0; j < r[i]; j++) {
                    valid &= set(i, j, B);
                }
                if (r[i] < w) {
                    valid &= set(i, r[i], W);
                }
            }
            for (int i = 0; i < c.length; i++) {
                for (int j = 0; j < c[i]; j++) {
                    valid &= set(j, i, B);
                }
                if (c[i] < h) {
                    valid &= set(c[i], i, W);
                }
            }

            if (!valid) {
                out.println(0);
            } else {
                NumberTheory.Mod107 m = new NumberTheory.Mod107();
                long answer = 1;
                for (int[] row : grid) {
                    for (int cell : row) {
                        if (cell == 0) {
                            answer = m.mult(answer, 2);
                        }
                    }
                }

                out.println(answer);
            }
        }

        private boolean set(int i, int j, int value) {
            if (grid[i][j] != 0 && grid[i][j] != value) {
                return false;
            }

            grid[i][j] = value;
            return true;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class NumberTheory {
        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            ArrayList<Long> factorial = new ArrayList<>();
            ArrayList<Long> invFactorial = new ArrayList<>();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.add(1L);
                invFactorial.add(1L);
            }

            public long normalize(long x) {
                x %= modulus();
                if (x < 0)
                    x += modulus();
                return x;
            }

            public long mult(long a, long b) {
                return normalize(a * b);
            }

        }

        public static class Mod107 extends NumberTheory.Modulus<NumberTheory.Mod107> {
            public long modulus() {
                return 1_000_000_007L;
            }

        }

    }
}