import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        DYetAnotherMonsterKillingProblem solver = new DYetAnotherMonsterKillingProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class DYetAnotherMonsterKillingProblem {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int m = in.nextInt();
            Pair<Integer, Integer>[] heroes = new Pair[m];
            for (int i = 0; i < m; i++) {
                int power = in.nextInt();
                int endurance = in.nextInt();
                heroes[i] = Pair.of(power, endurance);
            }
            Arrays.sort(heroes, Comparator.comparingInt((Pair<Integer, Integer> h) -> -h.first).thenComparingInt(h -> -h.second));

//        int bestEndurance = 0;
//        List<Pair<Integer, Integer>> usefulHeroes = new ArrayList<>();
//        for (Pair<Integer, Integer> h : heroes) {
//            if (h.second > bestEndurance) {
//                usefulHeroes.add(h);
//                bestEndurance = h.second;
//            }
//        }
            IntSparseTable maxPowerByEndurance = new IntSparseTable(n + 1, Math::max);
            for (Pair<Integer, Integer> h : heroes) {
                if (h.first > maxPowerByEndurance.get(h.second))
                    maxPowerByEndurance.update_LAZY(h.second, h.first);
            }
            maxPowerByEndurance.rebuild();

            int lastDefeated = -1;
            int days = 0;
            while (lastDefeated < n - 1) {
                int next = lastDefeated;
                int maxEnemy = -1;
                for (int i = lastDefeated + 1; i < n; i++) {
                    maxEnemy = Math.max(maxEnemy, a[i]);
                    if (maxPowerByEndurance.query(i - lastDefeated, n + 1) < maxEnemy)
                        break;
                    next = i;
                }
                if (lastDefeated == next) {
                    out.println(-1);
                    return;
                }
                lastDefeated = next;
                days++;
            }

            out.println(days);
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

        public void update_LAZY(int i, int v) {
            table[i] = v;
        }

        private int index(int length, int start) {
            return length * size + start;
        }

        private int combine(int a, int b) {
            return combiner.combine(a, b);
        }

        public int get(int i) {
            return table[i];
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

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }
}