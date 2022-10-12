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
        EDominoPrinciple solver = new EDominoPrinciple();
        solver.solve(1, in, out);
        out.close();
    }

    static class EDominoPrinciple {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            EDominoPrinciple.Domino[] d = new EDominoPrinciple.Domino[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt(), h = in.nextInt();
                d[i] = new EDominoPrinciple.Domino(i, x, h);
            }

            Arrays.sort(d, Comparator.comparingInt(i -> i.x));

            IntMinSegmentTree tree = new IntMinSegmentTree(n);

            for (int i = 0; i < n; i++) {
                tree.update_LAZY(i, (n - i) - 1);
            }
            tree.rebuild();

            for (int i = n - 2; i >= 0; i--) {
                int fall = 1;
                int endIndex = binarySearch(d[i].x + d[i].h, i, n, d);
                if (endIndex > i + 1) {
                    fall = (n - i) - tree.query(i + 1, endIndex);
                }
                tree.update(i, (n - i) - fall);
            }

            int[] answer = new int[n];
            for (int i = 0; i < n; i++) {
                answer[d[i].i] = (n - i) - tree.get(i);
            }

            out.println(Util.join(answer));
        }

        public static int binarySearch(int threshold, int i, int n, EDominoPrinciple.Domino[] d) {
            int tooSmall = i, tooBig = n;

            if (d[tooBig - 1].x < threshold) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
                if (d[center].x < threshold) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
        }

        static class Domino {
            final int i;
            final int x;
            final int h;

            Domino(int i, int x, int h) {
                this.i = i;
                this.x = x;
                this.h = h;
            }

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

        public int get(int i) {
            return value[size + i];
        }

        public void update(int i, int v) {
            i += size;
            value[i] = v;
            while (i > 1) {
                i /= 2;
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
}