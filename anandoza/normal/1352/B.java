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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BSameParitySummands solver = new BSameParitySummands();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSameParitySummands {
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            if (e(n, k) != null) {
                out.println(YES);
                out.println(Util.join(e(n, k)));
                return;
            }
            if (o(n, k) != null) {
                out.println(YES);
                out.println(Util.join(o(n, k)));
                return;
            }
            out.println(NO);
        }

        private List<Integer> o(int n, int k) {
            int r = n - 1 * (k - 1);
            if (r > 0 && r % 2 == 1) {
                List<Integer> answer = new ArrayList<>();
                for (int i = 0; i < k - 1; i++) {
                    answer.add(1);
                }
                answer.add(r);
                return answer;
            }
            return null;
        }

        private List<Integer> e(int n, int k) {
            int r = n - 2 * (k - 1);
            if (r > 0 && r % 2 == 0) {
                List<Integer> answer = new ArrayList<>();
                for (int i = 0; i < k - 1; i++) {
                    answer.add(2);
                }
                answer.add(r);
                return answer;
            }
            return null;
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

        private Util() {
        }

    }
}