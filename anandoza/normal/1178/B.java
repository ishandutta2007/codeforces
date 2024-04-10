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
        BWOWFactor solver = new BWOWFactor();
        solver.solve(1, in, out);
        out.close();
    }

    static class BWOWFactor {
        private static final char V = 'v';
        private static final char O = 'o';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            int n = s.length;

            long[] prefix = new long[n + 1]; // prefix[i] = w in s[0,i)
            for (int i = 2; i <= n; i++) {
                prefix[i] = prefix[i - 1];
                if (s[i - 1] == V && s[i - 2] == V) {
                    prefix[i]++;
                }
            }
            long[] suffix = new long[n + 1]; // suffix[i] = w in s[i,n)
            for (int i = n - 2; i >= 0; i--) {
                suffix[i] = suffix[i + 1];
                if (s[i] == V && s[i + 1] == V) {
                    suffix[i]++;
                }
            }

            long answer = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == O) {
                    answer += (prefix[i] * suffix[i]);
                }
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

    }
}