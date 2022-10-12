import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
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
        BXKSegments solver = new BXKSegments();
        solver.solve(1, in, out);
        out.close();
    }

    static class BXKSegments {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long x = in.nextInt();
            long k = in.nextInt();
            Integer[] a = in.readIntegerArray(n);

            if (k == 0) {
                Arrays.sort(a);
                long count = 0;
                long answer = 0;
                for (int i = 0, j = 0; i < n; i = j) {
                    while (j < n && a[i].equals(a[j]))
                        j++;

                    if (a[i] % x == 0 || (i > 0 && a[i] / x != a[i - 1] / x))
                        count = 0;
                    answer += count * (j - i);
                    if (a[i] % x != 0) {
                        count += (j - i);
                        answer += (long) (j - i) * (j - i);
                    }
                }

                out.println(answer);
                return;
            }

            HashMap<Long, Integer> count = new HashMap<>();
            for (int y : a) {
                long z = (y + x - 1) / x;
                count.merge(z, 1, Integer::sum);
            }

            HashMap<Long, Integer> count2 = new HashMap<>();
            for (int y : a) {
                long z = y / x;
                count2.merge(z, 1, Integer::sum);
            }

            long answer = 0;
            for (Map.Entry<Long, Integer> e : count.entrySet()) {
                long z = e.getKey();
                long w = z + (k - 1);
                long c = count2.getOrDefault(w, 0);
                answer += e.getValue() * c;
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

        public Integer[] readIntegerArray(int n) {
            Integer[] x = new Integer[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}