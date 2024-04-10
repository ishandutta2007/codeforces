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
        int N = in.nextInt(), K = in.nextInt();

        boolean[][] G = new boolean[N + 1][N + 1];
        int[][] A = new int[K][N + 1];

        for (int k = 0; k < K; ++k) {
            for (int i = 1; i <= N; ++i) {
                A[k][i] = in.nextInt();

                for (int j = 1; j < i; ++j)
                    G[A[k][j]][A[k][i]] = true;
            }
        }

        int[] Max = new int[N + 1];
        int Ans = 0;

        for (int i = 1; i <= N; ++i) {
            Max[A[0][i]] = 1;

            for (int j = 1; j < i; ++j) {
                if (!G[A[0][i]][A[0][j]])
                    Max[A[0][i]] = Math.max(Max[A[0][i]], Max[A[0][j]] + 1);
            }

            Ans = Math.max(Ans, Max[A[0][i]]);
        }

        out.println(Ans);
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