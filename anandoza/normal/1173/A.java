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
        ANauuoAndVotes solver = new ANauuoAndVotes();
        solver.solve(1, in, out);
        out.close();
    }

    static class ANauuoAndVotes {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int up = in.nextInt();
            int down = in.nextInt();
            int unknown = in.nextInt();

            int high = up - down + unknown;
            int low = up - down - unknown;
            if (Integer.compare(high, 0) == Integer.compare(low, 0)) {
                out.println(high > 0 ? '+' : high < 0 ? '-' : '0');
            } else {
                out.println("?");
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

    }
}