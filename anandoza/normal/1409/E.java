import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.Random;
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
        ETwoPlatforms solver = new ETwoPlatforms();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETwoPlatforms {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] x = in.readIntArray(n);
            in.readIntArray(n); // unused y
            Util.safeSort(x);

            int[] right = new int[n + 1];
            right[n] = 0;
            for (int i = n - 1, j = n - 1; i >= 0; i--) {
                while (x[j] > x[i] + k)
                    j--;

                int saved = j - i + 1;
                right[i] = Math.max(right[i + 1], saved);
            }
            // System.out.println("right = " + Arrays.toString(right));

            int answer = right[0];
            for (int i = 0, j = 0; i + 1 < n; i++) {
                while (x[j] < x[i] - k)
                    j++;

                int saved = i - j + 1;
                answer = Math.max(answer, saved + right[i + 1]);
                // System.out.println("saved = " + saved);
                // System.out.println("right[i+1] = " + right[i + 1]);
                // System.out.println();
            }

            out.println(answer);
        }

    }

    static class Util {
        public static void safeSort(int[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(int[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        private Util() {
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