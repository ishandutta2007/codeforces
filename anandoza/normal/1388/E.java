import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.Comparator;
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
        EUncleBogdanAndProjections solver = new EUncleBogdanAndProjections();
        solver.solve(1, in, out);
        out.close();
    }

    static class EUncleBogdanAndProjections {
        private PointF[][] seg;
        private PointF[] points;
        private int n;
        TreeMap<Double, PointF> left;
        TreeMap<Double, PointF> right;
        private static final double EPSILON = 1e-11;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            seg = new PointF[n][2];
            points = new PointF[2 * n];
            for (int i = 0; i < n; i++) {
                int l = in.nextInt(), r = in.nextInt(), y = in.nextInt();
                seg[i][0] = PointF.of(l, y);
                seg[i][1] = PointF.of(r, y);
                points[i] = seg[i][0];
                points[i + n] = seg[i][1];
            }

            double[] alphas = new double[2 * n * (n - 1) / 2];
            int alphaSize = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (seg[i][0].y == seg[j][0].y)
                        continue;
                    double badStart = alpha(seg[i][0], seg[j][1]);
                    double badEnd = alpha(seg[i][1], seg[j][0]);
                    if (badStart > badEnd) {
                        double t = badStart;
                        badStart = badEnd;
                        badEnd = t;
                    }
                    alphas[alphaSize++] = compress(badStart + EPSILON, 1);
                    alphas[alphaSize++] = compress(badEnd - EPSILON, -1);
                }
            }

            Arrays.sort(alphas, 0, alphaSize);

            left = precompute();
            right = precompute2();

            if (alphaSize == 0) {
                out.println(score(0));
                return;
            }

            int bad = 0;
            double answer = Double.POSITIVE_INFINITY;
            for (int i = 0; i < alphaSize; i++) {
                double alpha = alphas[i];
                int inc = bad(alphas[i]);
                if (bad == 0)
                    answer = Math.min(answer, score(alpha));
                bad += inc;
                if (bad == 0)
                    answer = Math.min(answer, score(alpha));
            }

            out.println(Util.formatDouble(answer));
        }

        private double compress(double v, int i) {
            if (i > 0) {
                v = Double.longBitsToDouble(Double.doubleToLongBits(v) | 1);
            } else {
                v = Double.longBitsToDouble(~(~Double.doubleToLongBits(v) | 1));
            }
            return v;
        }

        private int bad(double v) {
            return (Double.doubleToLongBits(v) & 1) == 1 ? 1 : -1;
        }

        private TreeMap<Double, PointF> precompute() {
            TreeMap<Double, PointF> map = new TreeMap<>();
            Arrays.sort(points, Comparator.comparingDouble((PointF p) -> -p.y).thenComparingDouble(p -> p.x));

            double alpha = Double.NEGATIVE_INFINITY;
            PointF last = points[0];

            map.put(alpha, last);
            while (true) {
                double nextAlpha = Double.POSITIVE_INFINITY;
                PointF next = last;
                for (PointF p : points) {
                    if (p.equals(last))
                        continue;

                    double a = alpha(last, p);
                    if (lessEquals(a, nextAlpha) && strictLess(alpha, a) && strictLess(p.y, next.y)) {
                        nextAlpha = a;
                        next = p;
                    }
                }
                if (next == last)
                    break;
                alpha = nextAlpha;
                last = next;
                map.put(alpha, last);
            }

            return map;
        }

        private TreeMap<Double, PointF> precompute2() {
            TreeMap<Double, PointF> map = new TreeMap<>();
            Arrays.sort(points, Comparator.comparingDouble((PointF p) -> -p.y).thenComparingDouble(p -> -p.x));

            double alpha = Double.POSITIVE_INFINITY;
            PointF last = points[0];

            map.put(alpha, last);
            while (true) {
                double nextAlpha = Double.NEGATIVE_INFINITY;
                PointF next = last;
                for (PointF p : points) {
                    if (p.equals(last))
                        continue;

                    double a = alpha(last, p);
                    if (lessEquals(nextAlpha, a) && strictLess(a, alpha) && strictLess(p.y, next.y)) {
                        nextAlpha = a;
                        next = p;
                    }
                }
                if (next == last)
                    break;
                alpha = nextAlpha;
                last = next;
                map.put(alpha, last);
            }

            return map;
        }

        private double project(PointF p, double alpha) {
            return p.x + alpha * p.y;
        }

        private double score(double alpha) {
            double min = project(left.floorEntry(alpha).getValue(), alpha);
            double max = project(right.ceilingEntry(alpha).getValue(), alpha);
            return max - min;
        }

        private boolean lessEquals(double a, double b) {
            return a <= b + EPSILON;
        }

        private boolean strictLess(double a, double b) {
            return a < b - EPSILON;
        }

        private double alpha(PointF a, PointF b) {
            return (b.x - a.x) / (a.y - b.y);
        }

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
        }

        private Util() {
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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

        public static PointF of(double x, double y) {
            return new PointF(x, y);
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