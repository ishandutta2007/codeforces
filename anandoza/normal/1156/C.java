import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.function.Function;
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
        CMatchPoints solver = new CMatchPoints();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMatchPoints {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int z = in.nextInt();
            Integer[] x = new Integer[n];
            for (int i = 0; i < n; i++)
                x[i] = in.nextInt();
            Arrays.sort(x);

            int answer = 0;
            int lastUsed = n / 2 - 1;
            for (int i = 0; i < n / 2; i++) {
                int finalI = i;
                int finalLastUsed = lastUsed;
                int nextUsed = BinarySearch.binarySearch(index -> index >= n || (index > finalLastUsed && x[index] - x[finalI] >= z));
                if (nextUsed < n) {
                    answer++;
                    lastUsed = nextUsed;
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

        public int nextInt() {
            return Integer.parseInt(next());
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
                int center = (tooBig + tooSmall) / 2;
                if (!bigEnough.apply(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
        }

    }
}