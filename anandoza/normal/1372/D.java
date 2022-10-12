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
        DOmkarAndCircle solver = new DOmkarAndCircle();
        solver.solve(1, in, out);
        out.close();
    }

    static class DOmkarAndCircle {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.readLongArray(n);

            if (n == 1) {
                out.println(a[0]);
                return;
            }

            long[] prefix = new long[n + 2];
            long[] suffix = new long[n + 2];
            for (int i = 0; i < n; i++) {
                prefix[i + 2] = a[i] + prefix[i];
            }
            Util.reverse(a);
            for (int i = 0; i < n; i++) {
                suffix[i + 2] = a[i] + suffix[i];
            }
            Util.reverse(suffix);

            long answer = 0;
            for (int i = 1; i < prefix.length; i++) {
                answer = Math.max(answer, prefix[i] + suffix[i - 1]);
            }

            out.println(answer);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }

    static class Util {
        public static void swap(long[] x, int i, int j) {
            long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(long[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        private Util() {
        }

    }
}