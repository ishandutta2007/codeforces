import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = 30001, D = in.nextInt();
        int[] count = new int[M];

        for (int i = 0; i < N; ++i) count[in.nextInt()]++;

        int offset = 400 - D;
        int[][] dp = new int[M][800];

        int ans = 0;

        dp[D][offset + D] = count[0] + 1;
        for (int i = D; i < M; ++i) {
            for (int j = 0; j < dp[i].length; ++j) {
                if (dp[i][j] == 0) continue;
                int l = j - offset;
                dp[i][j] += count[i];

                for (int p = l - 1; p <= l + 1; ++p) {
                    if (p > 0 && i + p < M)
                        dp[i + p][offset + p] = Math.max(dp[i + p][offset + p], dp[i][j]);
                }

                ans = Math.max(ans, dp[i][j] - 1);
            }
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