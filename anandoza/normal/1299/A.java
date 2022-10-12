import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AAnuHasAFunction solver = new AAnuHasAFunction();
        solver.solve(1, in, out);
        out.close();
    }

    static class AAnuHasAFunction {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            IntSparseTable or = new IntSparseTable(a, (x, y) -> x | y);

            int max = 0, maxIndex = 0;
            for (int i = 0; i < n; i++) {
                int rest = or.queryOrDefault(0, i, 0) | or.queryOrDefault(i + 1, n, 0);

                int cand = a[i] & ~rest;
                if (cand > max) {
                    max = cand;
                    maxIndex = i;
                }
            }

            Util.swap(a, 0, maxIndex);
            out.println(Util.join(a));
        }

    }

    static class IntSparseTable {
        public int size;
        public int[] table;
        private int maxLength;
        private final IntSparseTable.Combiner combiner;

        public IntSparseTable(int[] array, IntSparseTable.Combiner combiner) {
            this.size = array.length;
            this.combiner = combiner;

            maxLength = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(Math.max(size - 1, 1)));
            table = new int[maxLength * size];
            System.arraycopy(array, 0, table, 0, size);

            rebuild();
        }

        public IntSparseTable(int size, IntSparseTable.Combiner combiner) {
            this.size = size;
            this.combiner = combiner;

            maxLength = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(Math.max(size - 1, 1)));
            table = new int[maxLength * size];
        }

        public void rebuild() {
            for (int l = 0; l + 1 < maxLength; l++) {
                for (int i = 0; i < size; i++) {
                    table[index(l + 1, i)] = table[index(l, i)];
                    if (i + (1 << l) < size) {
                        table[index(l + 1, i)] = combine(table[index(l + 1, i)], table[index(l, i + (1 << l))]);
                    }
                }
            }
        }

        private int index(int length, int start) {
            return length * size + start;
        }

        private int combine(int a, int b) {
            return combiner.combine(a, b);
        }

        public int queryOrDefault(int i, int j, int defaultValue) {
            if (!(0 <= i && i < j && j <= size))
                return defaultValue;
            int length = j - i - 1;
            int l = length == 0 ? 0 : Integer.numberOfTrailingZeros(Integer.highestOneBit(length));
            int left = table[index(l, i)];
            int right = table[index(l, j - (1 << l))];
            return combine(left, right);
        }

        public interface Combiner {
            int combine(int a, int b);

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

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}