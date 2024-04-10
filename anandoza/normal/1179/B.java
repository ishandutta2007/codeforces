import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BTolikAndHisUncle solver = new BTolikAndHisUncle();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTolikAndHisUncle {
        boolean transposed = false;
        PrintWriter out;
        int curX;
        int curY;
        boolean[][] visited;
        ArrayList<String> answer;
        static final boolean DEBUG = false;
        HashSet<String> vectors = new HashSet<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.out = out;

            answer = new ArrayList<>();
            int n = in.nextInt(), m = in.nextInt();
            if (n > m) {
                int t = n;
                n = m;
                m = t;
                transposed = true;
            }

            visited = new boolean[m + 1][n + 1];
            curX = -1;
            curY = -1;

            ASSERT(n <= m);

            int xl = 1, xh = m;
            int yl = 1, yh = n;
            int height = yh - yl + 1;

            while (height > 1) {
                solve(xl, xh, yl, yh);
                xl++;
                xh--;
                yl++;
                yh--;
                height -= 2;
            }

            if (height > 0) {
                solve(xl, xh, yl);
            }

            for (String s : answer) {
                out.println(s);
            }

            ASSERT(answer.get(0).equals("1 1"));
            ASSERT(answer.size() == (n * m));
        }

        private void solve(int xl, int xh, int yl, int yh) {
            int x1 = xl, y1 = yl;
            int x2 = xh, y2 = yh;
            boolean backwards = false;
            if (curX >= 0 && curX < xl) {
                backwards = true;
            }

            for (int i = 0; i < (yh - yl) + (xh - xl); i++) {
                if (!backwards) {
                    add(x1, y1);
                    if (x1 < xh) {
                        x1++;
                    } else {
                        y1++;
                    }
                }

                add(x2, y2);
                if (x2 > xl) {
                    x2--;
                } else {
                    y2--;
                }

                if (backwards) {
                    add(x1, y1);
                    if (x1 < xh) {
                        x1++;
                    } else {
                        y1++;
                    }
                }
            }
        }

        private void solve(int xl, int xh, int y) {
            int x1 = xl, x2 = xh;
            boolean backwards = false;
            if (curX >= 0 && curX < xl) {
                backwards = true;
            }

            while (x1 < x2) {
                if (!backwards)
                    add(x1, y);
                add(x2, y);
                if (backwards)
                    add(x1, y);
                x1++;
                x2--;
            }

            if (x1 == x2) {
                add(x1, y);
            }
        }

        private void add(int x, int y) {
            if (DEBUG) {
                ASSERT(!visited[x][y]);
                visited[x][y] = true;
                if (curX >= 0) {
                    String v = (x - curX) + " " + (y - curY);
                    System.out.println(x + " " + y + " | " + v + " " + vectors);
                    ASSERT(!vectors.contains(v));
                    vectors.add(v);
                }
            }
            curX = x;
            curY = y;
            answer.add(string(x, y));
        }

        private String string(int i, int j) {
            return transposed ? (i + " " + j) : (j + " " + i);
        }

        private static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}