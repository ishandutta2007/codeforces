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
        ENewYearParties solver = new ENewYearParties();
        solver.solve(1, in, out);
        out.close();
    }

    static class ENewYearParties {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] x = in.readIntArray(n);
            int[] occ = new int[n + 2];
            for (int i : x) {
                occ[i]++;
            }

            int min = 0;
            for (int i = 0; i <= n + 1; i++) {
                if (occ[i] > 0) {
                    min++;
                    i += 2;
                }
            }

            for (int i = 0; i <= n; i++) {
                if (occ[i + 1] > 0 && occ[i] == 0) {
                    occ[i]++;
                    occ[i + 1]--;
                }
                if (occ[i] >= 2) {
                    occ[i + 1]++;
                    occ[i]--;
                }
            }

            int max = 0;
            for (int o : occ) {
                if (o > 0)
                    max++;
            }

            out.println(Util.join(min, max));
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}