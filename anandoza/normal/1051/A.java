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
        AVasyaAndPassword solver = new AVasyaAndPassword();
        solver.solve(1, in, out);
        out.close();
    }

    static class AVasyaAndPassword {
        static final char[] repl = "aA1".toCharArray();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                out.println(solve(in, out));
            }
        }

        private String solve(InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            int n = s.length;

            int[] count = new int[3];
            for (char c : s)
                count[type(c)]++;

            int missing = 3;
            for (int type = 0; type < 3; type++) {
                if (count[type] > 0)
                    missing--;
            }

            if (missing == 0)
                return String.valueOf(s);

            if (missing == 2) {
                int index = 0;
                for (int i = 0; i < 3; i++) {
                    if (count[i] == 0) {
                        s[index++] = repl[i];
                    }
                }

                return String.valueOf(s);
            }

            for (int type = 0; type < 3; type++) {
                if (count[type] > 0)
                    continue;

                for (int i = 0; i < n; i++) {
                    if (count[type(s[i])] > 1) {
                        for (int t = 0; t < 3; t++) {
                            if (count[t] == 0) {
                                s[i] = repl[t];
                                return String.valueOf(s);
                            }
                        }
                    }
                }
            }

            ASSERT(false);
            return "error!";
        }

        static int type(char c) {
            if ('a' <= c && c <= 'z')
                return 0;
            if ('A' <= c && c <= 'Z')
                return 1;
            return 2;
        }

        private static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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