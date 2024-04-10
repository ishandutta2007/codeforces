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
        ABeruTaxi solver = new ABeruTaxi();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABeruTaxi {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            PointF home = new PointF(in.nextInt(), in.nextInt());
            int n = in.nextInt();

            double answer = Double.POSITIVE_INFINITY;
            for (int i = 0; i < n; i++) {
                PointF car = new PointF(in.nextInt(), in.nextInt());
                double v = in.nextInt();
                answer = Math.min(answer, PointF.subtract(home, car).len() / v);
            }

            out.format("%.12f%n", answer);
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
        double x;
        double y;

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

    }
}