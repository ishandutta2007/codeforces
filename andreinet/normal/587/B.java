import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long l = in.nextLong();
            int k = in.nextInt();

            int[] A = new int[n];
            for (int i = 0; i < n; ++i) A[i] = in.nextInt();

            int[] sorted = A.clone();
            ArraysUtils.randomShuffle(sorted); // TEST 65 is against java sort, random shuffle so you don't get TLE
            Arrays.sort(sorted);

            final int Mod = (int) 1e9 + 7;

            int[] dp = new int[n];
            dp[0] = 1;

            int rem = (int) (l % n);
            long cnt = l / n % Mod + Mod;
            long rcnt = l / n;

            int ans = 0;
            for (int i = 1; i <= k && i <= rcnt + 1; ++i) {
                for (int j = 1; j < n; ++j)
                    dp[j] = (dp[j - 1] + dp[j]) % Mod;
                int[] ndp = new int[n];

                for (int j = 0; j < rem; ++j) {
                    int pos = search(sorted, A[j]);
                    ndp[pos] = (ndp[pos] + dp[pos]) % Mod;
                }

                for (int j = 0; j < n; ++j)
                    ans = (ans + ndp[j]) % Mod;

                for (int j = rem; j < n; ++j) {
                    int pos = search(sorted, A[j]);
                    ndp[pos] = (ndp[pos] + dp[pos]) % Mod;
                }

                if (i <= rcnt)
                    for (int j = 0; j < n; ++j)
                        ans = (int) ((ans + ndp[j] * (cnt - i + 1)) % Mod);

                dp = ndp;
            }

            out.println(ans);
        }

        private int search(int[] a, int e) {
            int pos = -1, step = 1;
            while (step < a.length) step *= 2;
            for (; step > 0; step /= 2) {
                if (pos + step < a.length && a[pos + step] <= e)
                    pos += step;
            }
            return pos;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class ArraysUtils {
        public static void randomShuffle(int[] A, int from, int to) {
            Random rnd = new Random();
            for (int i = from; i < to; ++i) {
                int pos = i + rnd.nextInt(to - i);
                swap(A, i, pos);
            }
        }

        public static void randomShuffle(int[] A) {
            randomShuffle(A, 0, A.length);
        }

        public static void swap(int[] A, int i, int j) {
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }

    }
}