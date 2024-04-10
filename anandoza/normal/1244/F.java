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
        FChips solver = new FChips();
        solver.solve(1, in, out);
        out.close();
    }

    static class FChips {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(); // [3, 2e5]
            int k = in.nextInt(); // [1, 1e9]

            char[] input = in.next().toCharArray();
            boolean[] white = new boolean[n];
            for (int i = 0; i < n; i++) {
                white[i] = input[i] == 'W';
            }

            UnionFind uf = new UnionFind(n);
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                if (white[i] == white[j]) {
                    uf.union(i, j);
                }
            }

            if (uf.size(0) == n) {
                out.println(printable(white));
                return;
            }

            int offset = -1;
            for (int i = 0; i < n; i++) {
                if (uf.size(i) > 1 && uf.size((i + n - 1) % n) == 1) {
                    offset = i;
                    break;
                }
            }

            if (offset == -1) {
                if (k % 2 == 1) {
                    for (int i = 0; i < n; i++) {
                        white[i] ^= true;
                    }
                }
                out.println(printable(white));
                return;
            }

            boolean[] offWhite = new boolean[n];
            for (int i = 0; i < n; i++) {
                offWhite[i] = white[(i + offset) % n];
            }
            int[] size = new int[n];
            for (int i = 0; i < n; i++) {
                size[i] = uf.size((i + offset) % n);
            }

            for (int i = 0, j = 0; i < n; i = j) {
                while (j < n && size[i] == size[j])
                    j++;

                if (size[i] > 1)
                    continue;

                int left = (i + n - 1) % n;
                int right = j % n;

                for (int index = i; index < j; index++) {
                    int lDist = Math.abs(index - i);
                    int rDist = Math.abs(index - (j - 1));

                    if (lDist < k || rDist < k)
                        offWhite[index] = offWhite[lDist < rDist ? left : right];
                    else
                        offWhite[index] ^= (k % 2) == 1;
                }
            }

            for (int i = 0; i < n; i++) {
                white[i] = offWhite[(i + n - offset) % n];
            }

            out.println(printable(white));
        }

        private static String printable(boolean[] white) {
            StringBuilder sb = new StringBuilder();
            for (boolean x : white) {
                sb.append(x ? 'W' : 'B');
            }
            return sb.toString();
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