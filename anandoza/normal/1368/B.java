import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BCodeforcesSubsequences solver = new BCodeforcesSubsequences();
        solver.solve(1, in, out);
        out.close();
    }

    static class BCodeforcesSubsequences {
        final char[] codeforces = "codeforces".toCharArray();
        final int L = codeforces.length;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long k = in.nextLong();

            long[] answer = new long[L];
            long count = 1;
            Arrays.fill(answer, 1);

            for (int i = 0; i < L; i = (i + 1) % L) {
                if (count >= k)
                    break;
                count /= answer[i];
                answer[i]++;
                count *= answer[i];
            }

            for (int i = 0; i < L; i++) {
                for (int j = 0; j < answer[i]; j++) {
                    out.print(codeforces[i]);
                }
            }

            out.println();
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}