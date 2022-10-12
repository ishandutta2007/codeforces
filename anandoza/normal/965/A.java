import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.function.LongPredicate;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        APaperAirplanes solver = new APaperAirplanes();
        solver.solve(1, in, out);
        out.close();
    }

    static class APaperAirplanes {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long k = in.nextLong();
            long n = in.nextLong();
            long s = in.nextLong();
            long p = in.nextLong();

            LongPredicate good = packs -> {
                long sheets = packs * p;
                long sheetsPerPerson = sheets / k;
                long planes = sheetsPerPerson * s;
                return planes >= n;
            };

            long answer = BinarySearch.binarySearchLong(good::test);
            out.println(answer);
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