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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int[] count;
        int[] subtree;
        int[] left;
        int[] right;
        int current;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] S = in.next().toCharArray();
            int N = S.length, K = in.nextInt();

            boolean[][] isPal = new boolean[N][N];

            for (int i = 0; i < N; ++i) {
                for (int j = 0; i - j >= 0 && i + j < N; j += 2) {
                    if (S[i - j] != S[i + j]) break;
                    isPal[i - j][i + j] = true;
                }
                for (int j = 1; i - j >= 0 && i + j < N; j += 2) {
                    if (S[i - j] != S[i + j]) break;
                    isPal[i - j][i + j] = true;
                }
                for (int j = 0; i - j >= 0 && i + j + 1 < N; j += 2) {
                    if (S[i - j] != S[i + j + 1]) break;
                    isPal[i - j][i + j + 1] = true;
                }
                for (int j = 1; i - j >= 0 && i + j + 1 < N; j += 2) {
                    if (S[i - j] != S[i + j + 1]) break;
                    isPal[i - j][i + j + 1] = true;
                }
            }

            int M = N * (N + 1) / 2 + 3;
            subtree = new int[M];
            count = new int[M];
            left = new int[M];
            right = new int[M];
            current = 1;

            for (int i = 0; i < N; ++i)
                add(0, S, i, isPal[i]);

            StringBuffer ans = new StringBuffer();
            getKth(0, K, ans);

            out.println(ans.toString());
        }

        private int add(int node, char[] S, int index, boolean[] isPal) {
            int ret = 0;

            if (index > 0 && isPal[index - 1]) {
                count[node]++;
                ret++;
            }

            if (index != S.length) {
                if (S[index] == 'a') {
                    if (left[node] == 0) left[node] = current++;
                    ret += add(left[node], S, index + 1, isPal);
                } else {
                    if (right[node] == 0) right[node] = current++;
                    ret += add(right[node], S, index + 1, isPal);
                }
            }

            subtree[node] += ret;
            return ret;
        }

        private void getKth(int node, int K, StringBuffer dest) {
            if (K <= count[node]) return;
            K -= count[node];
            if (left[node] != 0 && K <= subtree[left[node]]) {
                dest.append('a');
                getKth(left[node], K, dest);
            } else {
                if (left[node] != 0) K -= subtree[left[node]];
                dest.append('b');
                getKth(right[node], K, dest);
            }
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