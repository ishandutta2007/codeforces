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
        AAcaciusAndString solver = new AAcaciusAndString();
        solver.solve(1, in, out);
        out.close();
    }

    static class AAcaciusAndString {
        char[] pattern = "abacaba".toCharArray();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();

            for (int i = 0; i + pattern.length - 1 < n; i++) {
                if (match(s, i)) {
                    char[] t = s.clone();
                    for (int j = i; j < i + pattern.length; j++) {
                        t[j] = pattern[j - i];
                    }
                    for (int j = 0; j < t.length; j++) {
                        if (t[j] == '?')
                            t[j] = 'x';
                    }
                    int count = 0;
                    for (int j = 0; j + pattern.length - 1 < n; j++) {
                        if (match(t, j))
                            count++;
                    }

                    if (count == 1) {
                        out.println("Yes");
                        out.println(String.valueOf(t));
                        return;
                    }
                }
            }

            out.println("No");
        }

        private boolean match(char[] s, int i) {
            int score = 0;
            for (int j = 0; j < pattern.length; j++) {
                if (s[i + j] == '?' || s[i + j] == pattern[j])
                    score++;
            }
            return score == pattern.length;
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