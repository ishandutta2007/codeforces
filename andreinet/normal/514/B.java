import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.io.IOException;

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
    class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    final double eps = 1e-10;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        Point O = new Point(in.nextInt(), in.nextInt());
        Point[] points = new Point[N];
        for (int i = 0; i < N; ++i)
            points[i] = new Point(in.nextInt(), in.nextInt());
        Arrays.sort(points, new Comparator<Point>() {
            public int compare(Point o1, Point o2) {
                return Double.compare(slope(O, o1), slope(O, o2));
            }
        });
        int ans = 1;
        for (int i = 1; i < N; ++i)
            if (Math.abs(slope(points[i], O) - slope(points[i - 1], O)) > eps)
        ++ans;

        out.println(ans);
    }
    
    private double slope(Point a, Point b) {
        if (a.x == b.x) return 1e99;
        return (double) (a.y - b.y) / (a.x - b.x);
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