import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.function.LongToIntFunction;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.IntPredicate;
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
        ASerejaAndPrefixes solver = new ASerejaAndPrefixes();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASerejaAndPrefixes {
        private static final int BOUND = 100_000;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int m = in.nextInt();
            List<Pair<Long, Pll>> a = new ArrayList<>();
            List<Integer> answer = new ArrayList<>();
            long index = 0;
            for (int stage = 0; stage < m; stage++) {
                int t = in.nextInt();
                if (t == 1) {
                    int x = in.nextInt();
                    a.add(Pair.of(index, Pll.of(x, -1)));
                    index++;
                    if (answer.size() < BOUND)
                        answer.add(x);
                } else {
                    int l = in.nextInt();
                    int c = in.nextInt();
                    if (answer.size() < BOUND)
                        for (int i = 0; i < c; i++) {
                            answer.addAll(answer.subList(0, l));
                        }
                    a.add(Pair.of(index, Pll.of(l, c)));
                    index += l * c;
                }
            }
            int n = in.nextInt();
            long[] indices = in.readLongArray(n);

            LongToIntFunction f = new LongToIntFunction() {

                public int applyAsInt(long i) {
                    if (i < BOUND) {
                        return answer.get((int) i);
                    }
                    int j = BinarySearch.binarySearch((int b) -> {
                        if (b >= a.size())
                            return true;
                        if (a.get(b).first > i)
                            return true;
                        return false;
                    });
                    j--;

                    Pair<Long, Pll> p = a.get(j);
                    if (p.second.second < 0)
                        return (int) p.second.first;
                    return applyAsInt((i - p.first) % p.second.first);
                }
            };

            for (long i : indices) {
                out.print(f.applyAsInt(i - 1) + " ");
            }
            out.println();
        }

    }

    static class BinarySearch {
        public static int binarySearch(IntPredicate bigEnough) {
            int tooSmall = 0, tooBig;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.test(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.test(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.test(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
        }

    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }

    static class Pll implements Comparable<Pll> {
        public final long first;
        public final long second;

        public Pll(long first, long second) {
            this.first = first;
            this.second = second;
        }

        public static Pll of(long first, long second) {
            return new Pll(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pll pair = (Pll) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new long[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pll o) {
            if (first != o.first)
                return Long.compare(first, o.first);
            return Long.compare(second, o.second);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}