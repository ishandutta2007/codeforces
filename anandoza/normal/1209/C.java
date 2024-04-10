import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CPaintTheDigits solver = new CPaintTheDigits();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPaintTheDigits {
        private static final boolean DEBUG = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String input = in.next();
            int[] d = new int[n];
            for (int i = 0; i < n; i++) {
                d[i] = input.charAt(i) - '0';
            }

            out.println(solve(n, d));
        }

        private static String solve(int n, int[] d) {
            IntMinSegmentTree min = new IntMinSegmentTree(n);
            IntMaxSegmentTree max = new IntMaxSegmentTree(n);
            for (int i = 0; i < n; i++) {
                min.update_LAZY(i, d[i]);
                max.update_LAZY(i, d[i]);
            }
            min.rebuild();
            max.rebuild();

            boolean[] one = new boolean[n];
            boolean[] two = new boolean[n];
            for (int i = 0; i < n; i++) {
                int minAfter = min.query(i + 1, n);
                if (minAfter < d[i]) {
                    two[i] = true;
                }

                int maxBefore = max.query(0, i);
                if (maxBefore > d[i]) {
                    one[i] = true;
                }
            }

            int maxOne = -1, minTwo = 10;
            for (int i = 0; i < n; i++) {
                if (one[i]) {
                    maxOne = Math.max(maxOne, d[i]);
                }
                if (two[i]) {
                    minTwo = Math.min(minTwo, d[i]);
                }
            }

            if (minTwo < maxOne) {
                return "-";
            }

            for (int i = 0; i < n; i++) {
                if (!one[i] && !two[i]) {
                    if (d[i] > minTwo) {
                        two[i] = true;
                    }
                    if (d[i] < maxOne) {
                        one[i] = true;
                    }
                }
            }

            StringBuilder answer = new StringBuilder();

            for (int i = 0; i < n; i++) {
                if (one[i] && two[i]) {
                    return "-";
                } else if (one[i]) {
                    answer.append('1');
                } else if (two[i]) {
                    answer.append('2');
                } else {
                    answer.append('2');
                }
            }

            if (DEBUG) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (d[i] < d[j] && answer.charAt(i) > answer.charAt(j) || d[i] > d[j] && answer.charAt(i) <= answer.charAt(j)) {
                            System.out.println("     ERROR");
                            System.out.println(Arrays.toString(d));
                            //Util.ASSERT(false);
                        }
                    }
                }
            }

            return answer.toString();
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

    static class IntMinSegmentTree {
        public int size;
        public int[] value;
        protected final int identityElement;

        public IntMinSegmentTree(int size) {
            this.size = size;
            value = new int[2 * size];
            this.identityElement = Integer.MAX_VALUE;
            Arrays.fill(value, identityElement);
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = Math.min(value[2 * i], value[2 * i + 1]);
            }
        }

        public void update_LAZY(int i, int v) {
            i += size;
            value[i] = v;
        }

        public int query(int i, int j) {
            int res_left = identityElement, res_right = identityElement;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1) {
                    res_left = Math.min(res_left, value[i++]);
                }
                if ((j & 1) == 1) {
                    res_right = Math.min(value[--j], res_right);
                }
            }
            return Math.min(res_left, res_right);
        }

    }

    static class IntMaxSegmentTree {
        public int size;
        public int[] value;
        protected final int identityElement;

        public IntMaxSegmentTree(int size) {
            this.size = size;
            value = new int[2 * size];
            this.identityElement = Integer.MIN_VALUE;
            Arrays.fill(value, identityElement);
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = Math.max(value[2 * i], value[2 * i + 1]);
            }
        }

        public void update_LAZY(int i, int v) {
            i += size;
            value[i] = v;
        }

        public int query(int i, int j) {
            int res_left = identityElement, res_right = identityElement;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1) {
                    res_left = Math.max(res_left, value[i++]);
                }
                if ((j & 1) == 1) {
                    res_right = Math.max(value[--j], res_right);
                }
            }
            return Math.max(res_left, res_right);
        }

    }
}