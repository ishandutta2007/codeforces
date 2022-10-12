import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BEmotes solver = new BEmotes();
        solver.solve(1, in, out);
        out.close();
    }

    static class BEmotes {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long m = in.nextLong(), k = in.nextLong();
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
            }

            Arrays.sort(a);
            long biggest = a[n - 1];
            long second = a[n - 2];

            long spacers = m / (k + 1);
            long answer = spacers * second + (m - spacers) * biggest;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}