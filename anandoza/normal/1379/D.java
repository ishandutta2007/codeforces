import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        DNewPassengerTrams solver = new DNewPassengerTrams();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNewPassengerTrams {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            in.nextInt(); // unused
            int m = in.nextInt();
            int k = in.nextInt();

            int[] a = new int[2 * n + 1];
            int[] input = new int[n];
            for (int i = 0; i < n; i++) {
                in.next(); // unused
                a[i] = in.nextInt() % (m / 2);
                a[i + n] = a[i] + m / 2;
                input[i] = a[i];
            }
            a[2 * n] = Integer.MAX_VALUE;
            Util.safeSort(a);

            int score = Integer.MAX_VALUE;
            int start = 0;
            for (int i = 0, j = 0; i < n && a[i] < m / 2; i++) {
                while (a[j] < a[i] + k)
                    j++;

                if (j - i - 1 < score) {
                    score = j - i - 1;
                    start = i;
                }
            }

            int t = a[start] + k;
            t %= (m / 2);

            out.println(Util.join(score, t));
            for (int i = 0; i < n; i++) {
                if (t - k < input[i] && input[i] < t)
                    out.print((i + 1) + " ");
                if (t - k < input[i] - m / 2 && input[i] - m / 2 < t)
                    out.print((i + 1) + " ");
            }
            out.println();
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

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

    }
}