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
        DDrEvilUnderscores solver = new DDrEvilUnderscores();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDrEvilUnderscores {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            List<Integer> a = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                a.add(in.nextInt());
            }

            int answer = f(a, 1 << 29);

            out.println(answer);
        }

        private static int f(List<Integer> a, int bit) {
            if (bit == 0)
                return 0;

            int res = 0;
            List<Integer> on = new ArrayList<>();
            List<Integer> off = new ArrayList<>();
            for (int x : a) {
                if ((x & bit) > 0)
                    on.add(x);
                else
                    off.add(x);
            }
            if (on.isEmpty()) {
                res |= f(a, bit / 2);
            } else if (off.isEmpty()) {
                res |= f(a, bit / 2);
            } else {
                res |= bit;
                res |= Math.min(f(on, bit / 2), f(off, bit / 2));
            }
            return res;
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