import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
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
            long t = in.nextLong();
            long w = in.nextLong();
            long b = in.nextLong();

            long g = gcd(w, b);
            if (BigInteger.valueOf(w).multiply(BigInteger.valueOf(b))
                    .divide(BigInteger.valueOf(g))
                    .compareTo(BigInteger.valueOf(t)) > 0) {
                long ans = Math.min(t, Math.min(w, b) - 1);
                long g1 = gcd(ans, t);
                out.println((ans / g1) + "/" + (t / g1));
            } else {
                long m = w / g * b;
                long cnt = t / m + 1;
                long ans = Math.min(w, b) * cnt - 1;
                long r = t % m;
                if (r < Math.min(w, b)) {
                    ans -= Math.min(w, b) - r - 1;
                }
                long g1 = gcd(ans, t);
                out.println((ans / g1) + "/" + (t / g1));
            }
        }

        private long gcd(long a, long b) {
            while (b != 0) {
                long c = a % b;
                a = b;
                b = c;
            }
            return a;
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

        public long nextLong() {
            return Long.parseLong(next());
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