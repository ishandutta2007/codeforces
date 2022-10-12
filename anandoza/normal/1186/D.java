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
        DVusTheCossackAndNumbers solver = new DVusTheCossackAndNumbers();
        solver.solve(1, in, out);
        out.close();
    }

    static class DVusTheCossackAndNumbers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            double[] a = in.readDoubleArray(n);

            int[] b = new int[n];
            long sum = 0;
            for (int i = 0; i < n; i++) {
                b[i] = (int) Math.floor(a[i]);
                sum += b[i];
            }

            Util.ASSERT(sum <= 0);

            for (int i = 0; i < n; i++) {
                if (sum == 0)
                    break;

                if (a[i] != (int) a[i]) {
                    b[i]++;
                    sum++;
                }

                Util.ASSERT(Math.abs(a[i] - b[i]) < 1);
            }

            Util.ASSERT(sum == 0);

            for (int x : b)
                out.println(x);
        }

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public double[] readDoubleArray(int n) {
            double[] x = new double[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextDouble();
            }
            return x;
        }

    }
}