import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        APrimeMinister solver = new APrimeMinister();
        solver.solve(1, in, out);
        out.close();
    }

    static class APrimeMinister {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n - 1];
            int alice = in.nextInt();
            for (int i = 0; i < n - 1; i++) {
                a[i] = in.nextInt();
            }

            int coal = 0;
            int tot = 0;

            coal += alice;
            tot += alice;

            List<Integer> c = new ArrayList<>();
            c.add(1); // alice
            for (int i = 0; i < n - 1; i++) {
                if (2 * a[i] <= alice) {
                    coal += a[i];
                    c.add(i + 2);
                }
                tot += a[i];
            }

            if (coal * 2 > tot) {
                out.println(c.size());
                for (int x : c)
                    out.print(x + " ");
            } else
                out.println(0);
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