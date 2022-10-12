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
        BTheNumberOfProducts solver = new BTheNumberOfProducts();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTheNumberOfProducts {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt() < 0 ? 1 : 0;
                // a[i]=0 means positive and 1 means negative.
            }

            int[] prefix = new int[n + 1];
            prefix[0] = 0;
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] ^ a[i];
            }

            long negativePrefixCount = 0;
            for (int i = 0; i <= n; i++) {
                if (prefix[i] == 1) {
                    negativePrefixCount++;
                }
            }
            long positivePrefixCount = n + 1 - negativePrefixCount;

            long positive = (negativePrefixCount) * (negativePrefixCount - 1) / 2 + positivePrefixCount * (positivePrefixCount - 1) / 2;
            long negative = (positivePrefixCount * negativePrefixCount);

            out.println(Util.join(negative, positive));
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
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
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