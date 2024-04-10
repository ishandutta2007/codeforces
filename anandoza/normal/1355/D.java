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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DGameWithArray solver = new DGameWithArray();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGameWithArray {
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), s = in.nextInt();

            if (s - (n - 1) > n) {
                int k = n;
                out.println(YES);
                for (int i = 0; i < n - 1; i++) {
                    out.print("1 ");
                }
                out.println(s - (n - 1));
                out.println(k);
                return;
            }

            out.println(NO);
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