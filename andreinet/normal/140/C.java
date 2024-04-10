import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
        int[] A = new int[N];
        for (int i = 0; i < N; ++i)
            A[i] = in.nextInt();

        TreeSet<Pair> S = new TreeSet<Pair>();

        Arrays.sort(A);
        for (int i = 0; i < N;) {
            int j;
            for (j = i + 1; j < N && A[i] == A[j]; ++j);

            S.add(new Pair(j - i, A[i]));
            i = j;
        }

        int[][] Ans = new int[N][3];
        int Count = 0;

        while (true) {
            int[] Vals = new int[3], Cnt = new int[3];

            boolean ok = true;
            for (int i = 0; i < 3; ++i) {
                if (S.isEmpty()) {
                    ok = false;
                    break;
                }

                Pair curr = S.pollLast();
                Vals[i] = curr.second;
                Cnt[i] = curr.first;
            }

            if (!ok)
                break;

            Ans[Count++] = Vals;

            for (int i = 0; i < 3; ++i) {
                if (Cnt[i] > 1)
                    S.add(new Pair(Cnt[i] - 1, Vals[i]));
            }
        }

        out.println(Count);
        for (int i = 0; i < Count; ++i) {
            Arrays.sort(Ans[i]);
            out.println("" + Ans[i][2] + ' ' + Ans[i][1] + ' ' + Ans[i][0]);
        }
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