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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DUnshufflingADeck solver = new DUnshufflingADeck();
        solver.solve(1, in, out);
        out.close();
    }

    static class DUnshufflingADeck {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = Permutations.readPermutation(in, n);

            if (n == 1) {
                out.println(0);
                return;
            }
            boolean reverse = n % 2 == 0;
            if (reverse) {
                Util.reverse(a);
            }

            List<List<Integer>> ops = new ArrayList<>();
            if (a[n - 1] == 0) {
                List<Integer> l = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    l.add(1);
                }
                ops.add(l);
                reverse ^= true;
                Util.reverse(a);
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = i; j < n; j++) {
                    if (a[j] == i) {
                        Util.reverse(a, i, j + 1);
                        ops.add(new ArrayList<>());
                        for (int k = 0; k < i; k++) {
                            ops.get(ops.size() - 1).add(1);
                        }
                        ops.get(ops.size() - 1).add(j + 1 - i);
                        for (int k = j + 1; k < n; k++) {
                            ops.get(ops.size() - 1).add(1);
                        }
                        break;
                    }
                }
            }

            out.println(ops.size());
            boolean parity = false;
            for (List<Integer> op : ops) {
                if (parity ^ reverse)
                    Collections.reverse(op);
                out.println(op.size() + " " + Util.join(op));
                parity ^= true;
            }
        }

    }

    static class Permutations {
        public static int[] readPermutation(InputReader in, int n) {
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }
            return p;
        }

        private Permutations() {
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(int[] x, int l, int r) {
            for (int i = l, j = r - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        public static void reverse(int[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        private Util() {
        }

    }
}