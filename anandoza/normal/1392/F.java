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
        FOmkarAndLandslide solver = new FOmkarAndLandslide();
        solver.solve(1, in, out);
        out.close();
    }

    static class FOmkarAndLandslide {
        int n;
        long[] h;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            h = in.readLongArray(n);
            for (int i = 0; i < n; i++) {
                h[i] -= i;
            }

            long sum = 0;
            long count = n;
            for (int k = 0; k < n; k++) {
                sum += h[k];
            }
            long small = sum / count;
            long big = small + 1;
            long bigCount = sum - count * small;
            for (int k = 0; k < n; k++) {
                if (bigCount > 0) {
                    h[k] = big;
                    bigCount--;
                } else {
                    h[k] = small;
                }
            }

            for (int i = 0; i < n; i++) {
                h[i] += i;
            }
            out.println(Util.join(h));
        }

    }

    static class Util {
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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
}