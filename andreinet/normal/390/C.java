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
            int n = in.nextInt(), k = in.nextInt(), q = in.nextInt();

            String S = in.next();

            int[] A = new int[n];
            for (int i = 0; i < n; ++i)
                A[i] = S.charAt(i) == '0' ? 0 : 1;

            int[] sumk = new int[n], sum = new int[n];
            for (int i = 0; i < n; ++i) {
                sumk[i] = A[i];
                if (i >= k) sumk[i] += sumk[i - k];
                sum[i] = A[i];
                if (i > 0) sum[i] += sum[i - 1];
            }

            while (q-- > 0) {
                int l = in.nextInt() - 1, r = in.nextInt() - 1;
                int sk = sumk[r];
                if (l > 0) sk -= sumk[l - 1];
                int s = sum[r];
                if (l > 0) s -= sum[l - 1];

                int ans = s - sk + (r - l + 1) / k - sk;
                out.println(ans);
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