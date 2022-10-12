import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.function.DoublePredicate;
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
        ASaveEnergy solver = new ASaveEnergy();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASaveEnergy {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long k = in.nextLong(), d = in.nextLong(), t = in.nextLong();

            long p = d * ((k + d - 1) / d);
            double on = k, off = p - k;

            double answer = BinarySearch.binarySearchDoubleFixedIterations(time -> {
                double full = Math.floor(time / p);
                time -= full * p;
                double onTime = Math.min(on, time);
                double offTime = time - onTime;
                onTime += full * on;
                offTime += full * off;

                double cooked = onTime / t + offTime / (2 * t);
                return cooked >= 1;
            }, 0, 2e18, 100);

            out.println(Util.formatDouble(answer));
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

    static class BinarySearch {
        public static double binarySearchDoubleFixedIterations(DoublePredicate bigEnough, double low, double high, int iterations) {
            double tooSmall = low, tooBig = high;

            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }
            Util.ASSERT(bigEnough.test(tooBig));

            for (int i = 0; i < iterations; i++) {
                double center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.test(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return (tooSmall + tooBig) / 2;
        }

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
        }

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }
}