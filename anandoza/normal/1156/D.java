import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
        D01Tree solver = new D01Tree();
        solver.solve(1, in, out);
        out.close();
    }

    static class D01Tree {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            UnionFind zero = new UnionFind(n);
            UnionFind one = new UnionFind(n);

            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int c = in.nextInt();
                if (c == 0)
                    zero.union(a, b);
                else
                    one.union(a, b);
            }

            HashSet<Integer>[] onesReachableByZeros = new HashSet[n];
            for (int i = 0; i < n; i++) {
                onesReachableByZeros[i] = new HashSet<>();
            }

            for (int i = 0; i < n; i++) {
                onesReachableByZeros[zero.rep(i)].add(one.rep(i));
            }

            long answer = 0;
            for (int i = 0; i < n; i++) {
                if (zero.rep(i) == i) {
                    for (int j : onesReachableByZeros[i]) {
                        answer += ((long) zero.size(i)) * one.size(j);
                    }
                    answer -= zero.size(i);
                }
            }

            out.println(answer);
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

        public void union(int x, int y) {
            x = rep(x);
            y = rep(y);

            if (x == y) {
                return;
            }

            if (size(x) < size(y)) {
                int t = x;
                x = y;
                y = t;
            }

            // now size(x) >= size(y)

            __rep[y] = x;
            __size[x] += __size[y];
        }

    }
}