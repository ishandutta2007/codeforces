import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        Pair[] A = new Pair[N];

        for (int i = 0; i < N; i++)
            A[i] = new Pair(in.nextInt(), i);

        Arrays.sort(A);

        int[] B = new int[N];

        int s = 0;
        for (int i = 0; i < N; i++) {
            int nexts = Math.max(s, A[i].first);
            B[A[i].second] = nexts;
            s = nexts + 1;
        }

        for (int i = 0; i < N; i++)
            out.print("" + B[i] + ' ');

        out.println();
    }

    private static class Pair implements Comparable<Pair> {
        int first, second;

        private Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair other) {
            if (first != other.first)
                return first < other.first ? -1: 1;

            if (second != other.second)
                return second < other.second ? -1: 1;

            return 0;
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