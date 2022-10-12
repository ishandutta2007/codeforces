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
        CRoundCorridor solver = new CRoundCorridor();
        solver.solve(1, in, out);
        out.close();
    }

    static class CRoundCorridor {
        BigInteger n;
        BigInteger m;
        BigInteger g;
        BigInteger nFactor;
        BigInteger mFactor;
        InputReader in;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            n = new BigInteger(in.next());
            m = new BigInteger(in.next());
            int q = in.nextInt();

            g = n.gcd(m);
            nFactor = n.divide(g);
            mFactor = m.divide(g);

            for (int i = 0; i < q; i++) {
                BigInteger start = read();
                BigInteger end = read();

                boolean answer = start.equals(end);

                out.println(answer ? "YES" : "NO");
            }
        }

        private BigInteger read() {
            boolean inner = in.nextInt() == 1;
            BigInteger input = new BigInteger(in.next()).subtract(BigInteger.ONE);
            if (inner) {
                return input.divide(nFactor);
            } else {
                return input.divide(mFactor);
            }
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