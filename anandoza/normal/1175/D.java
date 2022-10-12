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
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DArraySplitting solver = new DArraySplitting();
        solver.solve(1, in, out);
        out.close();
    }

    static class DArraySplitting {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            long[] suffixes = new long[n];
            suffixes[n - 1] = a[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                suffixes[i] = suffixes[i + 1] + a[i];
            }

            long answer = suffixes[0];
            suffixes[0] = Long.MIN_VALUE;

            Util.safeSort(suffixes);

            for (int i = 0; i < k - 1; i++) {
                answer += suffixes[n - 1 - i];
            }

            out.println(answer);
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

    static class Util {
        public static void safeSort(long[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(long[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(long[] x, int i, int j) {
            long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

    }
}