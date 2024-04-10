import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.function.IntBinaryOperator;
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
        EOmkarAndLastFloor solver = new EOmkarAndLastFloor();
        solver.solve(1, in, out);
        out.close();
    }

    static class EOmkarAndLastFloor {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[][] count = new int[m + 1][m + 1];
            for (int i = 0; i < n; i++) {
                int k = in.nextInt();
                for (int j = 0; j < k; j++) {
                    int l = in.nextInt() - 1;
                    int r = in.nextInt();

                    count[l][r]++;
                }
            }

            IntBinaryOperator f = new IntBinaryOperator() {
                int[][] cache = new int[m + 1][m + 1];
                boolean[][] computed = new boolean[m + 1][m + 1];

                public int applyAsInt(int l, int r) {
                    if (r <= l)
                        return 0;

                    if (computed[l][r])
                        return cache[l][r];

                    int w = r - l;
                    int[] diff = new int[w + 1];
                    for (int i = l; i <= r; i++) {
                        for (int j = i; j <= r; j++) {
                            diff[i - l] += count[i][j];
                            diff[j - l] -= count[i][j];
                        }
                    }
                    int[] score = new int[w];
                    score[0] = diff[0];
                    for (int i = 1; i < w; i++) {
                        score[i] = score[i - 1] + diff[i];
                    }

                    int max = 0;
                    for (int i = l; i < r; i++) {
                        int left = applyAsInt(l, i);
                        int right = applyAsInt(i + 1, r);
                        max = Math.max(max, left + right + score[i - l] * score[i - l]);
                    }

                    cache[l][r] = max;
                    computed[l][r] = true;
                    return max;
                }
            };

            out.println(f.applyAsInt(0, m));
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