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
        BAromasSearch solver = new BAromasSearch();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAromasSearch {
        private static final long CAP = 40_000_000_000_000_000L;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long[] x = new long[100];
            long[] y = new long[100];
            x[0] = in.nextLong();
            y[0] = in.nextLong();
            long ax = in.nextLong();
            long ay = in.nextLong();
            long bx = in.nextLong();
            long by = in.nextLong();

            for (int i = 1; i < x.length; i++) {
                if (x[i - 1] >= CAP)
                    x[i] = CAP;
                else
                    x[i] = ax * x[i - 1] + bx;
                if (y[i - 1] >= CAP)
                    y[i] = CAP;
                else
                    y[i] = ay * y[i - 1] + by;
            }

            long originalXS = in.nextLong(), originalYS = in.nextLong();
            long t = in.nextLong();

            int answer = 0;
            for (int dir : new int[]{-1, 1}) {
                for (int start = 0; start < x.length; start++) {
                    long cost = 0;
                    int count = 0;
                    long xs = originalXS, ys = originalYS;
                    for (int i = start; i < x.length && i >= 0; i += dir) {
                        if (x[i] >= CAP || y[i] >= CAP)
                            break;
                        cost += Math.abs(xs - x[i]) + Math.abs(ys - y[i]);
                        if (cost > t)
                            break;
                        count++;
                        xs = x[i];
                        ys = y[i];
                    }
                    answer = Math.max(answer, count);
                }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}