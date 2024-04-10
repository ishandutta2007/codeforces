import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        ENewYearDomino solver = new ENewYearDomino();
        solver.solve(1, in, out);
        out.close();
    }

    static class ENewYearDomino {
        int n;
        int[] x;
        int[] h;
        TreeSet<Integer> gaps;
        IntSumBIT st;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            x = new int[n];
            h = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                h[i] = in.nextInt();
            }
            int lastUnused = n - 1;

            int queryCount = in.nextInt();
            Pii[] queries = new Pii[queryCount];
            for (int i = 0; i < queryCount; i++) {
                queries[i] = Pii.of(in.nextInt() - 1, in.nextInt() - 1); // inclusive
            }
            Integer[] indices = new Integer[queryCount];
            for (int i = 0; i < queryCount; i++) {
                indices[i] = i;
            }
            Arrays.sort(indices, Comparator.comparingInt(i -> -queries[i].first));

            st = new IntSumBIT(n);
            for (int i = 1; i < n; i++) {
                st.update(i, Math.max(0, x[i] - (x[i - 1] + h[i - 1])));
            }
            gaps = new TreeSet<>();
            for (int i = 1; i < n; i++) {
                gaps.add(i);
            }

            int[] answer = new int[queryCount];
            for (int index : indices) {
                Pii q = queries[index];
                while (lastUnused >= q.first) {
                    add(lastUnused--);
                }

                answer[index] = st.query(q.first + 1, q.second + 1);
            }
            for (int x : answer) {
                out.println(x);
            }
        }

        private void add(int i) {
            int r = x[i] + h[i];
            Integer cur = gaps.higher(i);
            while (cur != null && x[cur] <= r) {
                st.update(cur, 0);
                gaps.remove(cur);
                cur = gaps.higher(cur);
            }

            if (cur != null) {
                st.update(cur, Math.min(st.get(cur), x[cur] - r));
            }
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

        public int get(int i) {
            return query(i, i + 1);
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