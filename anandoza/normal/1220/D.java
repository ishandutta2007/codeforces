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
        DAlexAndJulian solver = new DAlexAndJulian();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAlexAndJulian {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] b = in.readLongArray(n);
            int[] count = new int[65];
            for (long x : b) {
                count[Long.numberOfTrailingZeros(x)]++;
            }

            int answer = Integer.MAX_VALUE;
            int bucketToKeep = -1;
            for (int i = 0; i < count.length; i++) {
                int c = count[i];
                if (n - c < answer) {
                    answer = n - c;
                    bucketToKeep = i;
                }
            }

            out.println(answer);
            for (long x : b) {
                if (Long.numberOfTrailingZeros(x) == bucketToKeep)
                    continue;
                out.print(x);
                out.print(" ");
            }
            out.println();
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
}