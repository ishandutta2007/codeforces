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
        BRestrictedRPS solver = new BRestrictedRPS();
        solver.solve(1, in, out);
        out.close();
    }

    static class BRestrictedRPS {
        static final char A = 'R';
        static final char B = 'P';
        static final char C = 'S';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            char[] s = in.next().toCharArray();

            char[] answer = new char[n];

            int score = 0;
            for (int i = 0; i < n; i++) {
                switch (s[i]) {
                    case A:
                        if (b > 0) {
                            b--;
                            score++;
                            answer[i] = B;
                        }
                        break;
                    case B:
                        if (c > 0) {
                            c--;
                            score++;
                            answer[i] = C;
                        }
                        break;
                    case C:
                        if (a > 0) {
                            a--;
                            score++;
                            answer[i] = A;
                        }
                        break;
                }
            }

            if (score < (n + 1) / 2) {
                out.println("NO");
                return;
            }

            for (int i = 0; i < n; i++) {
                if (answer[i] == 0) {
                    if (a > 0) {
                        answer[i] = A;
                        a--;
                        continue;
                    }
                    if (b > 0) {
                        answer[i] = B;
                        b--;
                        continue;
                    }
                    if (c > 0) {
                        answer[i] = C;
                        c--;
                        continue;
                    }
                }
            }
            out.println("YES");
            out.println(String.valueOf(answer));
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