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
        DPrefixesAndSuffixes solver = new DPrefixesAndSuffixes();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPrefixesAndSuffixes {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            final int n = s.length;

            int[] z = ZAlgorithm.zAlgorithm(s);

            List<String> answer = new ArrayList<>();
            IntSumSegmentTree count = new IntSumSegmentTree(n + 1);
            for (int i = 0; i < n; i++) {
                count.update_LAZY(z[i], 1 + count.get(z[i]));
            }
            count.rebuild();

            for (int i = n - 1; i >= 0; i--) {
                if (i + z[i] == n) {
                    answer.add(Util.join(z[i], count.query(z[i], n + 1)));
                }
            }

            out.println(answer.size());
            for (String x : answer) {
                out.println(x);
            }
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

    }

    static class ZAlgorithm {
        private ZAlgorithm() {
        }

        public static int[] zAlgorithm(char[] s) {
            int n = s.length;
            int[] z = new int[n];
            z[0] = n;

            for (int i = 1, l = -1, r = -1; i < n; i++) {
                z[i] = r > i ? Math.min(r - i, z[i - l]) : 0;
                while (i + z[i] < n && s[i + z[i]] == s[z[i]])
                    z[i]++;
                if (i + z[i] > r) {
                    l = i;
                    r = i + z[i];
                }
            }
            return z;
        }

    }

    static class IntSumSegmentTree {
        public int size;
        public int[] value;

        public IntSumSegmentTree(int size) {
            this.size = size;
            value = new int[2 * size];
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = value[2 * i] + value[2 * i + 1];
            }
        }

        public int get(int i) {
            return value[size + i];
        }

        public void update_LAZY(int i, int v) {
            i += size;
            value[i] = v;
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
}