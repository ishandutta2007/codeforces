import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C1HeidiAndTheTuringTestEasy solver = new C1HeidiAndTheTuringTestEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class C1HeidiAndTheTuringTestEasy {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = 4 * sc.nextInt() + 1;

            Point p[] = new Point[n];
            for (int i = 0; i < n; ++i) {
                p[i] = new Point(sc.nextInt(), sc.nextInt());
            }

            for (int j = 0; j < n; ++j) {
                int flag = 0;
                int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE;
                int minY = Integer.MAX_VALUE, maxY = Integer.MIN_VALUE;
                for (int i = 0; i < n; ++i) {
                    if (i == j)
                        continue;

                    minX = Math.min(minX, p[i].x);
                    maxX = Math.max(maxX, p[i].x);
                    maxY = Math.max(maxY, p[i].y);
                    minY = Math.min(minY, p[i].y);
                }

                if (maxX - minX != maxY - minY)
                    flag = 1;

                for (int i = 0; i < n; ++i) {
                    if (i == j)
                        continue;

                    if (p[i].x == maxX || p[i].x == minX) {
                        if (p[i].y > maxY || p[i].y < minY)
                            flag = 1;
                    } else if (p[i].y == maxY || p[i].y == minY) {
                        if (p[i].x > maxX || p[i].x < minX)
                            flag = 1;
                    } else
                        flag = 1;
                }

                if (flag == 0) {
                    out.print(p[j].x + " " + p[j].y);
                    return;
                }
            }
        }

        class Point {
            int x;
            int y;

            Point(int a, int b) {
                x = a;
                y = b;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}