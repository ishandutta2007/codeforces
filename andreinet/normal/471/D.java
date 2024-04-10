import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();
        int[] A = new int[N + 2], B = new int[M + 2];

        for (int i = 1; i <= N; ++i) {
            A[i] = in.nextInt();
        }

        for (int i = 1; i <= M; ++i) {
            B[i] = in.nextInt();
        }

        if (M == 1) {
            out.println(N);
            return;
        }

        for (int i = 1; i < N; ++i)
            A[i] -= A[i + 1];

        for (int i = 1; i < M; ++i)
            B[i] -= B[i + 1];

        N--; M--;

        int[] P = new int[M + 2];

        B[M + 1] = 2000000005;
        for (int i = 2, k = 0; i <= M; ++i) {
            while (k > 0 && B[i] != B[k + 1])
                k = P[k];

            if (B[i] == B[k + 1])
                ++k;

            P[i] = k;
        }

        int ans = 0;
        for (int i = 1, k = 0; i <= N; ++i) {
            while (k > 0 && A[i] != B[k + 1])
                k = P[k];

            if (A[i] == B[k + 1])
                ++k;

            if (k == M)
                ++ans;
        }

        out.println(ans);
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