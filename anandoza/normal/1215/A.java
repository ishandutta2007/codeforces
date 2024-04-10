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
        AYellowCards solver = new AYellowCards();
        solver.solve(1, in, out);
        out.close();
    }

    static class AYellowCards {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a1 = in.nextInt(), a2 = in.nextInt();
            int k1 = in.nextInt(), k2 = in.nextInt();
            if (k1 > k2) {
                int t = k1;
                k1 = k2;
                k2 = t;
                t = a1;
                a1 = a2;
                a2 = t;
            } // now k1 <= k2

            int n = in.nextInt();

            int min = Math.max(0, n - ((k1 - 1) * a1 + (k2 - 1) * a2));
            int max;
            if (a1 * k1 >= n) {
                max = n / k1;
            } else {
                max = a1 + (n - a1 * k1) / k2;
            }

            out.println(Util.join(min, max));
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

    }
}