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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
        /*int[] ans = new int[30];
        for (int i = 1; i < 30; ++i) {
            ans[i] = getDp((1 << i) - 1);
        }*/

            int[] ans = new int[]{0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

        /*for (int i = 0; i < 30; ++i)
            System.err.print(ans[i] + ", ");*/

            int n = in.nextInt(), sq = 1;
            while ((sq + 1) * (sq + 1) <= n) sq++;

            boolean[] power = new boolean[sq + 1];
            int[] count = new int[30];
            int bcnt = 0;

            for (int i = 2; i <= sq; ++i) {
                if (power[i]) continue;
                int k = 0, r = 1;
                while ((long) r * i <= n) {
                    r *= i;
                    k++;
                    if (r <= sq) {
                        power[r] = true;
                    } else {
                        bcnt++;
                    }
                }
                count[k]++;
            }

            int sum = 0;
            for (int i = 1; i < 30; ++i) {
                if (count[i] % 2 == 1) {
                    sum ^= ans[i];
                }
            }
            sum ^= (n - sq - bcnt + 1) % 2;

            out.println(sum == 0 ? "Petya" : "Vasya");
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