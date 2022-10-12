import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.LongUnaryOperator;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.function.LongPredicate;
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
        ERestorerDistance solver = new ERestorerDistance();
        solver.solve(1, in, out);
        out.close();
    }

    static class ERestorerDistance {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long a = in.nextInt(), r = in.nextInt(), initialM = in.nextInt();
            long m = Math.min(initialM, a + r);
            long[] h = in.readLongArray(n);

            LongUnaryOperator cost = target -> {
                long add = 0, remove = 0;
                for (long x : h) {
                    if (x < target) {
                        add += target - x;
                    } else {
                        remove += x - target;
                    }
                }

                long move = Math.min(add, remove);
                add -= move;
                remove -= move;

                return move * m + add * a + remove * r;
            };

            long optH = BinarySearch.binarySearchLong(t -> cost.applyAsLong(t + 1) - cost.applyAsLong(t) >= 0, Util.max(h));
            out.println(cost.applyAsLong(optH));
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

    static class BinarySearch {
        public static long binarySearchLong(LongPredicate bigEnough, long passingValue) {
            long tooSmall = 0, tooBig = passingValue;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            if (!bigEnough.test(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                long center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.test(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
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

        private Util() {
        }

    }
}