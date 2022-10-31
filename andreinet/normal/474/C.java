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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    Point[] Sq, O;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        Sq = new Point[4];
        O = new Point[4];

        for (int i = 0; i < 4; ++i) {
            Sq[i] = new Point();
            O[i] = new Point();
        }

        int Q = in.nextInt();
        while (Q-- > 0) {
            for (int i = 0; i < 4; ++i) {
                Sq[i].x = in.nextInt();
                Sq[i].y = in.nextInt();
                O[i].x = in.nextInt();
                O[i].y = in.nextInt();
            }

            cnt = 0;
            ans = 0x3f3f3f3f;
            Back(0);

            if (ans == 0x3f3f3f3f)
                out.println(-1);
            else
                out.println(ans);
        }
    }

    int ans, cnt;

    void Back(int k) {
        if (k == 4) {
            long[] dists = new long[6];
            for (int i = 0, p = 0; i < 4; ++i)
                for (int j = i + 1; j < 4; ++j)
                    dists[p++] = Sq[i].dist(Sq[j]);

            Arrays.sort(dists);
            if (dists[0] == 0)
                return;
            if (!(dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3]))
                return;
            if (!(dists[4] == dists[5]))
                return;
            if (!(2 * dists[0] == dists[4]))
                return;

            ans = Math.min(ans, cnt);
        } else {
            for (int i = 0; i < 4; ++i) {
                Back(k + 1);
                Sq[k].rotate90(O[k]);
                ++cnt;
            }
            cnt -= 4;
        }
    }

    private class Point {
        public int x, y;

        Point() {}

        public void rotate90(Point o) {
            int nx = o.y - y;
            int ny = x - o.x;

            x = nx + o.x;
            y = ny + o.y;
        }

        public long dist(Point other) {
            return 1L * (x - other.x) * (x - other.x) + 1L * (y - other.y) * (y - other.y);
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