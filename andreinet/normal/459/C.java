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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private int[][] Ans;
    private int[] A;
    private int N, K, D, cnt;
    private boolean stop;

    private void Back(int k) {
        if (k == D) {
            for (int i = 0; i < D; i++)
                Ans[i][cnt] = A[i];
            ++cnt;

            if (cnt == N)
                stop = true;
        } else {
            A[k] = 0;

            while (!stop && A[k] < K) {
                ++A[k];
                Back(k + 1);
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        N = in.nextInt();
        K = in.nextInt();
        D = in.nextInt();

        Ans = new int[D][N];
        A = new int[D];

        cnt = 0;
        stop = false;
        Back(0);
        
        if (cnt < N) {
            out.println(-1);
            return;
        }

        for (int i = 0; i < D; i++) {
            for (int j = 0; j < N; j++)
                out.print("" + Ans[i][j] + ' ');
            out.println();
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