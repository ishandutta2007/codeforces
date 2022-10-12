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
        EBinarySubsequenceRotation solver = new EBinarySubsequenceRotation();
        solver.solve(1, in, out);
        out.close();
    }

    static class EBinarySubsequenceRotation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] sInput = in.next().toCharArray();
            char[] tInput = in.next().toCharArray();
            Util.ASSERT(sInput.length == tInput.length && tInput.length == n);
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = sInput[i] - '0';
            }
            int[] t = new int[n];
            for (int i = 0; i < n; i++) {
                t[i] = tInput[i] - '0';
            }

            int[] d = new int[n];
            int sum = 0;
            for (int i = 0; i < n; i++) {
                d[i] = t[i] - s[i];
                sum += d[i];
            }

            if (sum != 0) {
                out.println(-1);
                return;
            }

            int pos = 0, neg = 0;

            for (int x : d) {
                if (x == 0)
                    continue;

                if (x > 0) {
                    if (neg == 0)
                        neg++;
                    neg--;
                    pos++;
                } else {
                    if (pos == 0)
                        pos++;
                    pos--;
                    neg++;
                }
            }

            out.println(pos + neg);
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

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }
}