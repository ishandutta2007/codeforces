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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BBinaryPeriod solver = new BBinaryPeriod();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBinaryPeriod {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int[] t = in.readBitString();
            if (Util.min(t) == Util.max(t)) {
                out.println(Util.formatBitString(t));
                return;
            }

            for (int i = 0; i < t.length; i++) {
                out.print("01");
            }
            out.println();
        }

    }

    static class Util {
        public static String formatBitString(int[] t) {
            StringBuilder sb = new StringBuilder();
            for (int x : t)
                sb.append(x);
            return sb.toString();
        }

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

        public int[] readBitString() {
            char[] chars = next().toCharArray();
            int[] x = new int[chars.length];
            for (int i = 0; i < x.length; i++) {
                x[i] = chars[i] - '0';
            }
            return x;
        }

    }
}