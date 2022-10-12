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
        AKeanuReeves solver = new AKeanuReeves();
        solver.solve(1, in, out);
        out.close();
    }

    static class AKeanuReeves {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();

            int score = 0;
            for (char x : s.toCharArray()) {
                score += x == '0' ? 1 : -1;
            }

            if (score != 0) {
                out.println(1);
                out.println(s);
            } else {
                out.println(2);
                out.println(s.charAt(0) + " " + s.substring(1));
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