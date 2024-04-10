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
        CWetSharkAndFlowers solver = new CWetSharkAndFlowers();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWetSharkAndFlowers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int p = in.nextInt();
            double[] pr = new double[n + 1];
            for (int i = 0; i < n; i++) {
                int l = in.nextInt() - 1, r = in.nextInt();
                int good = r / p - l / p;
                int tot = r - l;
                pr[i] = (double) good / tot;
            }
            pr[n] = pr[0];

            double ans = 0;
            for (int i = 0; i < n; i++) {
                ans += 1 - (1 - pr[i]) * (1 - pr[i + 1]);
            }
            ans *= 2000;

            out.println(Util.formatDouble(ans));
        }

    }

    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
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