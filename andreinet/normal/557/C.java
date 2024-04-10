import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
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
            int M = in.nextInt();
            final int maxLen = 100005, N = 100000;

            int[] count = new int[maxLen], sumd = new int[maxLen];
            int[] A = new int[M];
            for (int i = 0; i < M; ++i) {
                int x = in.nextInt();
                count[x]++;
                A[i] = x;
            }

            List<Integer>[] costs = new List[maxLen];
            for (int i = 0; i < maxLen; ++i) costs[i] = new ArrayList<>();

            for (int i = 0; i < M; ++i) {
                int x = in.nextInt();
                sumd[A[i]] += x;
                costs[A[i]].add(x);
            }

            for (int i = N; i > 0; --i)
                sumd[i] += sumd[i + 1];

            int[] sumc = new int[203], cntc = new int[203];

            TreeSet<Integer> S = new TreeSet<>();
            int ans = Integer.MAX_VALUE, have = 0;
            for (int i = 1; i <= N; ++i) {
                have += count[i];
                if (have == 0) continue;

                int need = Math.max(0, have - (2 * count[i] - 1));
                if (need == 0) ans = Math.min(ans, sumd[i + 1]);
                else {
                    int pos = 0, add = 0;
                    for (int step = 1 << 8; step > 0; step /= 2) {
                        if (pos + step < sumc.length && need > cntc[pos + step]) {
                            pos += step;
                            need -= cntc[pos];
                            add += sumc[pos];
                        }
                    }
                    add += (pos + 1) * need;

                    ans = Math.min(ans, sumd[i + 1] + add);
                }

                for (int p : costs[i]) update(sumc, cntc, p, p);
            }

            out.println(ans);
        }

        private void update(int[] sum, int[] cnt, int pos, int val) {
            for (; pos < cnt.length; pos += pos & -pos) {
                sum[pos] += val;
                cnt[pos]++;
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