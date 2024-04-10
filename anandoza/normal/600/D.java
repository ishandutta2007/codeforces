import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        DAreaOfTwoCirclesIntersection solver = new DAreaOfTwoCirclesIntersection();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAreaOfTwoCirclesIntersection {
        private static final int ITER = 1_00_000_000;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            double x1 = in.nextDouble(), y1 = in.nextDouble(), r1 = in.nextDouble();
            double x2 = in.nextDouble(), y2 = in.nextDouble(), r2 = in.nextDouble();
            if (Math.abs(x1 - x2) < Math.abs(y1 - y2)) {
                double t = x1;
                x1 = y1;
                y1 = t;
                t = x2;
                x2 = y2;
                y2 = t;
            }

            double xmin = Math.max(x1 - r1, x2 - r2);
            double xmax = Math.min(x1 + r1, x2 + r2);
            double x0 = (xmin + xmax) / 2;
            double y0 = (y1 + y2) / 2;
            xmin -= x0;
            xmax -= x0;
            x1 -= x0;
            x2 -= x0;
            y1 -= y0;
            y2 -= y0;

            double area = 0;
            double STEP = (xmax - xmin) / ITER;
            double prevL = -1;
            for (double x = xmin; x < xmax; x += STEP) {
                double dy1 = r1 * r1 - (x - x1) * (x - x1);
                dy1 = dy1 <= 0 ? 0 : Math.sqrt(dy1);
                double a1 = y1 - dy1, b1 = y1 + dy1;

                double dy2 = r2 * r2 - (x - x2) * (x - x2);
                dy2 = dy2 <= 0 ? 0 : Math.sqrt(dy2);
                double a2 = y2 - dy2, b2 = y2 + dy2;

                double l = Math.min(b1, b2) - Math.max(a1, a2);
                if (l <= 0)
                    l = 0;
                if (prevL == -1)
                    prevL = l;
                area += (l + prevL) / 2;
                prevL = l;
            }
            area *= STEP;

            out.println(area);
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}