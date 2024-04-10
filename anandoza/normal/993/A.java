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
        ITwoSquares solver = new ITwoSquares();
        solver.solve(1, in, out);
        out.close();
    }

    static class ITwoSquares {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Point[][] s = new Point[2][4];

            for (int i = 0; i < s.length; i++) {
                for (int j = 0; j < s[i].length; j++) {
                    s[i][j] = new Point(2 * in.nextInt(), 2 * in.nextInt());
                }
            }

            Point[] centers = new Point[s.length];
            for (int i = 0; i < s.length; i++) {
                centers[i] = Point.zero();
                for (Point p : s[i]) {
                    centers[i].add(p);
                }
                centers[i].div(4);
            }

            for (int i = 0; i < s.length; i++) {
                for (Point p : s[i]) {
                    if (p.classify(s[1 - i]) != Classification.OUT) {
                        out.println("YES");
                        return;
                    }
                }
                if (centers[i].classify(s[1 - i]) != Classification.OUT) {
                    out.println("YES");
                    return;
                }
            }

            out.println("NO");
        }

    }

    static class Point implements Comparable<Point> {
        public long x;
        public long y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public static Point zero() {
            return new Point(0, 0);
        }

        public Point copy() {
            return new Point(x, y);
        }

        public Point add(Point o) {
            x += o.x;
            y += o.y;
            return this;
        }

        public Point subtract(Point o) {
            x -= o.x;
            y -= o.y;
            return this;
        }

        public Point div(long c) {
            x /= c;
            y /= c;
            return this;
        }

        public static Point subtract(Point a, Point b) {
            return a.copy().subtract(b);
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

        public static long cross(Point a, Point b) {
            return a.x * b.y - a.y * b.x;
        }

        public static long cross(Point p, Point a, Point b) {
            return cross(subtract(a, p), subtract(b, p));
        }

        public int compareTo(Point o) {
            int ret = Long.compare(y, o.y);
            if (ret != 0)
                return ret;
            return Long.compare(x, o.x);
        }

        public Classification classify(Point[] polygon) {
            boolean ans = false;
            for (int i = 0; i < polygon.length; i++) {
                Point a = polygon[i], b = polygon[(i + 1) % polygon.length];
                if (cross(a, b, this) == 0 && (a.compareTo(this) <= 0 || b.compareTo(this) <= 0) && (this.compareTo(a) <= 0 || this.compareTo(b) <= 0))
                    return Classification.ON;
                if (a.y > b.y) {
                    Point t = a;
                    a = b;
                    b = t;
                }
                if (a.y <= y && y < b.y && cross(this, a, b) > 0)
                    ans ^= true;
            }
            return ans ? Classification.IN : Classification.OUT;
        }

    }

    static enum Classification {
        ON,
        IN,
        OUT,
        ;
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