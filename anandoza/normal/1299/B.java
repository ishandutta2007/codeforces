import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BAerodynamic solver = new BAerodynamic();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAerodynamic {
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Point[] poly = new Point[n];
            for (int i = 0; i < n; i++) {
                poly[i] = new Point(in.nextInt(), in.nextInt());
            }
            Point[] diffs = new Point[n];
            for (int i = 0; i < n; i++) {
                Point cur = poly[i];
                Point next = poly[(i + 1) % n].copy();
                next.subtract(cur);

                diffs[i] = next;
            }

            if (n % 2 == 1) {
                out.println(NO);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (!Point.mult(diffs[i], -1).equals(diffs[(i + n / 2) % n])) {
                    out.println(NO);
                    return;
                }
            }

            out.println(YES);
        }

    }

    static class Point implements Comparable<Point> {
        public long x;
        public long y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Point copy() {
            return new Point(x, y);
        }

        public Point subtract(Point o) {
            x -= o.x;
            y -= o.y;
            return this;
        }

        public Point mult(long c) {
            x *= c;
            y *= c;
            return this;
        }

        public static Point mult(Point a, long c) {
            return a.copy().mult(c);
        }

        public String toString() {
            return String.format("(%d, %d)", x, y);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }

        public int hashCode() {
            return Objects.hash(x, y);
        }

        public int compareTo(Point o) {
            int ret = Long.compare(x, o.x);
            if (ret != 0)
                return ret;
            return Long.compare(y, o.y);
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