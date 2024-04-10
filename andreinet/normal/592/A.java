import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = 8;
            int[] minA = new int[n], maxB = new int[n];
            Arrays.fill(minA, n + 1);
            Arrays.fill(maxB, -1);
            String[] matrix = new String[n];
            for (int i = 0; i < n; ++i) {
                matrix[i] = in.next();
                for (int j = 0; j < n; ++j) {
                    char c = matrix[i].charAt(j);
                    if (c == 'B') {
                        minA[j] = Math.min(minA[j], i);
                    } else if (c == 'W') {
                        maxB[j] = Math.max(maxB[j], i);
                    }
                }
            }
            int ansa = n + 1, ansb = n + 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    char c = matrix[i].charAt(j);
                    if (c == 'B') {
                        if (i > maxB[j]) {
                            ansb = Math.min(ansb, n - i - 1);
                        }
                    } else if (c == 'W') {
                        if (i < minA[j]) {
                            ansa = Math.min(ansa, i);
                        }
                    }
                }
            }

            out.println(ansa <= ansb ? "A" : "B");
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}