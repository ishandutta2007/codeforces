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
        AInscribedFigures solver = new AInscribedFigures();
        solver.solve(1, in, out);
        out.close();
    }

    static class AInscribedFigures {
        static final int CIRCLE = 1;
        static final int TRIANGLE = 2;
        static final int SQUARE = 3;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            int answer = 0;

            for (int i = 0; i < n - 1; i++) {
                int cur = a[i];
                int next = a[i + 1];

                if (cur == CIRCLE) {
                    if (next == TRIANGLE) {
                        answer += 3;
                        if (i - 1 >= 0 && a[i - 1] == SQUARE) {
                            answer -= 1;
                        }
                    } else if (next == SQUARE) {
                        answer += 4;
                    }
                } else if (cur == TRIANGLE) {
                    if (next == SQUARE) {
                        answer = -1;
                        break;
                    } else if (next == CIRCLE) {
                        answer += 3;
                    }
                } else if (cur == SQUARE) {
                    if (next == TRIANGLE) {
                        answer = -1;
                        break;
                    } else if (next == CIRCLE) {
                        answer += 4;
                    }
                }
            }

            out.println(answer >= 0 ? "Finite" : "Infinite");
            if (answer >= 0) {
                out.println(answer);
            }
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