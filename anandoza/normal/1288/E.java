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
        EMessengerSimulator solver = new EMessengerSimulator();
        solver.solve(1, in, out);
        out.close();
    }

    static class EMessengerSimulator {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] a = in.readIntArray(m);
            for (int i = 0; i < m; i++) {
                a[i]--;
            }

            int[] min = new int[n];
            for (int i = 0; i < n; i++) {
                min[i] = i;
            }
            for (int x : a) {
                min[x] = 0;
            }

            int[] max = max(a, n);

            for (int i = 0; i < n; i++) {
                out.println(Util.join(min[i] + 1, max[i] + 1));
            }
        }

        private static int[] max(int[] input, int n) {
            IntSumSegmentTree st = new IntSumSegmentTree(input.length + n);

            int[] pos = new int[n];
            for (int i = 0; i < n; i++) {
                pos[i] = n - 1 - i;
                st.update(pos[i], 1);
            }

            int[] max = new int[n];

            int index = n;
            for (int i : input) {
                max[i] = Math.max(max[i], st.query(pos[i] + 1, index));
                st.update(pos[i], 0);
                st.update(index, 1);
                pos[i] = index;
                index++;
            }

            for (int i = 0; i < n; i++) {
                max[i] = Math.max(max[i], st.query(pos[i] + 1, st.size));
            }

            return max;
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

        private Util() {
        }

    }

    static class IntSumSegmentTree {
        public int size;
        public int[] value;

        public IntSumSegmentTree(int size) {
            this.size = size;
            value = new int[2 * size];
        }

        public void update(int i, int v) {
            i += size;
            value[i] = v;
            while (i > 1) {
                i /= 2;
                value[i] = value[2 * i] + value[2 * i + 1];
            }
        }

        public int query(int i, int j) {
            int res_left = 0, res_right = 0;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1) {
                    int b = value[i++];
                    res_left = res_left + b;
                }
                if ((j & 1) == 1) {
                    int a = value[--j];
                    res_right = a + res_right;
                }
            }
            return res_left + res_right;
        }

    }
}