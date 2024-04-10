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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ABalancedBitstring solver = new ABalancedBitstring();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABalancedBitstring {
        private static final char Q = '?';
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            char[] s = in.next().toCharArray();

            char[] canonical = new char[k];
            for (int i = 0; i < k; i++) {
                canonical[i] = Q;
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == Q)
                    continue;
                if (canonical[i % k] == Q) {
                    canonical[i % k] = s[i];
                    continue;
                }
                if (canonical[i % k] != s[i]) {
                    out.println(NO);
                    return;
                }
            }

            int ones = 0, zeros = 0;
            for (int i = 0; i < k; i++) {
                if (canonical[i] != Q) {
                    if (canonical[i] == '1')
                        ones++;
                    if (canonical[i] == '0')
                        zeros++;
                }
            }

            if (ones > k / 2 || zeros > k / 2) {
                out.println(NO);
                return;
            }

            out.println(YES);
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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