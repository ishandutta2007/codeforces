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
        CNumberGame solver = new CNumberGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class CNumberGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();

            out.println(isWinning(n) ? "Ashishgup" : "FastestFinger");
        }

        private static boolean isWinning(int n) {
            if (n == 1)
                return false;

            if (n == 2)
                return true;

            if (n % 2 == 1) {
                return true; // go to 1
            }

            if (n % 4 == 0 && Integer.bitCount(n) != 1) {
                return true; // go to power of 2 >= 4
            }

            if (Integer.bitCount(n) == 1)
                return false;

            if (prime(n / 2))
                return false;

            return true;
        }

        private static boolean prime(int n) {
            if (n == 2)
                return true;
            if (n % 2 == 0)
                return false;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0)
                    return false;
            }
            return true;
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