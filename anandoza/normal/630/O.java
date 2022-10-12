import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
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
        OArrow solver = new OArrow();
        solver.solve(1, in, out);
        out.close();
    }

    static class OArrow {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            double px = in.nextInt();
            double py = in.nextInt();
            PointF o = new PointF(px, py);
            double vx = in.nextInt();
            double vy = in.nextInt();
            PointF v = new PointF(vy, -vx);
            double a = in.nextInt();
            double b = in.nextInt();
            double c = in.nextInt();
            double d = in.nextInt();

            List<PointF> points = new ArrayList<>();
            points.add(new PointF(0, b));
            points.add(new PointF(-a / 2, 0));
            points.add(new PointF(-c / 2, 0));
            points.add(new PointF(-c / 2, -d));
            points.add(new PointF(c / 2, -d));
            points.add(new PointF(c / 2, 0));
            points.add(new PointF(a / 2, 0));

            for (PointF p : points) {
                p.mult(v);
                p.div(v.len());
                p.add(o);

                out.println(Util.join(Util.formatDouble(p.x), Util.formatDouble(p.y)));
            }

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

    static class PointF implements Comparable<PointF> {
        public double x;
        public double y;

        public PointF(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public double norm() {
            return x * x + y * y;
        }

        public double len() {
            return Math.sqrt(norm());
        }

        public PointF add(PointF o) {
            x += o.x;
            y += o.y;
            return this;
        }

        public PointF mult(PointF o) {
            double newX = x * o.x - y * o.y;
            double newY = x * o.y + y * o.x;
            x = newX;
            y = newY;
            return this;
        }

        public PointF div(double c) {
            x /= c;
            y /= c;
            return this;
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

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
        }

        public static String join(String... i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

    }
}