import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        BNewYearPermutation solver = new BNewYearPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class BNewYearPermutation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] p = in.readIntArray(n);

            UnionFind uf = new UnionFind(n);
            for (int i = 0; i < n; i++) {
                char[] row = in.next().toCharArray();
                for (int j = 0; j < n; j++) {
                    if (row[j] == '1') {
                        uf.union(i, j);
                    }
                }
            }

            List<Integer>[] sublists = new List[n];
            for (int i = 0; i < n; i++) {
                sublists[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; i++) {
                sublists[uf.rep(i)].add(i);
            }

            int[] answer = new int[n];
            for (List<Integer> sublist : sublists) {
                List<Integer> sorted = new ArrayList<>();
                for (int i : sublist) {
                    sorted.add(p[i]);
                }
                Collections.sort(sorted);

                int index = 0;
                for (int i : sublist) {
                    answer[i] = sorted.get(index++);
                }
            }

            out.println(Util.join(answer));
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