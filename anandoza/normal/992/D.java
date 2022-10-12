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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DNastyaAndAGame solver = new DNastyaAndAGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNastyaAndAGame {
        private static final long BOUND = 2_000_000_000_000_000_000L;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            long[] a = in.readLongArray(n);

            long[] d = new long[n];
            long[] c = new long[n];
            int size = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != 1) {
                    c[size] = 1;
                    d[size++] = a[i];
                    continue;
                }

                d[size] = 1;
                for (; i < n && a[i] == 1; i++) {
                    c[size]++;
                }
                i--;
                size++;
            }

            int answer = 0;
            for (int l = 0; l < size; l++) {
                for (int rep = 1; rep <= c[l]; rep++) {
                    long product = d[l];
                    long sum = rep * d[l];
                    for (int i = l + 1; i < size; i++) {
                        if (product > BOUND / d[i])
                            break;
                        product *= d[i];

                        if (d[i] != 1) {
                            sum += d[i];
                            if (product % k == 0 && product / k == sum) {
                                answer++;
                            }
                        } else {
                            if (product % k == 0) {
                                long s = product / k;
                                if (sum + 1 <= s && s <= sum + c[i]) {
                                    answer++;
                                }
                            }
                            sum += c[i];
                        }
                    }
                }
            }

            if (k == 1)
                answer += n;

            out.println(answer);
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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