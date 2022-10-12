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
        CInfiniteFence solver = new CInfiniteFence();
        solver.solve(1, in, out);
        out.close();
    }

    static class CInfiniteFence {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }

        }

        private void solve(InputReader in, PrintWriter out) {
            int r = in.nextInt(), b = in.nextInt(), k = in.nextInt();
            int g = NumberTheory.gcd(r, b);
            r /= g;
            b /= g;
            if (r < b) {
                int t = r;
                r = b;
                b = t;
            }
            // now r >= b

            boolean die = 1 + (r - 2) / b >= k;
            die |= k == 1;

            out.println(die ? "REBEL" : "OBEY");
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

    static class NumberTheory {
        public static int gcd(int a, int b) {
            int c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
        }

    }
}