import java.io.OutputStream;
import java.io.IOException;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt(), K = in.nextInt();

        char[][] A = new char[N + 2][M + 2];
        for (int i = 1; i <= N; ++i) {
            String S = in.nextString();
            for (int j = 1; j <= M; ++j)
                A[i][j] = S.charAt(j - 1);
        }

        if (N <= 2 || M <= 2) {
            out.println(0);
            return;
        }

        int[][] S = new int[N + 2][M + 2];

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                int x = 0;
                if (A[i][j] == '1' && A[i - 1][j] == '1' && A[i + 1][j] == '1' && A[i][j - 1] == '1' && A[i][j + 1] =='1')
                    x = 1;

                S[i][j] = x + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];

                //out.print("" + S[i][j] + ' ');
            }
           // out.println();
        }

        long Ans = 0;
        for (int i = 3; i <= N; ++i) {
            for (int j = 3; j <= M; ++j) {
                int up = 1;
                for (int k = j - 2; k >= 1; --k) {
                    while (up <= i && S[i - 1][j - 1] - S[up + 1][j - 1] - S[i - 1][k] + S[up + 1][k] >= K)
                        ++up;

                    if (S[i - 1][j - 1] - S[up][j - 1] - S[i - 1][k] + S[up][k] >= K)
                        Ans += up;
                }
            }
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