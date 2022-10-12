import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        FTokitsukazeAndStrangeRectangle solver = new FTokitsukazeAndStrangeRectangle();
        solver.solve(1, in, out);
        out.close();
    }

    static class FTokitsukazeAndStrangeRectangle {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            FTokitsukazeAndStrangeRectangle.Point[] input = new FTokitsukazeAndStrangeRectangle.Point[n];
            for (int i = 0; i < n; i++) {
                input[i] = new FTokitsukazeAndStrangeRectangle.Point(in.nextInt(), in.nextInt());
            }

            TreeSet<Integer> xCoordinates = new TreeSet<>();
            for (FTokitsukazeAndStrangeRectangle.Point p : input) {
                xCoordinates.add(p.x);
            }

            HashMap<Integer, Integer> xToCompressedX = new HashMap<>();
            {
                int index = 0;
                for (int x : xCoordinates) {
                    xToCompressedX.put(x, index);
                    index++;
                }
            }

            FTokitsukazeAndStrangeRectangle.Point[] points = new FTokitsukazeAndStrangeRectangle.Point[n];
            for (int i = 0; i < n; i++) {
                points[i] = new FTokitsukazeAndStrangeRectangle.Point(xToCompressedX.get(input[i].x), input[i].y);
            }

            Arrays.sort(points, Comparator.comparingInt(p -> -p.y));

            long answer = 0;

            IntSegmentTree count = new IntSegmentTree(n, Integer::sum, 0);
            for (int i = 0; i < n; i++) {
                int yCoord = points[i].y;
                List<Integer> xCoords = new ArrayList<>();
                xCoords.add(-1);
                xCoords.add(n);
                for (; i < n && points[i].y == yCoord; i++) {
                    xCoords.add(points[i].x);
                    count.update(points[i].x, 1);
                }
                i--;

                Collections.sort(xCoords);
                answer += countIntervals(count.query(0, n));

                for (int j = 0; j + 1 < xCoords.size(); j++) {
                    answer -= countIntervals(count.query(xCoords.get(j) + 1, xCoords.get(j + 1)));
                }
            }

            out.println(answer);
        }

        static long countIntervals(long numPoints) {
            return numPoints * (numPoints + 1) / 2;
        }

        static class Point {
            public final int x;
            public final int y;

            Point(int x, int y) {
                this.x = x;
                this.y = y;
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

    static class IntSegmentTree {
        public int size;
        public int[] value;
        protected final IntSegmentTree.Combiner combiner;
        protected final int identityElement;

        public IntSegmentTree(int size, IntSegmentTree.Combiner combiner, int identityElement) {
            this.size = size;
            value = new int[2 * size];
            Arrays.fill(value, identityElement);
            this.combiner = combiner;
            this.identityElement = identityElement;
        }

        protected int combine(int a, int b) {
            return combiner.combine(a, b);
        }

        public void update(int i, int v) {
            i += size;
            value[i] = v;
            while (i > 1) {
                i /= 2;
                value[i] = combine(value[2 * i], value[2 * i + 1]);
            }
        }

        public int query(int i, int j) {
            int res_left = identityElement, res_right = identityElement;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1)
                    res_left = combine(res_left, value[i++]);
                if ((j & 1) == 1)
                    res_right = combine(value[--j], res_right);
            }
            return combine(res_left, res_right);
        }

        public interface Combiner {
            int combine(int a, int b);

        }

    }
}