import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.function.LongPredicate;
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
        FAmrAndPins solver = new FAmrAndPins();
        solver.solve(1, in, out);
        out.close();
    }

    static class FAmrAndPins {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long r = 2 * in.nextLong();
            Point start = new Point(in.nextLong(), in.nextLong());
            Point end = new Point(in.nextLong(), in.nextLong());

            long norm = start.subtract(end).norm();
            long stepsSq = (norm + r * r - 1) / (r * r);
            long answer = BinarySearch.binarySearchLong(a -> a * a >= stepsSq);

            out.println(answer);
        }

    }

    static class BinarySearch {
        public static long binarySearchLong(LongPredicate bigEnough) {
            long tooSmall = 0, tooBig;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.test(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.test(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                long center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.test(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
        }

    }

    static class Point implements Comparable<Point> {
        public long x;
        public long y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public long norm() {
            return x * x + y * y;
        }

        public Point subtract(Point o) {
            x -= o.x;
            y -= o.y;
            return this;
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
            int ret = Long.compare(y, o.y);
            if (ret != 0)
                return ret;
            return Long.compare(x, o.x);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}