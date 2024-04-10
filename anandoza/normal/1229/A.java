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
        AMarcinAndTrainingCamp solver = new AMarcinAndTrainingCamp();
        solver.solve(1, in, out);
        out.close();
    }

    static class AMarcinAndTrainingCamp {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.readLongArray(n);
            long[] b = in.readLongArray(n);

            HashMap<Long, Integer> count = new HashMap<>();
            for (long x : a) {
                count.put(x, 1 + count.getOrDefault(x, 0));
            }

            long answer = 0;
            boolean[] use = new boolean[n];
            for (long x : count.keySet()) {
                if (count.get(x) > 1) {
                    for (int i = 0; i < n; i++) {
                        if ((a[i] & x) == a[i]) {
                            use[i] = true;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (use[i]) {
                    answer += b[i];
                }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}