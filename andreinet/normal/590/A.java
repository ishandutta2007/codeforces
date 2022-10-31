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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] A = new int[n + 2];
            for (int i = 1; i <= n; ++i)
                A[i] = in.nextInt();
            A[0] = A[1];
            A[n + 1] = A[n];

            int[] B = A.clone();

            int cnt = 0, ans = 0;
            for (int i = 1; i <= n; ++i) {
                if (A[i] != A[i - 1] && A[i] != A[i + 1]) {
                    cnt++;
                } else {
                    if (cnt != 0) {
                        ans = Math.max(ans, (cnt + 1) / 2);
                        int left = i - cnt;
                        if (cnt % 2 == 1) {
                            for (int j = left; j < i; ++j) B[j] = A[i];
                        } else {
                            int mid = left + cnt / 2;
                            for (int j = left; j < mid; ++j) B[j] = A[i] ^ 1;
                            for (int j = mid; j < i; ++j) B[j] = A[i];
                        }
                    }
                    cnt = 0;
                }
            }

            out.println(ans);
            for (int i = 1; i <= n; ++i) out.print(B[i] + " ");
            out.println();
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