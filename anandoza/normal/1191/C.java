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
        CTokitsukazeAndDiscardItems solver = new CTokitsukazeAndDiscardItems();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTokitsukazeAndDiscardItems {
        long n;
        int m;
        long k;
        int deleted;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextLong();
            m = in.nextInt();
            k = in.nextLong();
            deleted = 0;

            long[] discard = new long[m];
            for (int i = 0; i < m; i++) {
                discard[i] = in.nextLong() - 1;
            }

            long answer = 0;
            while (deleted < m) {
                long firstToDelete = discard[deleted];
                long page = page(firstToDelete);
                long lastToDelete = endOfPage(page);
                for (int i = deleted; i < m && discard[i] <= lastToDelete; i++) {
                    deleted++;
                }
                answer++;
            }

            out.println(answer);
        }

        private long page(long index) {
            index -= deleted;
            index /= k;
            return index;
        }

        private long endOfPage(long pageNumber) {
            pageNumber *= k;
            pageNumber += k - 1;
            pageNumber += deleted;
            return pageNumber;
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
}