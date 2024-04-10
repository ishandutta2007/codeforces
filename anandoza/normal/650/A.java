import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashMap;
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
        AWatchmen solver = new AWatchmen();
        solver.solve(1, in, out);
        out.close();
    }

    static class AWatchmen {
        private static final long BIG = 2_000_000_010L;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] x = new int[n];
            int[] y = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }

            HashMap<Integer, Integer> sameX = new HashMap<>();
            for (int i = 0; i < n; i++) {
                sameX.put(x[i], 1 + sameX.getOrDefault(x[i], 0));
            }
            HashMap<Integer, Integer> sameY = new HashMap<>();
            for (int i = 0; i < n; i++) {
                sameY.put(y[i], 1 + sameY.getOrDefault(y[i], 0));
            }
            HashMap<Long, Integer> sameXY = new HashMap<>();
            for (int i = 0; i < n; i++) {
                long key = x[i] * BIG + y[i];
                sameXY.put(key, 1 + sameXY.getOrDefault(key, 0));
            }

            long answer = 0;
            for (int c : sameX.values()) {
                answer += nc2(c);
            }
            for (int c : sameY.values()) {
                answer += nc2(c);
            }
            for (int c : sameXY.values()) {
                answer -= nc2(c);
            }

            out.println(answer);
        }

        static long nc2(long n) {
            return n * (n - 1) / 2;
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