import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.function.Function;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CTheRace solver = new CTheRace();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTheRace {
        private static final double TOL = 1e-9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            // alpha is >= 1
            Function<Double, Boolean> tooBig = (alpha) -> {
                double gas = alpha;
                int currentStation = 0;
                int index = 0;
                while (index < n) {
                    int skip = (int) gas;
                    gas -= skip;
                    currentStation += skip;
                    if (currentStation < a[index]) {
                        return false;
                    } else if (currentStation > a[index]) {
                        return true;
                    } else {
                        index++;
                        gas += alpha;
                    }
                }
                return false;
            };
            Function<Double, Boolean> tooSmall = (alpha) -> {
                double gas = alpha;
                int currentStation = 0;
                int index = 0;
                while (index < n) {
                    int skip = (int) gas;
                    gas -= skip;
                    currentStation += skip;
                    if (currentStation < a[index]) {
                        return false;
                    } else if (currentStation > a[index]) {
                        return true;
                    } else {
                        index++;
                        gas += alpha;
                    }
                }
                return true;
            };

            double low = BinarySearch.binarySearchDouble(tooSmall, 1, 1.5e6, TOL) + TOL;
            double high = BinarySearch.binarySearchDouble(tooBig, 1, 1.5e6, TOL) - TOL;

            int next = simulate(low, n);
            int next2 = simulate(high, n);

            if (next == next2) {
                out.println("unique");
                out.println(next);
            } else {
                out.println("not unique");
            }
        }

        private int simulate(double alpha, int n) {
            double gas = alpha;
            int currentStation = 0;
            int index = 0;
            while (index <= n) {
                int skip = (int) gas;
                gas -= skip;
                currentStation += skip;
                index++;
                gas += alpha;
            }
            return currentStation;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }

    static class BinarySearch {
        public static double binarySearchDouble(Function<Double, Boolean> bigEnough, double low, double high, double tolerance) {
            double tooSmall = low, tooBig = high;

            if (bigEnough.apply(tooSmall)) {
                return tooSmall;
            }
            Util.ASSERT(bigEnough.apply(tooBig));

            while (tooBig - tooSmall > tolerance) {
                double center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.apply(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return (tooSmall + tooBig) / 2;
        }

    }
}