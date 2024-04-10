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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[][][][] dp;
        int offset1;
        int offset2;
        String[] matrix;
        int n;
        int m;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            matrix = new String[n];
            for (int i = 0; i < n; ++i) {
                matrix[i] = in.next();
            }

            int x = n + m;
            dp = new int[x + 10][x + 10][x + 10][x + 10];
            for (int[][][] p : dp)
                for (int[][] l : p)
                    for (int[] r : l)
                        Arrays.fill(r, -1);
            offset1 = 2;
            offset2 = 1 + m;

            int ans;
            if (m % 2 == 0) {
                ans = getAns(-2, n + m, -m, n + 1) ^
                        getAns(-1, n + m, -1 - m, n + 1);
            } else {
                ans = getAns(-2, n + m, -1 - m, n + 1) ^
                        getAns(-1, n + m, -m, n + 1);
            }

            if (ans != 0) {
                out.println("WIN");
            } else {
                out.println("LOSE");
            }
        }

        private int getAns(int ld1, int rd1, int ld2, int rd2) {
            if (rd1 - ld1 <= 2 || rd2 - ld2 <= 2) {
                return 0;
            } else if (dp[offset1 + ld1][offset1 + rd1][offset2 + ld2][offset2 + rd2] != -1) {
                return dp[offset1 + ld1][offset1 + rd1][offset2 + ld2][offset2 + rd2];
            } else {
                TreeSet<Integer> values = new TreeSet<>();
                for (int d1 = ld1 + 2; d1 < rd1; d1 += 2) {
                    for (int d2 = ld2 + 2; d2 < rd2; d2 += 2) {
                        int i = (d1 + d2) / 2;
                        int j = (d1 - d2) / 2;
                        if (i < 0 || i >= n || j < 0 || j >= m) continue;
                        int v;
                        if (matrix[i].charAt(j) == 'L') {
                            v = getAns(ld1, d1, ld2, rd2) ^
                                    getAns(d1, rd1, ld2, rd2);
                        } else if (matrix[i].charAt(j) == 'R') {
                            v = getAns(ld1, rd1, ld2, d2) ^
                                    getAns(ld1, rd1, d2, rd2);
                        } else {
                            v = getAns(ld1, d1, ld2, d2) ^
                                    getAns(d1, rd1, ld2, d2) ^
                                    getAns(ld1, d1, d2, rd2) ^
                                    getAns(d1, rd1, d2, rd2);
                        }
                        values.add(v);
                    }
                }
                int ans = 0;
                while (values.contains(ans))
                    ++ans;
                return dp[offset1 + ld1][offset1 + rd1][offset2 + ld2][offset2 + rd2] = ans;
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