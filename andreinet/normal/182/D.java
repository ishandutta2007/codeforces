import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String S1 = in.next(), S2 = in.next();
            int N = S1.length(), M = S2.length();

            boolean[] equal = new boolean[N];
            for (int i = 0; i < N; ++i) {
                if (i >= M) break;
                equal[i] = (i == 0 || equal[i - 1]) && S1.charAt(i) == S2.charAt(i);
            }

            int[] P1 = getPi(S1), P2 = getPi(S2);
            int ans = 0;

            int d1, d2, l1, l2;

            if (N % (N - P1[N]) == 0) {
                d1 = N / (N - P1[N]);
                l1 = N - P1[N];
            } else {
                d1 = 1;
                l1 = N;
            }

            if (M % (M - P2[M]) == 0) {
                d2 = M / (M - P2[M]);
                l2 = M - P2[M];
            } else {
                d2 = 1;
                l2 = M;
            }

            for (int i = 1; i <= d1; ++i) {
                if (d1 % i == 0) {
                    int len = i * l1;
                    if (len % l2 == 0) {
                        int j = len / l2;
                        if (d2 % j == 0 && equal[len - 1]) ans++;
                    }
                }
            }

            out.println(ans);
        }

        private int[] getPi(String S) {
            int N = S.length();
            int[] P = new int[N + 1];

            for (int i = 2, k = 0; i <= N; ++i) {
                while (k > 0 && S.charAt(k) != S.charAt(i - 1))
                    k = P[k];

                if (S.charAt(k) == S.charAt(i - 1)) k++;
                P[i] = k;
            }
            return P;
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