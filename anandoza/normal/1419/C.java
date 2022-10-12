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
        CKilljoy solver = new CKilljoy();
        solver.solve(1, in, out);
        out.close();
    }

    static class CKilljoy {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long x = in.nextLong();
            long[] a = in.readLongArray(n);

            if (Util.min(a) == Util.max(a) && Util.min(a) == x) {
                out.println(0);
                return;
            }

            long diff = 0;
            for (long i : a) {
                if (i == x) {
                    out.println(1);
                    return;
                }
                diff += x - i;
            }
            if (diff == 0) {
                out.println(1);
                return;
            }

            out.println(2);
        }

    }

    static class Util {
        public static long max(long... x) {
            long max = Long.MIN_VALUE;
            for (long i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

        public static long min(long... x) {
            long min = Long.MAX_VALUE;
            for (long i : x) {
                min = Math.min(i, min);
            }
            return min;
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