import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    private final int Inf = 0x3f3f3f3f;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();
        int[] R = new int[M], C = new int[M];

        int[] Rmax = new int[N + 1], Rmin = new int[N + 1], Cmin = new int[N + 1], Cmax = new int[N + 1];
        int[] D1min = new int[2 * N + 1], D1max = new int[2 * N + 1], D2min = new int[2 * N + 1], D2max = new int[2 * N + 1];

        Arrays.fill(Rmin, Inf);
        Arrays.fill(Cmin, Inf);
        Arrays.fill(D1min, Inf);
        Arrays.fill(D2min, Inf);
        Arrays.fill(Rmax, -Inf);
        Arrays.fill(Cmax, -Inf);
        Arrays.fill(D1max, -Inf);
        Arrays.fill(D2max, -Inf);

        final int Offset = N;

        for (int i = 0; i < M; ++i) {
            R[i] = in.nextInt();
            C[i] = in.nextInt();

            Rmax[R[i]] = Math.max(Rmax[R[i]], C[i]);
            Rmin[R[i]] = Math.min(Rmin[R[i]], C[i]);
            Cmax[C[i]] = Math.max(Cmax[C[i]], R[i]);
            Cmin[C[i]] = Math.min(Cmin[C[i]], R[i]);
            D1max[Offset + R[i] - C[i]] = Math.max(D1max[Offset + R[i] - C[i]], R[i] + C[i]);
            D1min[Offset + R[i] - C[i]] = Math.min(D1min[Offset + R[i] - C[i]], R[i] + C[i]);
            D2max[R[i] + C[i]] = Math.max(D2max[R[i] + C[i]], R[i] - C[i]);
            D2min[R[i] + C[i]] = Math.min(D2min[R[i] + C[i]], R[i] - C[i]);
        }

        int[] Ans = new int[9];
        for (int i = 0; i < M; ++i) {
            int cnt = 0;

            if (C[i] < Rmax[R[i]])
                ++cnt;
            if (C[i] > Rmin[R[i]])
                ++cnt;
            if (R[i] < Cmax[C[i]])
                ++cnt;
            if (R[i] > Cmin[C[i]])
                ++cnt;

            if (R[i] + C[i] < D1max[Offset + R[i] - C[i]])
                ++cnt;
            if (R[i] + C[i] > D1min[Offset + R[i] - C[i]])
                ++cnt;

            if (R[i] - C[i] < D2max[R[i] + C[i]])
                ++cnt;
            if (R[i] - C[i] > D2min[R[i] + C[i]])
                ++cnt;

            Ans[cnt]++;
        }

        for (int i = 0; i < 9; ++i)
            out.print("" + Ans[i] + ' ');

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