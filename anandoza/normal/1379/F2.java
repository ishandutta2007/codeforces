import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStream;
import java.util.function.IntFunction;

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
        F2ChessStrikesBackHardVersion solver = new F2ChessStrikesBackHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class F2ChessStrikesBackHardVersion {
        private static final String NO = "NO";
        private static final String YES = "YES";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            in.nextInt(); // unused, N
            in.nextInt(); // unused, M
            int queries = in.nextInt();
            Pii[] q = new Pii[queries];
            for (int i = 0; i < queries; i++) {
                q[i] = Pii.of(in.nextInt() - 1, in.nextInt() - 1);
            }
            Map<Integer, Integer> xCoord = coordinatesMap(q);
            final int X = xCoord.size();

            FastSegmentTree<F2ChessStrikesBackHardVersion.T> st = new FastSegmentTree<>(X, F2ChessStrikesBackHardVersion.T::new, true);
            TreeSet<Integer>[] fY = new TreeSet[X];
            TreeSet<Integer>[] bY = new TreeSet[X];
            for (int x = 0; x < X; x++) {
                fY[x] = new TreeSet<>();
                fY[x].add(Integer.MAX_VALUE);
            }
            for (int x = 0; x < X; x++) {
                bY[x] = new TreeSet<>();
                bY[x].add(Integer.MIN_VALUE);
            }

            for (Pii p : q) {
                boolean isForward = p.first % 2 == 0;
                int x = xCoord.get(p.first);

                TreeSet<Integer> y = isForward ? fY[x] : bY[x];
                boolean remove = y.contains(p.second);

                if (remove) {
                    y.remove(p.second);
                } else {
                    y.add(p.second);
                }

                st.get(x);
                if (isForward)
                    st.value.min[0] = y.first();
                else
                    st.value.max[0] = y.last();
                st.update(x);

                boolean valid = !st.value.bad[1];
                out.println(valid ? YES : NO);
            }
        }

        private static Map<Integer, Integer> coordinatesMap(Pii[] q) {
            int[] coordinateArray = new int[q.length];
            for (int i = 0; i < q.length; i++) {
                coordinateArray[i] = q[i].first;
            }
            Util.safeSort(coordinateArray);
            Map<Integer, Integer> coordinates = new HashMap<>();
            for (int i = 0, j = 0; i < coordinateArray.length; i++) {
                if (coordinates.containsKey(coordinateArray[i]))
                    continue;
                coordinates.put(coordinateArray[i], j++);
            }
            return coordinates;
        }

        private static class T implements FastSegmentTree.Storage<F2ChessStrikesBackHardVersion.T> {
            public final int[] min;
            public final int[] max;
            public final boolean[] bad;

            public T(int capacity) {
                min = new int[capacity];
                max = new int[capacity];
                bad = new boolean[capacity];
            }

            public void clear(int i) {
                min[i] = Integer.MAX_VALUE;
                max[i] = Integer.MIN_VALUE;
                bad[i] = false;
            }

            public void set(int to, int from) {
                min[to] = min[from];
                max[to] = max[from];
                bad[to] = bad[from];
            }

            public void combine(int target, int left, int right) {
                min[target] = Math.min(min[left], min[right]);
                max[target] = Math.max(max[left], max[right]);
                bad[target] = bad[left] || bad[right] || min[left] < max[right];
            }

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

    static class Util {
        public static void safeSort(int[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(int[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        private Util() {
        }

    }

    static class FastSegmentTree<T extends FastSegmentTree.Storage<T>> {
        public final int size;
        public final T value;

        public FastSegmentTree(int size, IntFunction<T> constructor, boolean powerOfTwo) {
            this(powerOfTwo ? upsize(size) : size, constructor);
        }

        private static int upsize(int n) {
            int powerOfTwo = Integer.highestOneBit(n);
            if (powerOfTwo < n)
                powerOfTwo *= 2;
            return powerOfTwo;
        }

        public FastSegmentTree(int size, IntFunction<T> constructor) {
            this.size = size;
            value = constructor.apply(2 * size + 4);
            for (int i = 0; i < 2 * size + 2; i++) {
                value.clear(i);
            }
        }

        public void get(int i) {
            value.set(0, size + i);
        }

        public void update(int i) {
            i += size;
            value.set(i, 0);
            while (i > 1) {
                i /= 2;
                value.combine(i, 2 * i, 2 * i + 1);
            }
        }

        public interface Storage<T extends FastSegmentTree.Storage<T>> {
            void clear(int i);

            void set(int to, int from);

            void combine(int target, int left, int right);

        }

    }
}