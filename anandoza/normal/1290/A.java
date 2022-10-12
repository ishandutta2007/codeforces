import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.ArrayDeque;
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
        AMindControl solver = new AMindControl();
        solver.solve(1, in, out);
        out.close();
    }

    static class AMindControl {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            k = Math.min(k, m - 1);
            int[] a = in.readIntArray(n);

            Queue<Integer> poss = new ArrayDeque<>();
            for (int i = 0; i < m; i++) {
                //System.out.println(i + " , " + (n - m + i));
                poss.add(Math.max(a[i], a[n - m + i]));
            }
            //System.out.println(poss);
            IntMinSparseTable min = new IntMinSparseTable(m);
            for (int i = 0; i < m; i++) {
                min.update_LAZY(i, poss.poll());
            }
            min.rebuild();

            int answer = Integer.MIN_VALUE;
            for (int i = 0; i <= k; i++) {
                //System.out.println(i + " " + (m - k + i));
                answer = Math.max(answer, min.query(i, m - k + i));
            }
            //System.out.println("ANSWER");

            out.println(answer);
        }

    }

    static class Util {
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
}