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
        D2RGBSubstringHardVersion solver = new D2RGBSubstringHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class D2RGBSubstringHardVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++)
                solve(in, out);
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            char[] charS = in.next().toCharArray();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = "RGB".indexOf(charS[i]);
            }

            int answer = Integer.MAX_VALUE;
            for (int offset = 0; offset <= 2; offset++) {
                int[] bad = new int[n + 1];
                for (int i = 0; i < n; i++) {
                    bad[i + 1] = bad[i];
                    if ((s[i] - (i % 3) + 9) % 3 != offset) {
                        bad[i + 1]++;
                    }
                }

                for (int i = 0; i + k <= n; i++) {
                    answer = Math.min(answer, bad[i + k] - bad[i]);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}