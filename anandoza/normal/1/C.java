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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CAncientBerlandCircus solver = new CAncientBerlandCircus();
        solver.solve(1, in, out);
        out.close();
    }

    static class CAncientBerlandCircus {
        PointF[] p;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            p = new PointF[3];
            for (int i = 0; i < 3; i++) {
                double x = in.nextDouble(), y = in.nextDouble();
                p[i] = new PointF(x, y);
            }

            double area = Double.POSITIVE_INFINITY;
            for (int sides = 3; sides <= 100; sides++) {
                area = Math.min(area, f(sides));
            }

            out.println(area);
        }

        private static boolean eq(double a, double b) {
            return Util.error(a, b) <= 1e-5;
        }

        private double f(int sides) {
            double[] angles = new double[3];
            double[] dists = new double[3];
            for (int cycle = 0; cycle < 3; cycle++) {
                PointF a = p[(cycle) % 3];
                PointF b = p[(cycle + 1) % 3];
                PointF c = p[(cycle + 2) % 3];

                PointF s1 = PointF.subtract(b, a);
                PointF s2 = PointF.subtract(c, a);
                double angle = s1.ang() - s2.ang();
                if (angle < 0)
                    angle += 2 * Math.PI;
                angle = Math.min(angle, 2 * Math.PI - angle);
                angles[cycle] = angle;

                dists[cycle] = PointF.subtract(b, c).len();
            }

            double totalOffset = 0;
            for (int i = 0; i < 3; i++) {
                double offset = angles[i] * sides / Math.PI;
                if (!eq(offset, Math.round(offset)))
                    return Double.POSITIVE_INFINITY;
                totalOffset += offset;
            }
            if (!eq(totalOffset, sides))
                return Double.POSITIVE_INFINITY;

            double dist = dists[0];
            double R = dist / 2 / Math.sin(angles[0]);
            double area = R * R * sides * Math.sin(2 * Math.PI / sides) / 2;

            return area;
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }

    static class Util {
        public static double error(double a, double b) {
            return Math.abs(a - b) / Math.max(1, Math.min(Math.abs(a), Math.abs(b)));
        }

    }

    static class PointF implements Comparable<PointF> {
        public double x;
        public double y;

        public PointF(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public PointF copy() {
            return new PointF(x, y);
        }

        public double norm() {
            return x * x + y * y;
        }

        public double len() {
            return Math.sqrt(norm());
        }

        public double ang() {
            return Math.atan2(y, x);
        }

        public PointF subtract(PointF o) {
            x -= o.x;
            y -= o.y;
            return this;
        }

        public static PointF subtract(PointF a, PointF b) {
            return a.copy().subtract(b);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            PointF point = (PointF) o;
            return x == point.x && y == point.y;
        }

        public int hashCode() {
            return Objects.hash(x, y);
        }

        public int compareTo(PointF o) {
            int ret = Double.compare(x, o.x);
            if (ret != 0)
                return ret;
            return Double.compare(y, o.y);
        }

        public String toString() {
            return String.format("(%f, %f)", x, y);
        }

    }
}