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
        CStackOfPresents solver = new CStackOfPresents();
        solver.solve(1, in, out);
        out.close();
    }

    static class CStackOfPresents {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] a = in.readIntArray(n);
            for (int i = 0; i < n; i++)
                a[i]--;
            int[] b = in.readIntArray(m);
            for (int i = 0; i < m; i++)
                b[i]--;
            int[] aInv = Permutations.inverse(a);
            for (int i = 0; i < m; i++) {
                b[i] = aInv[b[i]];
            }

            long cost = 0;
            int maxIndexRemoved = -1;

            for (int i = 0; i < m; i++) {
                int k = b[i] <= maxIndexRemoved ? 0 : b[i] - i;
                maxIndexRemoved = Math.max(maxIndexRemoved, b[i]);
                cost += 2 * k + 1;
            }

            out.println(cost);
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