import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
        DAliceBobAndCandies solver = new DAliceBobAndCandies();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAliceBobAndCandies {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            ArrayDeque<Integer> q = new ArrayDeque<>();
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                q.addLast(in.nextInt());
            }

            int a = 0;
            int b = 0;
            int moves = 0;
            int prev = 0;
            while (!q.isEmpty()) {
                int cur = 0;
                while (!q.isEmpty() && cur <= prev) {
                    cur += q.pollFirst();
                }
                a += cur;
                if (cur > 0)
                    moves++;
                if (cur <= prev) {
                    break;
                }
                prev = cur;

                cur = 0;
                while (!q.isEmpty() && cur <= prev) {
                    cur += q.pollLast();
                }
                b += cur;
                if (cur > 0)
                    moves++;
                if (cur <= prev) {
                    break;
                }
                prev = cur;
            }

            out.println(Util.join(moves, a, b));
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
}