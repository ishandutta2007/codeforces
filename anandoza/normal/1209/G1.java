import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
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
        G1IntoBlocksEasyVersion solver = new G1IntoBlocksEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class G1IntoBlocksEasyVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), unusedQ = in.nextInt();

            int[] a = in.readIntArray(n);

            out.println(solve(a));
        }

        private static int solve(int[] a) {
            int n = a.length;
            int K = 0;
            for (int i = 0; i < n; i++) {
                a[i]--; // now it's [0, K)
                K = Math.max(K, a[i] + 1);
            }

            UnionFind uf = new UnionFind(n);

            int[] first = new int[K];
            Arrays.fill(first, n);
            int[] last = new int[K];
            Arrays.fill(last, -1);
            int[] count = new int[K];
            for (int i = 0; i < n; i++) {
                int x = a[i];
                first[x] = Math.min(first[x], i);
                last[x] = Math.max(last[x], i);
                count[x]++;
            }

            G1IntoBlocksEasyVersion.Endpoint[] pointsBig = new G1IntoBlocksEasyVersion.Endpoint[2 * K];
            int numEndpoints = 0;
            for (int i = 0; i < K; i++) {
                if (last[i] == -1)
                    continue;
                pointsBig[numEndpoints++] = new G1IntoBlocksEasyVersion.Endpoint(first[i], true);
                pointsBig[numEndpoints++] = new G1IntoBlocksEasyVersion.Endpoint(last[i], false);
            }
            G1IntoBlocksEasyVersion.Endpoint[] points = new G1IntoBlocksEasyVersion.Endpoint[numEndpoints];
            System.arraycopy(pointsBig, 0, points, 0, numEndpoints);


            Arrays.sort(points, Comparator.<G1IntoBlocksEasyVersion.Endpoint>comparingInt(p -> p.i).thenComparingInt(p -> p.isStart ? 0 : 1));

            int intervalCount = 0;
            for (int i = 0, index = 0; i + 1 < n; i++) {
                while (index < points.length && points[index].i <= i) {
                    intervalCount += points[index++].isStart ? 1 : -1;
                }
                if (intervalCount > 0) {
                    uf.union(i, i + 1);
                }
            }

            int[] maxCount = new int[n];
            for (int i = 0; i < n; i++) {
                int rep = uf.rep(i);
                maxCount[rep] = Math.max(maxCount[rep], count[a[i]]);
            }

            int answer = 0;
            for (int i = 0; i < n; i++) {
                if (i == uf.rep(i)) {
                    answer += uf.size(i) - maxCount[i];
                }
            }

            return answer;
        }

        private static class Endpoint {
            final int i;
            final boolean isStart;

            private Endpoint(int i, boolean isStart) {
                this.i = i;
                this.isStart = isStart;
            }

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