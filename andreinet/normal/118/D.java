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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N1 = in.nextInt(), N2 = in.nextInt(), K1 = in.nextInt(), K2 = in.nextInt();
        final int Mod = 100000000;
        
        K1 = Math.min(N1, K1);
        K2 = Math.min(N2, K2);

        int[][] Dp1 = new int[N1 + 1][N2 + 1], Dp2 = new int[N1 + 1][N2 + 1];

        for (int i = 0; i <= K1; ++i)
            Dp1[i][0] = 1;

        for (int j = 0; j <= K2; ++j)
            Dp2[0][j] = 1;

        for (int i = 1; i <= N1; ++i) {
            for (int j = 1; j <= N2; ++j) {
                for (int k = 1; k <= K1 && k <= i; ++k)
                    Dp1[i][j] = (Dp1[i][j] + Dp2[i - k][j]) % Mod;

                for (int k = 1; k <= K2 && k <= j; ++k)
                    Dp2[i][j] = (Dp2[i][j] + Dp1[i][j - k]) % Mod;
            }
        }

        out.println((Dp1[N1][N2] + Dp2[N1][N2]) % Mod);
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