import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    int[][] points, order, perm;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        points = new int[8][3];
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 3; ++j)
                points[i][j] = in.nextInt();

        perm = new int[][]{
            new int[]{1, 2, 3},
            new int[]{1, 3, 2},
            new int[]{2, 1, 3},
            new int[]{2, 3, 1},
            new int[]{3, 1, 2},
            new int[]{3, 2, 1}
        };

        order = new int[8][3];
        dists = new long[7];
        if (!Back(0))
            out.println("NO");
        else {
            out.println("YES");
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 3; ++j)
                    out.print("" + order[i][j] + ' ');
                out.println();
            }
        }
    }

    private long dist(int[] p1, int[] p2) {
        return 1L * (p1[0] - p2[0]) * (p1[0] - p2[0]) + 1L * (p1[1] - p2[1]) * (p1[1] - p2[1]) + 1L * (p1[2] - p2[2]) * (p1[2] - p2[2]);
    }

    long[] dists;

    private boolean Back(int pos) {
        if (pos == 8) {
            for (int i = 0; i < 8; ++i)
                for (int j = i + 1; j < 8; ++j)
                    if (order[i][0] == order[j][0] && order[i][1] == order[j][1] && order[i][2] == order[j][2])
                        return false;
            
            for (int i = 1; i < 8; ++i)
                dists[i - 1] = dist(order[0], order[i]);

            Arrays.sort(dists);
            if (!(dists[0] == dists[1] && dists[1] == dists[2]))
                return false;

            if (!(dists[3] == dists[4] && dists[4] == dists[5]))
                return false;

            if (!(dists[0] * 2 == dists[3]))
                return false;

            if (!(dists[0] + dists[3] == dists[6]))
                return false;

            return true;
        } else {
            for (int cperm = 0; cperm < 6; ++cperm) {
                for (int i = 0; i < 3; ++i)
                    order[pos][i] = points[pos][perm[cperm][i] - 1];

                if (Back(pos + 1))
                    return true;
            }

            return false;
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