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
    private final int Mod = 1000_000_007;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int Bmax = 100000;
        int[] Dp = new int[Bmax + 1];

        int Q = in.nextInt(), K = in.nextInt();

        Dp[0] = 1;
        for (int i = 1; i <= Bmax; ++i) {
            Dp[i] = Dp[i - 1];
            if (i - K >= 0)
                Dp[i] = (Dp[i] + Dp[i - K]) % Mod;
        }

        for (int i = 1; i <= Bmax; ++i)
            Dp[i] = (Dp[i - 1] + Dp[i]) % Mod;

        while (Q-- > 0) {
            int left = in.nextInt(), right = in.nextInt();
            out.println((Dp[right] - Dp[left - 1] + Mod) % Mod);
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