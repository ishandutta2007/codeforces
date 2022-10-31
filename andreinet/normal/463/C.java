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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();

        int[][] A = new int[N + 2][N + 2];
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                A[i][j] = in.nextInt();

        long[] Sumd1 = new long[3 * N], Sumd2 = new long[3 * N];
        int Offset = N + 2;

        long[] S = new long[2];
        S[0] = S[1] = -1;

        int[][] coord = new int[2][2];

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                Sumd1[Offset + i - j] += A[i][j];
                Sumd2[i + j] += A[i][j];
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                int u = ((i + j) & 1);
                long s = Sumd1[Offset + i - j] + Sumd2[i + j] - A[i][j];

                if (s > S[u]) {
                    S[u] = s;
                    coord[u][0] = i;
                    coord[u][1] = j;
                }
            }
        }

        out.println(S[0] + S[1]);
        out.println("" + coord[0][0] + ' ' + coord[0][1] + ' ' + coord[1][0] + ' ' + coord[1][1]);
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