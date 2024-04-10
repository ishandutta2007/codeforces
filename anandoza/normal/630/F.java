import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        FSelectionOfPersonnel solver = new FSelectionOfPersonnel();
        solver.solve(1, in, out);
        out.close();
    }

    static class FSelectionOfPersonnel {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            BigInteger ans = BigInteger.ZERO;
            for (int i = 5; i <= 7; i++) {
                BigInteger p = BigInteger.ONE;
                for (long j = n; j >= n - (i - 1); j--) {
                    p = p.multiply(BigInteger.valueOf(j));
                }
                for (int j = 1; j <= i; j++) {
                    p = p.divide(BigInteger.valueOf(j));
                }
                ans = ans.add(p);
            }
            out.println(ans);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}