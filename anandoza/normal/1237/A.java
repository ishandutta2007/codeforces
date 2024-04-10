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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ABalancedRatingChanges solver = new ABalancedRatingChanges();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABalancedRatingChanges {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            int odd = 0;
            for (int x : a) {
                if (x % 2 != 0) {
                    odd++;
                }
            }

            int[] b = new int[n];
            int oddSoFar = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0) {
                    b[i] = a[i] / 2;
                } else {
                    if (oddSoFar < odd / 2) {
                        b[i] = Math.floorDiv(a[i], 2);
                    } else {
                        b[i] = Math.floorDiv(a[i], 2) + 1;
                    }
                    oddSoFar++;
                }
            }

            int sum = 0;
            for (int x : b) {
                sum += x;
            }
            Util.ASSERT(sum == 0);

            for (int x : b) {
                out.println(x);
            }
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
}