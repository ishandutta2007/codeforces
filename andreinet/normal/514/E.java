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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    final int Mod = (int) (1e9 + 7);

    private int[][] mul(int[][] a, int[][] b) {
        int[][] ret = new int[a.length][a.length];
        for (int i = 0; i < ret.length; ++i)
            for (int j = 0; j < ret.length; ++j)
                for (int k = 0; k < ret.length; ++k)
                    ret[i][j] = (int) ((ret[i][j] + 1L * a[i][k] * b[k][j]) % Mod);
        return ret;
    }

    private int[][] Pow(int[][] x, int y) {
        int[][] ret = new int[x.length][x.length];
        for (int i = 0; i < ret.length; ++i)
            ret[i][i] = 1;
        for (; y > 0; y >>= 1) {
            if ((y & 1) != 0) ret = mul(ret, x);
            x = mul(x, x);
        }
        return ret;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();

        int[][] ans = new int[101][101];
        for (int i = 0; i < ans.length - 2; ++i)
            ans[i + 1][i] = 1;
        ans[100][0] = ans[100][100] = 1;
        //ans[0][99] = 1;

        while (N-- > 0) {
            int x = in.nextInt();
            ans[0][x - 1]++;
        }

        ans = Pow(ans, M + 1);
        out.println((ans[100][0]) % Mod);
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