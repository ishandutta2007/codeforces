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
        BUniversalSolution solver = new BUniversalSolution();
        solver.solve(1, in, out);
        out.close();
    }

    static class BUniversalSolution {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            char[] input = in.next().toCharArray();

            int r = 0, p = 0, s = 0;
            for (char x : input) {
                if (x == 'R')
                    r++;
                if (x == 'P')
                    p++;
                if (x == 'S')
                    s++;
            }

            int max = Util.max(r, p, s);
            char ans;
            if (max == r) {
                ans = 'P';
            } else if (max == p) {
                ans = 'S';
            } else {
                ans = 'R';
            }

            for (int i = 0; i < input.length; i++) {
                out.print(ans);
            }
            out.println();
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

        private Util() {
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
}