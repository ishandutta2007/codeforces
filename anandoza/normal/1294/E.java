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
        EObtainAPermutation solver = new EObtainAPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class EObtainAPermutation {
        int n;
        int m;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            int[][] cols = new int[m][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cols[j][i] = in.nextInt() - j - 1;
                }
            }

            int answer = 0;
            for (int[] c : cols) {
                answer += f(c);
            }

            out.println(answer);
        }

        private int f(int[] c) {
            int[] count = new int[n];
            for (int i = 0; i < n; i++) {
                int target = target(c[i]);
                if (target == -1)
                    continue;

                int offset = n + i - target;
                if (offset >= n)
                    offset -= n;

                count[offset]++;
            }

            int answer = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int cost = i + n - count[i];
                answer = Math.min(answer, cost);
            }

            return answer;
        }

        private int target(int x) {
            if (x % m != 0)
                return -1;
            int i = x / m;
            if (i >= n || i < 0)
                return -1;
            return i;
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