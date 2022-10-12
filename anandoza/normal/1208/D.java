import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.Function;
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
        DRestorePermutation solver = new DRestorePermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRestorePermutation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] s = in.readLongArray(n);

            long sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += i;
            }

            FullLongSegmentTree remaining = new FullLongSegmentTree(n, Long::sum, 0);
            for (int i = 0; i < n; i++) {
                remaining.update_LAZY(i, i + 1);
            }
            remaining.rebuild();

            int[] answer = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                int finalI = i;
                answer[i] = remaining.lowerBound(value -> value > s[finalI]);
                remaining.update(answer[i] - 1, 0);
            }
            out.println(Util.join(answer));
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

    }

    static class FullLongSegmentTree extends LongSegmentTree {
        public FullLongSegmentTree(int size, LongSegmentTree.Combiner combiner, int identityElement) {
            super(1 << (32 - Integer.numberOfLeadingZeros(size)), combiner, identityElement);
        }

        public int lowerBound(Function<Long, Boolean> bigEnough) {
            if (!bigEnough.apply(value[1]))
                return -1;

            if (bigEnough.apply(identityElement))
                return 0;

            int loc = 1;
            long cur = identityElement;
            for (; loc < size; ) {
                long mid = combine(cur, value[2 * loc]);
                if (bigEnough.apply(mid)) {
                    loc = 2 * loc;
                } else {
                    cur = mid;
                    loc = 2 * loc + 1;
                }
            }

            return loc - size + 1;
        }

    }

    static class LongSegmentTree {
        public int size;
        public long[] value;
        protected final LongSegmentTree.Combiner combiner;
        protected final long identityElement;

        public LongSegmentTree(int size, LongSegmentTree.Combiner combiner, long identityElement) {
            this.size = size;
            value = new long[2 * size];
            Arrays.fill(value, identityElement);
            this.combiner = combiner;
            this.identityElement = identityElement;
        }

        protected long combine(long a, long b) {
            return combiner.combine(a, b);
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = combine(value[2 * i], value[2 * i + 1]);
            }
        }

        public void update(int i, long v) {
            i += size;
            value[i] = v;
            while (i > 1) {
                i /= 2;
                value[i] = combine(value[2 * i], value[2 * i + 1]);
            }
        }

        public void update_LAZY(int i, long v) {
            i += size;
            value[i] = v;
        }

        public interface Combiner {
            long combine(long a, long b);

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