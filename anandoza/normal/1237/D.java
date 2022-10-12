import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        DBalancedPlaylist solver = new DBalancedPlaylist();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBalancedPlaylist {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);


            IntMinSparseTable min = new IntMinSparseTable(3 * n);
            for (int i = 0; i < 3 * n; i++) {
                min.update_LAZY(i, a[i % n]);
            }
            min.rebuild();

            IntMinSparseTable killers = new IntMinSparseTable(3 * n);
            for (int cool = 0; cool < 2 * n; cool++) {
                int finalCool = cool;
                int firstBad = BinarySearch.binarySearch(index -> {
                    if (index > 3 * n)
                        return true;

                    if (index <= finalCool)
                        return false;

                    return min.query(finalCool, index) * 2 < a[finalCool % n];
                });
                killers.update_LAZY(cool, firstBad - 1);
            }
            for (int cool = 2 * n; cool < 3 * n; cool++) {
                killers.update_LAZY(cool, Integer.MAX_VALUE);
            }
            killers.rebuild();

            int[] answer = new int[n];
            for (int start = 0; start < n; start++) {
                int finalStart = start;
                int end = BinarySearch.binarySearch(index -> {
                    if (index >= 3 * n)
                        return true;
                    if (index < finalStart)
                        return false;

                    return killers.query(finalStart, Math.min(2 * n, index) + 1) <= index;
                });

                if (end == 3 * n)
                    answer[start] = -1;
                else
                    answer[start] = end - start;
            }

            out.println(Util.join(answer));
        }

    }

    static class IntMinSparseTable {
        public int size;
        public int[] table;
        private int maxLength;

        public IntMinSparseTable(int[] array) {
            this.size = array.length;

            maxLength = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(Math.max(size - 1, 1)));
            table = new int[maxLength * size];
            System.arraycopy(array, 0, table, 0, size);

            rebuild();
        }

        public IntMinSparseTable(int size) {
            this.size = size;

            maxLength = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(Math.max(size - 1, 1)));
            table = new int[maxLength * size];
        }

        public void rebuild() {
            for (int l = 0; l + 1 < maxLength; l++) {
                for (int i = 0; i < size; i++) {
                    table[index(l + 1, i)] = table[index(l, i)];
                    if (i + (1 << l) < size) {
                        table[index(l + 1, i)] = Math.min(table[index(l + 1, i)], table[index(l, i + (1 << l))]);
                    }
                }
            }
        }

        public void update_LAZY(int i, int v) {
            table[i] = v;
        }

        private int index(int length, int start) {
            return length * size + start;
        }

        public int query(int i, int j) {
            Util.ASSERT(0 <= i && i < j && j <= size);
            int length = j - i - 1;
            int l = length == 0 ? 0 : Integer.numberOfTrailingZeros(Integer.highestOneBit(length));
            int left = table[index(l, i)];
            int right = table[index(l, j - (1 << l))];
            return Math.min(left, right);
        }

    }

    static class BinarySearch {
        public static int binarySearch(Function<Integer, Boolean> bigEnough) {
            int tooSmall = 0, tooBig;
            if (bigEnough.apply(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.apply(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.apply(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.apply(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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