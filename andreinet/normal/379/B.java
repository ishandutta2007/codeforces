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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    boolean Check(int[] A) {
        for (int i = 0; i < A.length; i++)
            if (A[i] > 0)
                return true;

        return false;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int[] A = new int[N];

        for (int i = 0; i < N; i++)
            A[i] = in.nextInt();

        int u = 0;
        while (Check(A)) {
            u ^= 1;

            if (u == 1) {
                for (int i = 0; i < N; i++) {
                    if (A[i] > 0 && i < N - 1) {
                        out.print("P");
                        A[i]--;
                    }
                    if (i < N - 1)
                        out.print("R");
                }
            } else {
                for (int i = N - 1; i >= 0; i--) {
                    if (A[i] > 0 && i > 0) {
                        out.print("P");
                        A[i]--;
                    }
                    if (i > 0)
                        out.print("L");
                }
            }
        }

        out.println();
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