import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String A = in.next(), B = in.next();
        int N = A.length(), M = B.length();

        int[] cnt1 = new int[52], cnt2 = new int[52];
        for (int i = 0; i < N; ++i) {
            if ('a' <= A.charAt(i) && A.charAt(i) <= 'z') ++cnt1[A.charAt(i) - 'a'];
            else ++cnt1[A.charAt(i) - 'A' + 26];
        }
        for (int i = 0; i < M; ++i) {
            if ('a' <= B.charAt(i) && B.charAt(i) <= 'z') ++cnt2[B.charAt(i) - 'a'];
            else ++cnt2[B.charAt(i) - 'A' + 26];
        }

        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < 52; ++i) {
            int x = Math.min(cnt1[i], cnt2[i]);
            cnt1[i] -= x;
            cnt2[i] -= x;
            ans1 += x;
        }

        for (int i = 0; i < 52; ++i) {
            int p = i >= 26 ? i - 26: i + 26;
            int x = Math.min(cnt1[i], cnt2[p]);
            cnt1[i] -= x;
            cnt2[p] -= x;
            ans2 += x;
        }

        out.println("" + ans1 + ' ' + ans2);
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