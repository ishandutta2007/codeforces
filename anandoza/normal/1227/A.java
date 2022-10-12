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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AMathProblem solver = new AMathProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class AMathProblem {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] l = new int[n];
            int[] r = new int[n];
            for (int i = 0; i < n; i++) {
                l[i] = in.nextInt();
                r[i] = in.nextInt();
            }

            int answer = Util.max(l) - Util.min(r);
            answer = Math.max(0, answer);

            out.println(answer);
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
        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

        public static int min(int... x) {
            int min = Integer.MAX_VALUE;
            for (int i : x) {
                min = Math.min(i, min);
            }
            return min;
        }

    }
}