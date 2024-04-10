import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    private int[] A;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        A = new int[N];

        for (int i = 0; i < N; ++i)
            A[i] = in.nextInt();

        Integer[] B = new Integer[N];
        for (int i = 0; i < N; ++i)
            B[i] = i + 1;

        Arrays.sort(B, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return A[o1 - 1] - A[o2 - 1];
            }
        });

        long nr = 1;
        for (int i = 0; i < N; ) {
            int j;
            for (j = i; j < N && A[B[j] - 1] == A[B[i] - 1]; ++j);

            nr *= (j - i);
            i = j;
            
            if (nr >= 3)
                break;
        }

        if (nr >= 3) {
            out.println("YES");

            for (int i = 0; i < N; ++i)
                out.print("" + B[i] + ' ');
            out.println();

            for (int i = 1; i < N; ++i)
                if (A[B[i] - 1] == A[B[i - 1] - 1]) {
                    int aux = B[i];
                    B[i] = B[i - 1];
                    B[i - 1] = aux;
                    break;
                }

            for (int i = 0; i < N; ++i)
                out.print("" + B[i] + ' ');
            out.println();

            for (int i = 1; i < N; ++i)
                if (A[B[i] - 1] == A[B[i - 1] - 1]) {
                    int aux = B[i];
                    B[i] = B[i - 1];
                    B[i - 1] = aux;
                }

            for (int i = 0; i < N; ++i)
                out.print("" + B[i] + ' ');
            out.println();
        } else {
            out.println("NO");
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