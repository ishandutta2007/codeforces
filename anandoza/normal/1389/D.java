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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DSegmentIntersections solver = new DSegmentIntersections();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSegmentIntersections {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long kInput = in.nextLong();
            long l1 = in.nextLong(), r1 = in.nextLong();
            long l2 = in.nextLong(), r2 = in.nextLong();

            long l = Math.max(l1, l2), r = Math.min(r1, r2);
            long k = kInput - n * Math.max(r - l, 0);
            if (k <= 0) {
                out.println(0);
                return;
            }

            if (r - l >= 0) {
                long headroom = (Math.max(r1, r2) - Math.min(l1, l2)) - (r - l);
                long answer = k;
                if (k > n * headroom)
                    answer += k - (n * headroom);
                out.println(answer);
                return;
            }

            long gap = Math.abs(r - l);
            long headroom = Math.max(r1, r2) - Math.min(l1, l2);
            LongUnaryOperator score = steps -> {
                if (steps <= gap)
                    return 0;

                long one = steps - gap <= headroom ? steps - gap : headroom + (steps - (gap + headroom)) / 2;

                long full = Math.min(n, steps / (gap + headroom));
                long leftover = steps - full * (gap + headroom);

                long many = full * headroom;

                long extend = full == 0 ? 0 : leftover / 2;
                long next = full == n ? 0 : leftover - gap;

                many += Util.max(0, extend, next);

                // System.out.format("steps = %d, one = %d, many = %d%n", steps, one, many);

                return Math.max(one, many);
            };
            long answer = BinarySearch.binarySearchLong(s -> score.applyAsLong(s) >= k);
            out.println(answer);
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

    }

    static class BinarySearch {
        public static long binarySearchLong(LongPredicate bigEnough) {
            long tooSmall = 0, tooBig;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.test(tooBig); tooBig *= 2)
                ;

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
}