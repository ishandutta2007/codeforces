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
            int N = in.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; ++i)
                A[i] = in.nextInt();

            double l, r = 0;
            for (int i = 0; i < N; ++i)
                r = Math.max(r, Math.abs(A[i]));
            l = -r;

            for (int i = 0; i < 200; ++i) {
                double m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
                double s1 = calc(A, m1);
                double s2 = calc(A, m2);

                if (s1 > s2) l = m1;
                else r = m2;
            }

            double ans = calc(A, r);
            out.println(String.format("%.15f", ans));
        }

        private double calc(int[] A, double x) {
            double ans = 0;
            for (int step = 0; step < 2; ++step) {
                double smin = 0, s = 0;
                for (int i = 0; i < A.length; ++i) {
                    s += A[i] - x;
                    ans = Math.max(ans, s - smin);
                    smin = Math.min(smin, s);
                }
                for (int i = 0; i < A.length; ++i)
                    A[i] = -A[i];
                x = -x;
            }
            return ans;
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