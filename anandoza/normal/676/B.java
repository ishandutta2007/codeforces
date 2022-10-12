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
        BPyramidOfGlasses solver = new BPyramidOfGlasses();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPyramidOfGlasses {
        int n;
        int t;
        int C;
        int[][] glass;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            t = in.nextInt();
            C = 1 << 20;

            glass = new int[n][n];
            for (int i = 0; i < t; i++) {
                pour(0, 0, C);
            }

            int answer = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (glass[i][j] == C)
                        answer++;
                }
            }

            out.println(answer);
        }

        private void pour(int i, int j, int c) {
            if (i >= n)
                return;
            int p = Math.min(C - glass[i][j], c);
            glass[i][j] += p;
            if (c - p > 0) {
                pour(i + 1, j, (c - p) / 2);
                pour(i + 1, j + 1, (c - p) / 2);
            }
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