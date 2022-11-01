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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();

            Cell[] cells = new Cell[n * m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cells[i * m + j] = new Cell(i, j);
                }
            }
            Arrays.sort(cells, (o1, o2) ->
                    Integer.compare(o1.x + o1.y, o2.x + o2.y));

            int ans = 0;
            for (int i = 0; i < k; ++i)
                ans += cells[i].x + cells[i].y + 1;
            out.println(ans);
            for (int i = k - 1; i >= 0; --i) {
                for (int x = 1; x <= cells[i].x + 1; ++x) {
                    out.print("(" + x + ",1) ");
                }
                for (int y = 2; y <= cells[i].y + 1; ++y) {
                    out.print("(" + (cells[i].x + 1) + "," + y + ") ");
                }
                out.println();
            }
        }

        private class Cell {
            int x;
            int y;

            Cell(int x, int y) {
                this.x = x;
                this.y = y;
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