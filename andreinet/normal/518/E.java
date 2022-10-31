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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    final int Inf = 0x3f3f3f3f;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), K = in.nextInt();

        int[] A = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            String nmb = in.next();
            if (nmb.equals("?")) A[i] = Inf;
            else A[i] = Integer.parseInt(nmb);
        }

        for (int i = 1; i <= K; ++i) {
            int cnt = (N - i) / K + 1;
            int[] B = new int[cnt];
            for (int j = i, k = 0; j <= N; j += K)
                B[k++] = A[j];
            int[] ans = solveSub(B);
            if (ans.length == 1 && ans[0] == -Inf) {
                out.println("Incorrect sequence");
                return;
            }
            for (int j = i, k = 0; j <= N; j += K)
                A[j] = ans[k++];
        }

        for (int i = 1; i <= N; ++i)
            out.print("" + A[i] + ' ');
        out.println();
    }

    private int[] solveSub(int[] A) {
        int N = A.length;
        boolean[] used = new boolean[N];
        for (int left = 0; left < N; ++left) {
            if (A[left] != Inf) continue;
            int right;
            for (right = left; right < N && A[right] == Inf; ++right)
                used[right] = true;

            int minVal = left == 0 ? -Inf: A[left - 1];
            int maxVal = right == N ? Inf: A[right];
            if (maxVal - minVal <= right - left) return new int[]{-Inf};

            int med = (right - left + 1) / 2, first = -med + 1;
            if (first <= minVal) first = minVal + 1;
            if (first + right - left - 1 >= maxVal) first = maxVal - (right - left);
            for (int j = left; j < right; ++j)
                A[j] = first++;
        }
        for (int i = 0; i < N - 1; ++i)
            if (A[i] >= A[i + 1])
                return new int[]{-Inf};

        return A;
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