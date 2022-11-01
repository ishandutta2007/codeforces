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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), w = in.nextInt();
            int[] a = new int[n];
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                sum += a[i];
            }

            if (w < 1 || w > sum) {
                out.println("No");
            } else if (w == 1) {
                int pos = n - 1;
                while (pos >= 0 && a[pos] != 1)
                    --pos;
                if (pos == -1) {
                    out.println("No");
                } else {
                    out.println("Yes");
                    out.print((pos + 1) + " ");
                    for (int i = 0; i < n; ++i) {
                        if (i != pos) {
                            out.println(repeat((i + 1) + " ", 2 * a[i]));
                        }
                    }
                    out.print((pos + 1) + " ");
                }
            } else if (n == 1) {
                if (a[0] == w) {
                    out.println("Yes");
                    out.println(repeat("1 ", 2 * a[0]));
                } else {
                    out.println("No");
                }
            } else {
                out.println("Yes");
                a[0]--;
                a[1]--;
                int k = n;
                int x = 0;
                while (x < w - 2) {
                    out.print(k + " " + k + " ");
                    a[k - 1]--;
                    if (a[k - 1] == 0) k--;
                    x++;
                }
                out.print("1 ");
                while (k > 2) {
                    out.print(k + " " + k + " ");
                    a[k - 1]--;
                    if (a[k - 1] == 0) k--;
                }
                while (a[1] > 0) {
                    out.print("2 2 ");
                    a[1]--;
                }
                out.print("1 ");
                out.print("2 ");
                while (a[0] > 0) {
                    out.print("1 1 ");
                    a[0]--;
                }
                out.print("2 ");
            }
        }

        private String repeat(String e, int times) {
            return new String(new char[times]).replace("\0", e);
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