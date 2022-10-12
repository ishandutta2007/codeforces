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
        EArchaeology solver = new EArchaeology();
        solver.solve(1, in, out);
        out.close();
    }

    static class EArchaeology {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            int n = s.length;

            int numberOfPairs = n / 2;

            StringBuilder answer = new StringBuilder();
            for (int pair = 0; pair < numberOfPairs / 2; pair++) {
                int i = pair * 2;

                find:
                for (int left = i; left <= i + 1; left++) {
                    for (int right = n - 1 - (i); right >= n - 1 - (i + 1); right--) {
                        if (s[left] == s[right]) {
                            answer.append(s[left]);
                            break find;
                        }
                    }
                }

            }

            int firstHalfLength = answer.length();

            if (answer.length() * 2 < n / 2) {
                answer.append(s[(numberOfPairs / 2) * 2]);
            }

            for (int i = firstHalfLength - 1; i >= 0; i--) {
                answer.append(answer.charAt(i));
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