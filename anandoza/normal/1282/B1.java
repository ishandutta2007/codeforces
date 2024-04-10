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
        B2KForThePriceOfOneHardVersion solver = new B2KForThePriceOfOneHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class B2KForThePriceOfOneHardVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long p = in.nextLong();
            int k = in.nextInt();
            Long[] a = in.readLongObjectArray(n);

            Arrays.sort(a);
            int answer = 0;
            for (int i = k - 1; i < n; i += k) {
                if (a[i] > p)
                    break;
                p -= a[i];
                answer += k;
            }

            long newAnswer = answer;
            for (int i = 0; i < k && i + answer < n; i++) {
                long cost = 0;
                cost += a[i];
                for (int j = i + k; j <= i + answer; j += k) {
                    cost += a[j] - a[j - 1];
                }
                if (cost > p) {
                    break;
                }
                p -= cost;
                newAnswer++;
            }
            out.println(newAnswer);
//        out.println(p + " " + Arrays.toString(a));
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

        public Long[] readLongObjectArray(int n) {
            Long[] x = new Long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}