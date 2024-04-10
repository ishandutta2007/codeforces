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
        EVusTheCossackAndAField solver = new EVusTheCossackAndAField();
        solver.solve(1, in, out);
        out.close();
    }

    static class EVusTheCossackAndAField {
        int n;
        int m;
        int[][] sum;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = 2 * in.nextInt();
            m = 2 * in.nextInt();
            int q = in.nextInt();

            int[][] orig = new int[n][m];
            for (int i = 0; i < n / 2; i++) {
                char[] row = in.next().toCharArray();
                for (int j = 0; j < m / 2; j++) {
                    orig[i][j] = orig[i + n / 2][j + m / 2] = row[j] == '1' ? 1 : 0;
                    orig[i + n / 2][j] = orig[i][j + m / 2] = 1 - orig[i][j];
                }
            }

            sum = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + orig[i - 1][j - 1];
                }
            }

            for (int i = 0; i < q; i++) {
                int x1 = in.nextInt() - 1;
                int y1 = in.nextInt() - 1;
                int x2 = in.nextInt();
                int y2 = in.nextInt();

                long answer = f(x2, y2) - f(x1, y2) - f(x2, y1) + f(x1, y1);

                out.println(answer);
            }
        }

        private long f(int x, int y) {
            long a = x / n;
            long b = y / m;
            x -= a * n;
            y -= b * m;

            long simpleArea = a * b * n * m + a * n * y + b * m * x;
            long answer = simpleArea / 2;

            long small = sum[x][y];
            boolean inverted = p(a, b);
            answer += !inverted ? small : (long) x * y - small;

            return answer;
        }

        private static boolean p(long i, long j) {
            return p((int) i) ^ p((int) j);
        }

        private static boolean p(int i) {
            return Integer.bitCount(i) % 2 == 1;
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