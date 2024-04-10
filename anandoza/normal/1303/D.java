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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DFillTheBag solver = new DFillTheBag();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFillTheBag {
        public static final int L = 64;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            long n = in.nextLong();
            int m = in.nextInt();
            int[] count = new int[L];
            for (int i = 0; i < m; i++) {
                int v = in.nextInt();
                count[Integer.numberOfTrailingZeros(v)]++;
            }

            long answer = 0;
            for (int i = 0; i < L; i++) {
                long b = 1L << i;

                if ((n & b) > 0) {
                    for (int j = i; j < L; j++) {
                        if (count[j] > 0) {
                            for (int k = j; k > i; k--) {
                                count[k]--;
                                count[k - 1] += 2;
                                answer++;
                            }
                            break;
                        }
                    }

                    if (count[i] == 0) {
                        out.println(-1);
                        return;
                    }
                    count[i]--;
                }
                if (i + 1 < L)
                    count[i + 1] += count[i] / 2;
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

    }
}