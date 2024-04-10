import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.TreeSet;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] add = new int[n + 1], aib = new int[n + 1];
            int[] pos = new int[n + 1];

            TreeSet<Integer> S = new TreeSet<>();
            for (int i = 1; i <= n; ++i) {
                int a = in.nextInt();
                int c = in.nextInt();

                Integer p = S.higher(a);
                int mpos = Math.max(i - c,
                        p == null ? 1 : add[p] + query(aib, n - p + 1) + 1);
                add[a] = mpos - query(aib, n - a + 1);
                pos[i] = mpos;

                p = S.lower(a);
                while (p != null) {
                    if (add[p] + query(aib, n - p + 1) < mpos) {
                        S.remove(p);
                    } else {
                        break;
                    }
                    p = S.lower(a);
                }
                update(aib, n - (a - 1) + 1, 1);
                S.add(a);
            }

            int[] fans = new int[n + 1];
            Arrays.fill(aib, 0);
            for (int i = 1; i <= n; ++i)
                aib[i] = i & -i;
            for (int i = n; i > 0; --i) {
                int rpos = find(aib, pos[i]);
                fans[rpos] = i;
                update(aib, rpos, -1);
            }

            for (int i = 1; i <= n; ++i)
                out.print(fans[i] + " ");
            out.println();
        }

        private void update(int[] aib, int pos, int value) {
            if (pos < 1) return;
            for (; pos < aib.length; pos += pos & -pos)
                aib[pos] += value;
        }

        private int query(int[] aib, int pos) {
            int ret = 0;
            for (; pos > 0; pos -= pos & -pos)
                ret += aib[pos];
            return ret;
        }

        private int find(int[] aib, int value) {
            int pos = 0, step;
            for (step = 1; step < aib.length; step *= 2) ;
            for (; step > 0; step >>= 1) {
                if (pos + step < aib.length && aib[pos + step] < value) {
                    pos += step;
                    value -= aib[pos];
                }
            }
            return pos + 1;
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