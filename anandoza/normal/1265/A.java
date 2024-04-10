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
        ABeautifulString solver = new ABeautifulString();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABeautifulString {
        static final char[] dict = "abc".toCharArray();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            for (int i = 0; i < s.length; i++) {
                if (s[i] != '?')
                    continue;
                for (char x : dict) {
                    if (i - 1 >= 0 && s[i - 1] == x)
                        continue;
                    if (i + 1 < s.length && s[i + 1] == x)
                        continue;
                    s[i] = x;
                    break;
                }
            }

            for (int i = 0; i + 1 < s.length; i++) {
                if (s[i] == s[i + 1]) {
                    out.println(-1);
                    return;
                }
            }
            out.println(String.valueOf(s));
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