import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.Function;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ASaveTheNature solver = new ASaveTheNature();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASaveTheNature {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Long[] p = new Long[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextLong() / 100;
            }

            Arrays.sort(p, Comparator.reverseOrder());

            long x = in.nextInt();
            long a = in.nextInt();
            long y = in.nextInt();
            long b = in.nextInt();
            if (x < y) {
                long t = x;
                x = y;
                y = t;
                long t2 = a;
                a = b;
                b = t2;
                // now x >= y
            }
            long ab = (((long) a) * b / NumberTheory.gcd(a, b));
            long k = in.nextLong();

            long finalA = a;
            long finalB = b;
            long finalX = x;
            long finalY = y;
            int answer = BinarySearch.binarySearch((numberTickets) -> {
                if (numberTickets > n) {
                    return true;
                }

                int AB = (int) (numberTickets / ab);
                int A = (int) (numberTickets / finalA - AB);
                int B = (int) (numberTickets / finalB - AB);

                int index = 0;
                long total = 0;
                for (int i = 0; i < AB && index < n; i++) {
                    total += p[index++] * (finalX + finalY);
                }
                for (int i = 0; i < A && index < n; i++) {
                    total += p[index++] * (finalX);
                }
                for (int i = 0; i < B && index < n; i++) {
                    total += p[index++] * (finalY);
                }
                return total >= k;
            });

            if (answer > n) {
                answer = -1;
            }

            out.println(answer);
        }

    }

    static class BinarySearch {
        public static int binarySearch(Function<Integer, Boolean> bigEnough) {
            int tooSmall = 0, tooBig;
            if (bigEnough.apply(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.apply(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.apply(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.apply(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
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

    }

    static class NumberTheory {
        public static long gcd(long a, long b) {
            long c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
        }

    }
}