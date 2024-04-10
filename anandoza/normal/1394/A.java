import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        ABoboniuChatsWithDu solver = new ABoboniuChatsWithDu();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABoboniuChatsWithDu {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), d = in.nextInt(), m = in.nextInt();
            long[] a = in.readLongArray(n);
            Util.safeSort(a);
            long[] prefix = new long[n + 1];
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + a[i];
            }
            int firstMuzzle = n;
            for (int i = 0; i < n; i++) {
                if (a[i] > m) {
                    firstMuzzle = i;
                    break;
                }
            }
            int maxMuzzles = n - firstMuzzle;
            if (maxMuzzles == 0) {
                long answer = 0;
                for (long x : a)
                    answer += x;
                out.println(answer);
                return;
            }

            long answer = 0;
            for (int muzzles = 1; muzzles <= maxMuzzles; muzzles++) {
                long mostSkipped = (long) (muzzles) * (d + 1);
                long leastSkipped = (long) (muzzles - 1) * (d + 1) + 1;
                if (leastSkipped > n)
                    continue;
                if (mostSkipped < maxMuzzles)
                    continue;
                long score = 0;
                score += prefix[n] - prefix[n - muzzles];
                int remaining = (int) (leastSkipped - maxMuzzles);
                remaining = Math.max(remaining, 0);
                score += prefix[firstMuzzle] - prefix[remaining];

                answer = Math.max(answer, score);
            }
            out.println(answer);
        }

    }

    static class Util {
        public static void safeSort(long[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(long[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(long[] x, int i, int j) {
            long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        private Util() {
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