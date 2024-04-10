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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt(), M = in.nextInt();
            char[] A = in.next().toCharArray();

            int s = 0;
            for (int i = 1; i < N; ++i)
                if (A[i] == '.' && A[i - 1] == '.')
                    s++;

            while (M-- > 0) {
                int pos = in.nextInt() - 1;
                char c = in.next().charAt(0);

                if (c == '.' && A[pos] != '.') {
                    if (pos > 0 && A[pos - 1] == '.') s++;
                    if (pos < N - 1 && A[pos + 1] == '.') s++;
                } else if (c != '.' && A[pos] == '.') {
                    if (pos > 0 && A[pos - 1] == '.') s--;
                    if (pos < N - 1 && A[pos + 1] == '.') s--;
                }

                A[pos] = c;

                out.println(s);
            }
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