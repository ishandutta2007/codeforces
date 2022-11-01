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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    private void update(long[] Aib, int pos, int val) {
        for (; pos < Aib.length; pos += pos & -pos)
            Aib[pos] += val;
    }

    private long query(long[] Aib, int pos) {
        long ret = 0;

        for (; pos > 0; pos -= pos & -pos)
            ret += Aib[pos];

        return ret;
    }

    int[] Norm(int[] A) {
        int N = A.length;

        Pair[] B = new Pair[N];
        for (int i = 0; i < N; i++)
            B[i] = new Pair(A[i], i);

        Arrays.sort(B);

        int[] ret = new int[N];

        ret[B[0].second] = 1;
        for (int i = 1, k = 1; i < N; i++) {
            if (B[i].first != B[i - 1].first)
                ++k;

            ret[B[i].second] = k;
        }
        return ret;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int[] A = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }

        A = Norm(A);

        int[] M = new int[N + 1];
        for (int i = 0; i < N; i++)
            M[A[i]]++;

        int[] Count = new int[N + 2];
        boolean[] S = new boolean[N + 1];

        for (int i = 0; i < N; i++) {
            if (!S[A[i]]) {
                S[A[i]] = true;
                Count[M[A[i]]]++;
            }
        }

        for (int i = N; i > 0; i--)
            Count[i] += Count[i + 1];


        long Aib[] = new long[N + 2];
        for (int i = 1; i <= N; i++)
            update(Aib, i, Count[i]);

        int[] C = new int[N + 1];

        long Ans = 0;
        for (int i = 0; i < N; i++) {
            int x = --M[A[i]], p = ++C[A[i]];

            update(Aib, x + 1, -1);

            Ans += query(Aib, p - 1);
        }

        out.println(Ans);
    }

    private static class Pair implements Comparable<Pair>{
        public int first, second;

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