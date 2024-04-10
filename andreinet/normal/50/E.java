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
            int n = in.nextInt(), m = in.nextInt();
            int[] cnt = new int[20_000_003];
            int offset = 10_000_001;

            long ans = 0;
            for (int b = 1, a = 1; b <= n; ++b) {
                while ((long) b * b - (long) a * a > m) {
                    a++;
                }
                cnt[offset - b + a]++;
                cnt[offset - b + b]--;
                cnt[offset - b - b + 1]++;
                cnt[offset - b - a + 1]--;
                if ((long) b * b <= m) {
                    cnt[offset - b]++;
                    cnt[offset - b + 1]--;
                }
                int r = (int) Math.min((long) b * b - 1, m);
                r -= b - a;
                ans += 2 * r;
            }

            if (cnt[0] > 0) ans++;
            for (int i = 1; i < cnt.length; ++i) {
                cnt[i] += cnt[i - 1];
                if (cnt[i] > 0) ans++;
            }

            out.println(ans);
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