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
        AAnotherOneBitesTheDust solver = new AAnotherOneBitesTheDust();
        solver.solve(1, in, out);
        out.close();
    }

    static class AAnotherOneBitesTheDust {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long a = in.nextInt(), b = in.nextInt(), c = in.nextInt();

            long answer = c * 2;
            long ab = Math.min(a, b);
            answer += ab * 2;
            a -= ab;
            b -= ab;

            if (a > 0) {
                answer += 1;
            } else if (b > 0) {
                answer += 1;
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
}