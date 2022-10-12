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
        CThePartyAndSweets solver = new CThePartyAndSweets();
        solver.solve(1, in, out);
        out.close();
    }

    static class CThePartyAndSweets {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int B = in.nextInt();
            int G = in.nextInt();

            long[] b = new long[B];
            long[] g = new long[G];

            for (int i = 0; i < b.length; i++) {
                b[i] = in.nextInt();
            }
            Arrays.sort(b);
            for (int i = 0; i < g.length; i++) {
                g[i] = in.nextInt();
            }
            Arrays.sort(g);


            long maxBoy = b[b.length - 1];
            long minGirl = g[0];

            long ans = 0;
            if (minGirl < maxBoy) {
                ans = -1;
            } else if (minGirl == maxBoy) {
                for (long boy : b) {
                    ans += boy * G;
                }
                for (long girl : g) {
                    ans += (girl - maxBoy);
                }
            } else {
                for (long boy : b) {
                    ans += boy * G;
                }
                for (long girl : g) {
                    ans += (girl - maxBoy);
                }
                ans += b[b.length - 1] - b[b.length - 2];
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}