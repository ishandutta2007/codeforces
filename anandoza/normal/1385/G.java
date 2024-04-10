import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
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
        GColumnsSwaps solver = new GColumnsSwaps();
        solver.solve(1, in, out);
        out.close();
    }

    static class GColumnsSwaps {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] p = new int[2][];
            for (int i = 0; i < 2; i++) {
                p[i] = Permutations.readPermutation(in, n);
            }

            BipartiteUnionFind uf = new BipartiteUnionFind(n);

            List<Pii>[] locations = Util.arrayOfLists(n);
            for (int row = 0; row < 2; row++) {
                for (int i = 0; i < n; i++) {
                    locations[p[row][i]].add(Pii.of(i, row));
                }
            }

            for (int i = 0; i < n; i++) {
                if (locations[i].size() != 2) {
                    out.println(-1);
                    return;
                }
                Pii a = locations[i].get(0);
                Pii b = locations[i].get(1);

                uf.union(a.first, b.first, a.second == b.second);
            }

            List<Integer> answer = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                boolean sameAsRoot = uf.sameAsRoot(i);
                boolean shouldUseSameAsRoot = uf.countSameAsRoot(i) < uf.size(i) - uf.countSameAsRoot(i);
                if (sameAsRoot == shouldUseSameAsRoot)
                    answer.add(i + 1);
            }

            out.println(answer.size());
            out.println(Util.join(answer));
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
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

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        private Util() {
        }

        public static <T> List<T>[] arrayOfLists(int n) {
            List<T>[] array = new List[n];
            for (int i = 0; i < n; i++) {
                array[i] = new ArrayList<>(0);
            }
            return array;
        }

    }

    static class Permutations {
        public static int[] readPermutation(InputReader in, int n) {
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }
            return p;
        }

        private Permutations() {
        }

    }

    static class BipartiteUnionFind {
        private final int[] __rep;
        private final int[] __size;
        private final boolean[] consistent;
        private final int[] countSameAsRoot;
        private final boolean[] differentFromRoot;

        public BipartiteUnionFind(int n) {
            __rep = new int[n];
            __size = new int[n];
            consistent = new boolean[n];
            countSameAsRoot = new int[n];
            differentFromRoot = new boolean[n];
            for (int i = 0; i < n; i++) {
                __rep[i] = i;
                __size[i] = 1;
                consistent[i] = true;
                countSameAsRoot[i] = 1;
                differentFromRoot[i] = false;
            }
        }

        public int rep(int x) {
            if (__rep[x] == x) {
                return x;
            }

            int r = rep(__rep[x]);
            differentFromRoot[x] ^= differentFromRoot[__rep[x]];
            __rep[x] = r;
            return r;
        }

        public int size(int x) {
            return __size[rep(x)];
        }

        public boolean sameAsRoot(int x) {
            rep(x);
            return !differentFromRoot[x];
        }

        public int countSameAsRoot(int x) {
            return countSameAsRoot[rep(x)];
        }

        public BipartiteUnionFind.Status union(int x, int y, boolean different) {
            int xRoot = rep(x);
            int yRoot = rep(y);

            if (xRoot == yRoot) {
                boolean good = !(different ^ differentFromRoot[x] ^ differentFromRoot[y]);
                if (!good)
                    consistent[xRoot] = false;
                return good ? BipartiteUnionFind.Status.FT : BipartiteUnionFind.Status.FF;
            }

            boolean areRootsDifferent = different ^ differentFromRoot[x] ^ differentFromRoot[y];

            x = xRoot;
            y = yRoot;
            if (size(x) < size(y)) {
                int t = x;
                x = y;
                y = t;
            }

            __rep[y] = x;
            __size[x] += __size[y];
            consistent[x] &= consistent[y];
            differentFromRoot[y] = areRootsDifferent;
            if (areRootsDifferent)
                countSameAsRoot[x] += __size[y] - countSameAsRoot[y];
            else
                countSameAsRoot[x] += countSameAsRoot[y];

            return BipartiteUnionFind.Status.TT;
        }

        public static class Status {
            public static final BipartiteUnionFind.Status TT = new BipartiteUnionFind.Status(true, true);
            public static final BipartiteUnionFind.Status FT = new BipartiteUnionFind.Status(false, true);
            public static final BipartiteUnionFind.Status FF = new BipartiteUnionFind.Status(false, false);
            public final boolean unionSucceeded;
            public final boolean consistent;

            private Status(boolean unionSucceeded, boolean consistent) {
                this.unionSucceeded = unionSucceeded;
                this.consistent = consistent;
            }

            public boolean equals(Object o) {
                if (this == o)
                    return true;
                if (o == null || getClass() != o.getClass())
                    return false;
                BipartiteUnionFind.Status status = (BipartiteUnionFind.Status) o;
                return unionSucceeded == status.unionSucceeded && consistent == status.consistent;
            }

            public int hashCode() {
                return Objects.hash(unionSucceeded, consistent);
            }

        }

    }
}