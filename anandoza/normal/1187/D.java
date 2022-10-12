import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.ArrayDeque;
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
        DSubarraySorting solver = new DSubarraySorting();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSubarraySorting {
        private static final Queue<Integer> EMPTY = new ArrayDeque<>();
        Map<Integer, Queue<Integer>> indices;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                out.println(solve(in, out) ? "YES" : "NO");
            }
        }

        private boolean solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            for (int i = 0; i < n; i++)
                b[i] = in.nextInt();

            Integer[] sortedA = new Integer[n];
            Integer[] sortedB = new Integer[n];

            for (int i = 0; i < n; i++)
                sortedA[i] = a[i];
            for (int i = 0; i < n; i++)
                sortedB[i] = b[i];
            Arrays.sort(sortedA);
            Arrays.sort(sortedB);
            for (int i = 0; i < n; i++) {
                if (!sortedA[i].equals(sortedB[i]))
                    return false;
            }

            indices = new HashMap<>();
            for (int i = 0; i < n; i++) {
                if (!indices.containsKey(a[i]))
                    indices.put(a[i], new ArrayDeque<>());
                indices.get(a[i]).add(i);
            }

            //        System.out.println(indices);

            IntSegmentTree min = new IntSegmentTree(n, Math::min, Integer.MAX_VALUE);
            //        IntSegmentTree removed = new IntSegmentTree(n, Integer::sum, 0);

            for (int i = 0; i < n; i++) {
                min.update(i, a[i]);
            }

            for (int i = 0; i < n; i++) {
                int desired = b[i];

                Queue<Integer> ind = indices.getOrDefault(desired, EMPTY);
                if (ind.isEmpty())
                    return false;

                int left = ind.poll();

                int minValue = min.query(0, left);
                //            System.out.format("%d %d %d%n", desired, blockingIndex, left);

                if (minValue < desired)
                    return false;

                //            removed.update(left, 1);
                min.update(left, Integer.MAX_VALUE);
            }

            return true;
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
}