import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BSashaAndMagneticMachines solver = new BSashaAndMagneticMachines();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSashaAndMagneticMachines {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();

            Arrays.sort(a);

            int ans = 0;
            for (int x : a) ans += x;

            int diff = 0;
            for (int x : a) {
                for (int i = 2; i <= x; i++) {
                    if (x % i == 0) {
                        diff = Math.max((x - x / i) - (i - 1) * a[0], diff);
                    }
                }
            }

            ans -= diff;

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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}