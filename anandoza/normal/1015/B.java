import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BObtainingTheString solver = new BObtainingTheString();
        solver.solve(1, in, out);
        out.close();
    }

    static class BObtainingTheString {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();

            if (!same(s, t)) {
                out.println(-1);
                return;
            }

            List<Integer> fromS = f(s);
            List<Integer> fromT = f(t);
            Collections.reverse(fromT);
            fromS.addAll(fromT);

            out.println(fromS.size());
            out.println(Util.join(fromS));
        }

        private List<Integer> f(char[] s) {
            List<Integer> ops = new ArrayList<>();
            while (true) {
                boolean change = false;
                for (int i = 0; i + 1 < s.length; i++) {
                    if (s[i] > s[i + 1]) {
                        change = true;
                        Util.swap(s, i, i + 1);
                        ops.add(i + 1);
                    }
                }
                if (!change)
                    break;
            }

            return ops;
        }

        private boolean same(char[] s, char[] t) {
            char[] a = s.clone(), b = t.clone();
            Arrays.sort(a);
            Arrays.sort(b);
            return Arrays.equals(a, b);
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

        public static void swap(char[] x, int i, int j) {
            char t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        private Util() {
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