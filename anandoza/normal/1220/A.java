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
        ACards solver = new ACards();
        solver.solve(1, in, out);
        out.close();
    }

    static class ACards {
        private static final char A = 'a';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int unused = in.nextInt();
            char[] s = in.next().toCharArray();
            int[] count = new int[26];
            for (char c : s) {
                count[c - A]++;
            }

            int oe = Math.min(count['o' - A], count['e' - A]);
            int zr = Math.min(count['z' - A], count['r' - A]);
            int n = count['n' - A];

            while (oe > 0) {
                if (n > 0) {
                    out.print(1 + " ");
                    n--;
                } else if (zr > 0) {
                    out.print(0 + " ");
                    zr--;
                }
                oe--;
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