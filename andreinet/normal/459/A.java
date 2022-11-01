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
    private int modul(int k) {
        return k < 0 ? -k: k;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();

        if (x1 != x2 && y1 != y2) {
            int x3 = x1, y3 = y2;
            int x4 = x2, y4 = y1;

            if (modul(x1 - x2) != modul(y1 - y2)) {
                out.println(-1);
            } else {
                out.println("" + x3 + ' ' + y3 + ' ' + x4 + ' ' + y4);
            }
        } else if (x1 == x2) {
            int x3 = x1 + modul(y1 - y2), y3 = y1;
            int x4 = x1 + modul(y1 - y2), y4 = y2;

            out.println("" + x3 + ' ' + y3 + ' ' + x4 + ' ' + y4);
        } else if (y1 == y2) {
            int x3 = x1, y3 = y1 + modul(x1 - x2);
            int x4 = x2, y4 = y1 + modul(x1 - x2);

            out.println("" + x3 + ' ' + y3 + ' ' + x4 + ' ' + y4);
        } else {
            out.println(-1);
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