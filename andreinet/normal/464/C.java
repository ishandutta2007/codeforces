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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private final int Mod = 1000000007;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String number = in.nextString();

        int M = in.nextInt();
        String[] updates = new String[M];

        for (int i = 0; i < M; ++i)
            updates[i] = in.nextString();


        int[] values = new int[10], pow10 = new int[10];
        for (int i = 0; i < 10; ++i) {
            values[i] = i;
            pow10[i] = 10;
        }

        for (int i = M - 1; i >= 0; --i) {
            String curr = updates[i];

            int x = curr.charAt(0) - '0';

            int nval = 0, npow10 = 1;
            for (int j = 3; j < curr.length(); ++j) {
                int y = curr.charAt(j) - '0';

                nval = (int) ((1L * nval * pow10[y] + values[y]) % Mod);
                npow10 = (int) (1L * npow10 * pow10[y] % Mod);
            }

            values[x] = nval;
            pow10[x] = npow10;
        }

        int ans = 0;
        for (int i = 0; i < number.length(); ++i) {
            int y = number.charAt(i) - '0';
            ans = (int) ((1L * ans * pow10[y] + values[y]) % Mod);
        }

        out.println(ans);
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