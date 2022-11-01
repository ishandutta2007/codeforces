import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        InputReader in;
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt(), k = in.nextInt();

            int left = 0, right = n - 1;
            int pos = -1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (mid != n - 1 && ask(mid, mid + 1) == 1) {
                    left = mid + 1;
                    pos = mid;
                } else {
                    right = mid - 1;
                }
            }
            ++pos;

            left = 0;
            right = pos - 1;

            int other = -1;
            if (pos > 0) {
                other = pos;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (ask(mid, mid + 1) == 0) {
                        other = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            if (other < 0 || other == pos) {
                if (pos == n - 2) {
                    other = pos + 1;
                } else {
                    left = pos + 1;
                    right = n - 1;
                    while (left <= right) {
                        int mid = (left + right + 1) / 2;
                        if (ask(mid, mid - 1) == 0) {
                            other = mid;
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                }
            }
            System.err.println(pos + " " + other);
            answer(pos, other);
        }

        private int ask(int x, int y) {
            out.println("1 " + (x + 1) + " " + (y + 1));
            out.flush();
            return in.next().equals("TAK") ? 0 : 1;
        }

        private void answer(int x, int y) {
            out.println("2 " + (x + 1) + " " + (y + 1));
            out.flush();
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