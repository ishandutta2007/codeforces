import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
            String S = in.next();
            int n = S.length();

            int[] order = new int[26];
            int[] pos = new int[26];

            for (int i = 0; i < 26; ++i) {
                order[i] = i;
                pos[i] = 0;
            }

            int[] all = new int[26 * n];
            int cnt = 0;

            int tconf = 0;
            for (int i = 1; i <= n + 1; ++i) {
                int x = i <= n ? S.charAt(i - 1) - 'a' : 26;
                int conf = 0;
                for (int j = 0; j < 26; ++j) {
                    all[cnt++] = conf;
                    conf |= 1 << order[j];
                    if (order[j] == x || pos[order[j]] == 0) break;
                }
                if (x < 26) {
                    tconf |= 1 << x;
                    int p = 0;
                    while (order[p] != x) ++p;
                    while (p > 0) {
                        order[p] = order[p - 1];
                        --p;
                    }
                    order[0] = x;
                    pos[x] = i;
                }
            }
            Arrays.sort(all, 0, cnt);

            int q = in.nextInt();
            while (q-- > 0) {
                String P = in.next();
                int conf = 0;
                for (int i = 0; i < P.length(); ++i) {
                    conf |= 1 << P.charAt(i) - 'a';
                }
                int p1 = -1, p2 = -1, step;
                for (step = 1; step < cnt; step *= 2) ;
                for (; step > 0; step /= 2) {
                    if (p1 + step < cnt && all[p1 + step] < conf)
                        p1 += step;
                    if (p2 + step < cnt && all[p2 + step] <= conf)
                        p2 += step;
                }

                out.println(conf == tconf ? 1 : p2 - p1);
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