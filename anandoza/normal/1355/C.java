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
        CCountTriangles solver = new CCountTriangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCountTriangles {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();

            long answer = 0;
            for (long z = c; z <= d; z++) {
                if (a + b > z) {
                    answer += (b - a + 1) * (c - b + 1);
                } else if (b + c <= z) {
                    answer += 0;
                } else {
                    long x = Math.max(b - a, c - b);
                    long y = Math.min(b - a, c - b);
                    long z0 = z - (a + b);
                    Util.ASSERT(z0 >= 0);
                    if (z0 <= y) {
                        answer += (x + 1) * (y + 1);
                        answer -= (z0 + 1) * (z0 + 2) / 2;
                    } else if (z0 <= x) {
                        answer += (x + 1) * (y + 1);
                        answer -= (z0 + 1) * (z0 + 2) / 2;
                        answer += (z0 - y) * (z0 - y + 1) / 2;
                    } else {
                        answer += (x + y - z0) * (x + y - z0 + 1) / 2;
                    }
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

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }
}