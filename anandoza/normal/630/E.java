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
        EARectangle solver = new EARectangle();
        solver.solve(1, in, out);
        out.close();
    }

    static class EARectangle {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long x1 = in.nextLong();
            long y1 = in.nextLong();
            long x2 = in.nextLong();
            long y2 = in.nextLong();
            long x = Math.abs(x1 - x2) + 1;
            long y = Math.abs(y1 - y2);

            long answer = -1;
            if (y % 2 == 0) {
                answer = x * (y / 2);
                answer += (x + 1) / 2;
            } else {
                answer = x * ((y + 1) / 2);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}