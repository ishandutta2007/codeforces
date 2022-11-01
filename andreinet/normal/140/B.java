import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Popa Andrei
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
}

class TaskB {
    private static final int Inf = 0x3f3f3f3f;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();

        int[][] A = new int[N][N];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                A[i][j] = in.nextInt();

        int[] Pos = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            int x = in.nextInt();
            Pos[x] = i;
        }

        SegmentTree Mins = new SegmentTree(Pos);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == i + 1)
                    continue;

                int x = i + 1 < A[i][j] ? Math.min(Mins.query(1, i), Mins.query(i + 2, A[i][j])): Mins.query(1, A[i][j]);
                if (x >= Pos[A[i][j]]) {
                    out.print("" + A[i][j] + ' ');
                    break;
                }
            }
        }

        out.println();
    }

    private static class SegmentTree {
        private int[] tree;
        private int N;

        private SegmentTree(int[] A) {
            for (N = 1; N < A.length; N *= 2);
            tree = new int[2 * N];
            Arrays.fill(tree, Inf);

            for (int i = 0; i < A.length; ++i)
                tree[i + N] = A[i];

            for (int i = N - 1; i > 0; --i) {
                tree[i] = Math.min(tree[2 * i], tree[2 * i + 1]);
            }
        }

        public int query(int left, int right) {
            if (left > right)
                return Inf;
            
            left = N + Math.max(left, 0);
            right = N + Math.min(right, N - 1);
            int ret = Inf;

            while (left <= right) {
                ret = Math.min(ret, Math.min(tree[left], tree[right]));
                left = (left + 1) / 2;
                right = (right - 1) / 2;
            }
            
            return ret;
        }
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String nextString() {
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