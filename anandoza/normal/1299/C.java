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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CWaterBalance solver = new CWaterBalance();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWaterBalance {
        double[] a;
        int n;
        UnionFind uf;
        int[] min;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            a = new double[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextDouble();
            }

            double[] answer = solveFaster();

            for (double x : answer) {
                out.println(x);
            }
        }

        private double[] solveFaster() {
            uf = new UnionFind(n);
            min = Permutations.identity(n);

            for (int i = 0; i < n; i++) {
                int l = i;
                while (l - 1 >= 0 && a[uf.rep(l - 1)] > a[uf.rep(l)]) {
                    merge(l - 1, l);
                    l = min[uf.rep(l)];
                }
            }

            double[] answer = new double[n];
            for (int i = 0; i < n; i++) {
                answer[i] = a[uf.rep(i)];
            }

            return answer;
        }

        private void merge(int i, int j) {
            double sum = a[uf.rep(i)] * uf.size(i) + a[uf.rep(j)] * uf.size(j);
            int mi = min[uf.rep(i)];
            uf.union(i, j);
            a[uf.rep(i)] = sum / uf.size(i);
            min[uf.rep(i)] = mi;
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }

    static class Permutations {
        public static int[] identity(int n) {
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
            return p;
        }

        private Permutations() {
        }

    }

    static class UnionFind {
        private int[] __rep;
        private int[] __size;

        public UnionFind(int n) {
            __rep = new int[n];
            __size = new int[n];
            for (int i = 0; i < n; i++) {
                __rep[i] = i;
                __size[i] = 1;
            }
        }

        public int rep(int x) {
            if (__rep[x] == x) {
                return x;
            }

            int r = rep(__rep[x]);
            __rep[x] = r;
            return r;
        }

        public int size(int x) {
            return __size[rep(x)];
        }

        public boolean union(int x, int y) {
            x = rep(x);
            y = rep(y);

            if (x == y) {
                return false;
            }

            if (size(x) < size(y)) {
                int t = x;
                x = y;
                y = t;
            }

            // now size(x) >= size(y)

            __rep[y] = x;
            __size[x] += __size[y];
            return true;
        }

    }
}