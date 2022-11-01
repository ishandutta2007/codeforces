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
            int[] A = new int[N], beg = new int[N];
            for (int i = 0; i < N; ++i) {
                int x = in.nextInt();
                A[i] = x;

                int pos = 17;
                while ((x & (1 << pos)) == 0) pos--;
                beg[i] = pos;
            }

            int cnt = 0, nmb = 0;
            while (true) {
                boolean ok = true;
                if (beg[0] - cnt < 0) break;

                int bit = getBit(A[0], beg[0] - cnt);
                for (int i = 1; i < N; ++i) {
                    if (beg[i] - cnt < 0 || getBit(A[i], beg[i] - cnt) != bit) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) break;

                nmb = nmb * 2 + bit;
                cnt++;
            }

            long ans = 0;
            for (int i = 0; i < N; ++i) {
                int pos = beg[i] - cnt;
                while (pos >= 0 && getBit(A[i], pos) == 0)
                    pos--;

                pos++;
                if (pos > 0) {
                    ans += pos;
                    A[i] >>= pos;
                }

                beg[i] -= pos;
            }

            long mans = 0x3f3f3f3f;
            for (int i = cnt - 1; i < 17; ++i) {
                long curr = 0;
                for (int j = 0; j < N; ++j) {
                    curr += Math.abs(beg[j] - i);
                }
                mans = Math.min(mans, curr);
            }

            ans += mans;
            out.println(ans);
        }

        private int getBit(int a, int pos) {
            return (a & (1 << pos)) == 0 ? 0 : 1;
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