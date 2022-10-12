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
        BHateA solver = new BHateA();
        solver.solve(1, in, out);
        out.close();
    }

    static class BHateA {
        static final String NO = ":(";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.println(solve(in, out));
        }

        private String solve(InputReader in, PrintWriter out) {
            String s = in.next();

            StringBuilder sbWithoutA = new StringBuilder();
            for (char x : s.toCharArray()) {
                if (x != 'a')
                    sbWithoutA.append(x);
            }
            String withoutA = sbWithoutA.toString();

            String first = withoutA.substring(0, withoutA.length() / 2);
            String second = withoutA.substring(withoutA.length() / 2);
            if (!first.equals(second))
                return NO;

            if (!s.endsWith(second))
                return NO;

            return s.substring(0, s.length() - second.length());
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

    }
}