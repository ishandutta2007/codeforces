import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
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

    private boolean comp(char[] A, char[] B) {
        if (B == null)
            return true;

        for (int i = 0; i < A.length; ++i)
            if (A[i] < B[i])
                return true;
            else if (A[i] > B[i])
                return false;

        return false;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), K = in.nextInt();
        char[] S = in.nextString().toCharArray();

        int[] Freq = new int[10];
        ArrayList<Integer>[] Pos = new ArrayList[10];

        for (int i = 0; i < 10; ++i)
            Pos[i] = new ArrayList<Integer>();

        for (int i = 0; i < N; ++i) {
            ++Freq[S[i] - '0'];
            Pos[S[i] - '0'].add(i);
        }

        for (int i = 0; i < 10; ++i) {
            if (Freq[i] >= K) {
                out.println("0\n" + new String(S));
                return;
            }
        }

        char[] Sol = null;
        int cmin = 0x3f3f3f3f;
        for (int i = 0; i < 10; ++i) {
            int count = K - Freq[i];

            if (count <= 0)
                continue;

            char[] Copy = new char[N];
            System.arraycopy(S, 0, Copy, 0, N);

            int cost = 0;
            for (int j = i - 1, k = i + 1; count > 0;) {
                if (j >= 0 && (i - j < k - i || k > 9)) {
                    int x = Math.min(Freq[j], count);
                    count -= x;

                    for (int p = Freq[j] - 1; p >= Freq[j] - x; --p)
                        Copy[Pos[j].get(p)] = (char) (i + '0');

                    cost += x * (i - j);

                    --j;
                } else {
                    int x = Math.min(Freq[k], count);
                    count -= x;

                    for (int p = 0; p < x; ++p)
                        Copy[Pos[k].get(p)] = (char) (i + '0');

                    cost += x * (k - i);

                    ++k;
                }
            }

            if (count != 0)
                continue;

            if (cost < cmin || (cost == cmin && comp(Copy, Sol))) {
                cmin = cost;
                Sol = Copy;
            }
        }
        out.println(cmin);
        out.println(new String(Sol));
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