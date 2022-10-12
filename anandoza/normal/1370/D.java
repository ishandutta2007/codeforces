import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.function.IntBinaryOperator;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.function.IntPredicate;
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
        DOddEvenSubsequence solver = new DOddEvenSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class DOddEvenSubsequence {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            int[] a = in.readIntArray(n);

            IntBinaryOperator countWithThreshold = (maximum, startIndex) -> {
                int count = startIndex;
                for (int i = startIndex; i < n; i++) {
                    if (a[i] <= maximum) {
                        count++;
                        if (i + 1 < n)
                            count++;
                        i++;
                    }
                }
                return count;
            };

            int oddMax = BinarySearch.binarySearch(maximum -> countWithThreshold.applyAsInt(maximum, 0) >= k);
            int evenMax = BinarySearch.binarySearch(maximum -> countWithThreshold.applyAsInt(maximum, 1) >= k);

            out.println(Math.min(oddMax, evenMax));
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

    static class BinarySearch {
        public static int binarySearch(IntPredicate bigEnough) {
            int tooSmall = 0, tooBig;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.test(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.test(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
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