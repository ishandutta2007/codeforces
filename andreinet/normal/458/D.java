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
        int N = in.nextInt(), M = in.nextInt(), K = in.nextInt();

        double[][] Comb = new double[N + 1][N + 1];

        for (int i = 0; i <= N; ++i) {
            Comb[i][0] = 1.0d;
            for (int j = 1; j <= i; ++j)
                Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];
        }

        double[] P = new double[M + 1];
        
        P[0] = 1.0d;
        for (int i = 1; i <= M; ++i)
            P[i] = P[i - 1] * (K - i + 1) / (M - i + 1);

        double Ans = 0.0d;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                int count = i * N + j * N - i * j;
                if (count <= K)
                    Ans += Comb[N][i] * Comb[N][j] * P[count];
            }
        }

        if (Ans > 1e99)
            out.println(1e99);
        else
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