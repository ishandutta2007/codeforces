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
        CMessy solver = new CMessy();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMessy {
        PrintWriter out;
        static final char LEFT = '(';
        static final char RIGHT = ')';
        char[] s;
        List<String> output;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            this.out = out;

            int n = in.nextInt(), k = in.nextInt();
            s = in.next().toCharArray();
            output = new ArrayList<>();

            for (int l = 0, r = n - 1; l < r; l++, r--) {
                while (s[l] == LEFT)
                    l++;
                while (s[r] == RIGHT)
                    r--;

                if (l >= r)
                    break;

                reverse(l, r);
            }

            // now k=1

            int l = 1, r = n - 2;
            if (k % 2 == 0) {
                reverse(l++, n - 1);
                reverse(l++, n - 1);
                k--;
            }
            for (int i = 0; i < k - 1; i++) {
                reverse(l++, r--);
            }
            out.println(output.size());
            for (String x : output) {
                out.println(x);
            }
        }

        private void reverse(int l, int r) {
            for (int i = l, j = r; i < j; i++, j--) {
                Util.swap(s, i, j);
            }
            output.add(Util.join(l + 1, r + 1));
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

        public static void swap(char[] x, int i, int j) {
            char t = x[i];
            x[i] = x[j];
            x[j] = t;
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