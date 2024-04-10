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
        BBalancedTunnel solver = new BBalancedTunnel();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBalancedTunnel {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] b = in.readIntArray(n);

            for (int i = 0; i < n; i++) {
                a[i]--;
            }
            for (int i = 0; i < n; i++) {
                b[i]--;
            }

            int[] aInv = new int[n];
            for (int i = 0; i < n; i++) {
                aInv[a[i]] = i;
            }

            int[] bPerm = new int[n];
            for (int i = 0; i < n; i++) {
                bPerm[n - 1 - i] = aInv[b[i]];
            }

            int min = n;
            int answer = 0;
            for (int i = 0; i < n; i++) {
                if (bPerm[i] > min) {
                    answer++;
                }
                min = Math.min(min, bPerm[i]);
            }

            out.println(answer);
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