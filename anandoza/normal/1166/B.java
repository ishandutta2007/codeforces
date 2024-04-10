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
        BAllTheVowelsPlease solver = new BAllTheVowelsPlease();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAllTheVowelsPlease {
        static final char[] vowels = "aeiou".toCharArray();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();

            String answer = "-1";
            for (int n = 1; n <= k; n++) {
                if (k % n != 0) {
                    continue;
                }
                if (n < vowels.length || k / n < vowels.length) {
                    continue;
                }

                int m = k / n;
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        sb.append(vowels[(i + j) % vowels.length]);
                    }
                }
                answer = sb.toString();
                break;
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