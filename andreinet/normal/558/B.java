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
            int N = in.nextInt();

            final int maxVal = 1000_000;
            int[] count = new int[maxVal + 1];
            int[] first = new int[maxVal + 1], last = new int[maxVal + 1];

            int[] A = new int[N];

            int maxAp = 0;
            for (int i = 0; i < N; ++i) {
                A[i] = in.nextInt();
                count[A[i]]++;
                if (count[A[i]] == 1) first[A[i]] = i;
                last[A[i]] = i;

                maxAp = Math.max(maxAp, count[A[i]]);
            }

            int ans = N, left = 1, right = N - 1;
            for (int i = 1; i <= maxVal; ++i) {
                if (count[i] != 0) {
                    if (count[i] == maxAp && ans > last[i] - first[i]) {
                        ans = last[i] - first[i];
                        left = first[i] + 1;
                        right = last[i] + 1;
                    }
                }
            }

            out.println(left + " " + right);
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