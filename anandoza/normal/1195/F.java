import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FGeometersAnonymousClub solver = new FGeometersAnonymousClub();
        solver.solve(1, in, out);
        out.close();
    }

    static class FGeometersAnonymousClub {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            List<Point> points = new ArrayList<>();

            int[] start = new int[n];
            int[] end = new int[n];
            for (int i = 0; i < n; i++) {
                int k = in.nextInt();
                Point[] poly = new Point[k];
                for (int j = 0; j < k; j++) {
                    poly[j] = new Point(in.nextInt(), in.nextInt());
                }

                start[i] = points.size();
                for (int j = 0; j < k; j++) {
                    Point cur = poly[j];
                    Point next = poly[(j + 1) % k].copy();
                    next.subtract(cur);
                    long g = NumberTheory.gcd(Math.abs(next.x), Math.abs(next.y));
                    next.div(g);

                    points.add(next);
                }
                end[i] = points.size();
            }

            int queryCount = in.nextInt();
            Pii[] queries = new Pii[queryCount];
            for (int i = 0; i < queryCount; i++) {
                queries[i] = Pii.of(in.nextInt() - 1, in.nextInt());
            }

            List<Integer>[] byEnd = Util.arrayOfLists(n + 1);
            for (int i = 0; i < queryCount; i++) {
                byEnd[queries[i].second].add(i);
            }

            HashMap<Point, Integer> last = new HashMap<>();
            int[] answer = new int[queryCount];
            IntSumBIT sum = new IntSumBIT(points.size());
            for (int i = 0; i < n; i++) {
                for (int j = start[i]; j < end[i]; j++) {
                    Point p = points.get(j);
                    Integer l = last.put(p, j);
                    if (l != null) {
                        sum.update(l, 0);
                    }

                    sum.update(j, 1);
                }

                for (int j : byEnd[i + 1]) {
                    answer[j] = sum.query(start[queries[j].first], end[i]);
                }
            }

            for (int x : answer)
                out.println(x);
        }

    }

    static class Util {
        private Util() {
        }

        public static <T> List<T>[] arrayOfLists(int n) {
            List<T>[] array = new List[n];
            for (int i = 0; i < n; i++) {
                array[i] = new ArrayList<>(0);
            }
            return array;
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

    static class NumberTheory {
        public static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            long c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
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

        public Point div(long c) {
            x /= c;
            y /= c;
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
            int ret = Long.compare(x, o.x);
            if (ret != 0)
                return ret;
            return Long.compare(y, o.y);
        }

    }

    static class IntSumBIT {
        public final int size;
        public final int[] value;

        public IntSumBIT(int size) {
            this.size = size;
            value = new int[size + 1];
        }

        public void update(int i, int v) {
            add(i, v - query(i, i + 1));
        }

        public void add(int i, int v) {
            for (i++; i <= size; i += i & -i)
                value[i] += v;
        }

        public int sum(int i) {
            int r = 0;
            for (; i > 0; i -= i & -i)
                r = r + value[i];
            return r;
        }

        public int query(int i, int j) {
            return i >= j ? 0 : sum(j) - sum(i);
        }

    }

    static class Pii implements Comparable<Pii> {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pii o) {
            if (first != o.first)
                return Integer.compare(first, o.first);
            return Integer.compare(second, o.second);
        }

    }
}