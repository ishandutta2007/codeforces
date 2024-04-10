import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[2 * n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            for (int i = n; i < 2 * n; ++i) {
                a[i] = a[i - n];
            }
            int[] add = new int[2 * n];
            long current = 0;
            long ratio = 0;
            long ans = Long.MAX_VALUE;
            int posAns = -1;
            for (int i = 2 * n - 1; i >= 0; --i) {
                if (i - a[i] >= 0) {
                    add[i - a[i]] += 2;
                }
                ratio += add[i];
                current += ratio;
                current += a[i] - 1;
                if (i + n < 2 * n) {
                    current -= n + 1 - a[i + n];
                    ratio--;
                }
                ratio--;
                if (i < n) {
                    if (ans > current) {
                        ans = current;
                        posAns = i;
                    }
                }
            }
            posAns = (n - posAns) % n;
            out.println(ans + " " + posAns);
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

        public int nextInt() {
            return Integer.parseInt(next());
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