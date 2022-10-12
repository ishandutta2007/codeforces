import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
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
        EMinimizingDifference solver = new EMinimizingDifference();
        solver.solve(1, in, out);
        out.close();
    }

    static class EMinimizingDifference {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long k = in.nextLong();
            int[] a = in.readIntArray(n);

            TreeMap<Long, Integer> count = new TreeMap<>();
            for (long x : a) {
                count.put(x, 1 + count.getOrDefault(x, 0));
            }

            while (k > 0) {
                if (count.size() <= 1) {
                    break;
                }

                Entry<Long, Integer> firstEntry = count.firstEntry();
                Entry<Long, Integer> lastEntry = count.lastEntry();

                long prevK = k;
                if (firstEntry.getValue() < lastEntry.getValue()) {
                    long key = firstEntry.getKey();
                    int value = firstEntry.getValue();
                    count.pollFirstEntry();
                    if ((count.firstKey() - key) * value > k) {
                        count.put(key + k / value, value);
                        k -= (k / value) * value;
                    } else {
                        count.put(count.firstKey(), count.firstEntry().getValue() + value);
                        k -= (count.firstKey() - key) * value;
                    }
                } else {
                    long key = lastEntry.getKey();
                    int value = lastEntry.getValue();
                    count.pollLastEntry();
                    if ((key - count.lastKey()) * value > k) {
                        count.put(key - k / value, value);
                        k -= (k / value) * value;
                    } else {
                        count.put(count.lastKey(), count.lastEntry().getValue() + value);
                        k -= (key - count.lastKey()) * value;
                    }
                }

                if (prevK == k)
                    break;
            }

            long answer = count.lastKey() - count.firstKey();

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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}