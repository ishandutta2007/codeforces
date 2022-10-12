import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        ELetThemSlide solver = new ELetThemSlide();
        solver.solve(1, in, out);
        out.close();
    }

    static class ELetThemSlide {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int w = in.nextInt();

            int[][] a = new int[n][];
            for (int i = 0; i < n; i++) {
                int s = in.nextInt();
                a[i] = in.readIntArray(s);
            }

            long[] diffs = new long[w];

            long[] values = new long[w];

            for (int[] row : a) {
                int l = row.length;

                IntMaxSegmentTree max = new IntMaxSegmentTree(l);
                for (int i = 0; i < l; i++) {
                    max.update_LAZY(i, row[i]);
                }
                max.rebuild();

                for (int wIndex = 0; wIndex < w; wIndex++) {
                    values[wIndex] = max.query(Math.max(0, l - (w - wIndex)), Math.min(l, wIndex + 1));
                    if (values[wIndex] < 0) {
                        if (wIndex >= l || w - (wIndex + 1) >= l) {
                            values[wIndex] = 0;
                        }
                    }

                    if (wIndex == l) {
                        wIndex = Math.max(wIndex, w - l - 2);
                    }
                }

                diffs[0] += values[0];
                for (int wIndex = 1; wIndex < w; wIndex++) {
                    if (wIndex == w - l - 1) {
                        diffs[wIndex] += values[wIndex] - values[Math.min(l, wIndex - 1)];
                    } else {
                        diffs[wIndex] += values[wIndex] - values[wIndex - 1];
                    }
                    if (wIndex == l) {
                        wIndex = Math.max(wIndex, w - l - 2);
                    }
                }
            }

            long[] answer = new long[w];
            answer[0] = diffs[0];
            for (int i = 1; i < w; i++) {
                answer[i] = answer[i - 1] + diffs[i];
            }
            out.println(Util.join(answer));
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

    static class Util {
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

    }
}