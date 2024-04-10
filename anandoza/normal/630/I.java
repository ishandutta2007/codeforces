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
        IParkingLot solver = new IParkingLot();
        solver.solve(1, in, out);
        out.close();
    }

    static class IParkingLot {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long m = 2 * n - 2;
            long answer = 0;

            long mid = Math.max(0, m - n - 1);
            answer += mid * 4 * 3 * 3 * (1L << (2 * Math.max(0, m - n - 2)));

            answer += 4 * 3 * (1L << (2 * (m - n - 1)));
            answer += 4 * 3 * (1L << (2 * (m - n - 1)));

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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}