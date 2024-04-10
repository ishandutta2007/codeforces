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
        BBeautifulNumbers solver = new BBeautifulNumbers();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBeautifulNumbers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++)
                p[i]--;

            p = Permutations.inverse(p);

            int left = -1;
            int right = n;
            boolean[] answer = new boolean[n];
            for (int i = n - 1; i >= 0; i--) {
                int count = n - (right - left - 1);
                answer[i] = count == n - 1 - i;

                if (p[i] < p[0])
                    left = Math.max(left, p[i]);
                else
                    right = Math.min(right, p[i]);
            }

            StringBuilder sb = new StringBuilder();
            for (boolean b : answer)
                sb.append(b ? 1 : 0);
            out.println(sb);
        }

    }

    static class Permutations {
        public static int[] inverse(int[] permutation) {
            int n = permutation.length;
            int[] inverse = new int[n];
            for (int i = 0; i < n; i++) {
                inverse[permutation[i]] = i;
            }
            return inverse;
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
}