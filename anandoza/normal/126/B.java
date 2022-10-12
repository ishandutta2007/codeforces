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
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BPassword solver = new BPassword();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPassword {
        static final String NO = "Just a legend";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String input = in.next();
            char[] s = input.toCharArray();
            int n = s.length;

            int[] z = ZAlgorithm.zAlgorithm(s);
            IntSparseTable max = new IntSparseTable(z, Integer::max);
            int answer = 0;
            for (int i = 2; i < n; i++) {
                if (i + z[i] == n) {
                    if (max.query(1, i) >= z[i]) {
                        answer = Math.max(answer, z[i]);
                    }
                }
            }

            out.println(answer > 0 ? input.substring(0, answer) : NO);
        }

    }

    static class ZAlgorithm {
        private ZAlgorithm() {
        }

        public static int[] zAlgorithm(char[] s) {
            int n = s.length;
            int[] z = new int[n];
            z[0] = n;

            for (int i = 1, l = -1, r = -1; i < n; i++) {
                z[i] = r > i ? Math.min(r - i, z[i - l]) : 0;
                while (i + z[i] < n && s[i + z[i]] == s[z[i]])
                    z[i]++;
                if (i + z[i] > r) {
                    l = i;
                    r = i + z[i];
                }
            }
            return z;
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

        public int query(int i, int j) {
            Util.ASSERT(0 <= i && i < j && j <= size);
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

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }
}