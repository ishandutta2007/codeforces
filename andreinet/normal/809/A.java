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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < a.length; ++i) {
                a[i] = in.nextInt();
            }
            ArraysUtils.randomShuffle(a);
            Arrays.sort(a);

            final int MOD = (int) 1e9 + 7;
            int[] pow2 = new int[a.length + 1];
            pow2[0] = 1;
            for (int i = 1; i < pow2.length; ++i) {
                pow2[i] = (int) ((long) pow2[i - 1] * 2 % MOD);
            }

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += (long) pow2[i] * a[i] % MOD;
                ans %= MOD;
                ans -= (long) (pow2[n - i - 1]) * a[i] % MOD;
                ans %= MOD;
            }

            ans %= MOD;
            if (ans < 0) {
                ans += MOD;
            }
            out.println(ans);
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
}