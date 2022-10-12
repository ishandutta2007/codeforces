import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
        ADistinctDigits solver = new ADistinctDigits();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADistinctDigits {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int l = in.nextInt(), r = in.nextInt();

            for (int i = l; i <= r; i++) {
                if (dist(i)) {
                    out.println(i);
                    return;
                }
            }

            out.println(-1);
        }

        static boolean dist(int i) {
            char[] s = String.valueOf(i).toCharArray();
            HashSet<Character> h = new HashSet<>();
            for (char x : s)
                h.add(x);

            return s.length == h.size();
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