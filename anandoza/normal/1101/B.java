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
        BAccordion solver = new BAccordion();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAccordion {
        private static final char LEFT = '[';
        private static final char RIGHT = ']';
        private static final char COLON = ':';
        private static final char BAR = '|';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();

            int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;
            for (int i = 0; i < s.length; i++) {
                if (s[i] == LEFT && left == Integer.MAX_VALUE)
                    left = i;
                if (s[i] == RIGHT)
                    right = i;
            }

            int leftColon = Integer.MAX_VALUE, rightColon = Integer.MIN_VALUE;
            for (int i = left; i <= right; i++) {
                if (s[i] == COLON) {
                    leftColon = Math.min(leftColon, i);
                    rightColon = Math.max(rightColon, i);
                }
            }

            if (leftColon >= rightColon) {
                out.println(-1);
                return;
            }

            int answer = 4;
            for (int i = leftColon; i <= rightColon; i++) {
                if (s[i] == BAR)
                    answer++;
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