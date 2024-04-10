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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    private int N, K;
    private char[] S;

    private boolean Solve(int pos) {
        if (pos == N)
            return false;

        if (Solve(pos + 1))
            return true;

        ++S[pos];
        while (S[pos] - 'a' < K && ((pos > 0 && S[pos] == S[pos - 1] || (pos > 1 && S[pos] == S[pos - 2]))))
            ++S[pos];

        if (S[pos] - 'a' == K)
            return false;

        for (int i = pos + 1; i < N; ++i) {
            int j;
            for (j = 0; (i > 0 && j + 'a' == S[i - 1]) || (i > 1 && j + 'a' == S[i - 2]); ++j);

            if (j >= K)
                return false;

            S[i] = (char) (j + 'a');
        }

        return true;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        N = in.nextInt();
        K = in.nextInt();
        S = in.nextString().toCharArray();

        if (Solve(0))
            out.println(new String(S));
        else
            out.println("NO");
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