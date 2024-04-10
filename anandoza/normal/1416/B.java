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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BMakeThemEqual solver = new BMakeThemEqual();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMakeThemEqual {
        PrintWriter out;
        int n;
        int[] a;
        List<String> ops;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.out = out;
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in);
            }
        }

        private void solve() {
            int target = 0;
            for (int x : a) {
                target += x;
            }
            target /= n;

            ops = new ArrayList<>();

            for (int i = 1; i < n; i++) {
                f(i, 1, a[i] / i);
                int next = a[i + 1] % (i + 1);
                int need = ((i + 1) - next) % (i + 1);
                f(1, i + 1, need);
            }
            f(n, 1, a[n] / n);

            for (int i = 2; i <= n; i++) {
                f(1, i, target);
            }

            for (int i = 1; i <= n; i++) {
                Util.ASSERT(a[i] == target);
            }
        }

        private void solve(InputReader in) {
            n = in.nextInt();
            a = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            int sum = 0;
            for (int x : a) {
                sum += x;
            }
            if (sum % n != 0) {
                out.println(-1);
                return;
            }

            solve();

            out.println(ops.size());
            for (String s : ops) {
                out.println(s);
            }
        }

        private void f(int i, int j, int x) {
            ops.add(Util.join(i, j, x));
            a[i] -= x * i;
            a[j] += x * i;
            Util.ASSERT(a[i] >= 0);
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }
}