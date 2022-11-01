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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    private final double Eps = 1e-12;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), R = in.nextInt(), r = in.nextInt();

        if (r > R) {
            out.println("NO");
            return;
        }
        
        if (2 * r > R) {
            if (N == 1)
                out.println("YES");
            else
                out.println("NO");

            return;
        }

        R -= r;
        r *= 2;

        double angle = Math.toDegrees(Math.acos((double)(R * R + R * R - r * r) / (double) (2 * R * R)));
        //out.println(Math.toDegrees(angle));

        if (360.0d / angle + Eps > (double) N)
            out.println("YES");
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