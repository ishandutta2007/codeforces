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
        AGregAndArray solver = new AGregAndArray();
        solver.solve(1, in, out);
        out.close();
    }

    static class AGregAndArray {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            long[] a = in.readLongArray(n);

            int[] l = new int[m], r = new int[m], d = new int[m];
            for (int i = 0; i < m; i++) {
                l[i] = in.nextInt() - 1;
                r[i] = in.nextInt();
                d[i] = in.nextInt();
            }

            int[] opDiffs = new int[m + 1];
            for (int i = 0; i < k; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt();
                opDiffs[x]++;
                opDiffs[y]--;
            }
            int[] opCounts = Util.cumulativeSumWithoutZero(opDiffs);

            long[] diffs = new long[n + 1];
            for (int i = 0; i < m; i++) {
                long s = (long) d[i] * opCounts[i];
                diffs[l[i]] += s;
                diffs[r[i]] -= s;
            }

            diffs = Util.cumulativeSumWithoutZero(diffs);
            for (int i = 0; i < n; i++) {
                a[i] += diffs[i];
            }

            out.println(Util.join(a));
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

        public static int[] cumulativeSumWithoutZero(int[] x) {
            int[] s = new int[x.length];
            s[0] = x[0];
            for (int i = 1; i < x.length; i++) {
                s[i] = s[i - 1] + x[i];
            }
            return s;
        }

        public static long[] cumulativeSumWithoutZero(long[] x) {
            long[] s = new long[x.length];
            s[0] = x[0];
            for (int i = 1; i < x.length; i++) {
                s[i] = s[i - 1] + x[i];
            }
            return s;
        }

    }
}