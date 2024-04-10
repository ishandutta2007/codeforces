import java.util.Deque;
import java.util.InputMismatchException;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.util.Collection;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt(), K = in.nextInt();
        Deque<Pairii>[] deqs = new Deque[M];
        for (int i = 0; i < M; ++i) deqs[i] = new ArrayDeque<>();

        int ans = 0;
        int[] shots = new int[M];
        for (int i = 1, j = 0; i <= N; ++i) {
            for (Deque<Pairii> deq: deqs) {
                int x = in.nextInt();
                while (!deq.isEmpty() && x >= deq.peekLast().first)
                    deq.pollLast();
                deq.add(new Pairii(x, i));
            }

            int sum = 0;
            for (Deque<Pairii> deq: deqs)
                if (!deq.isEmpty())
                    sum += deq.peekFirst().first;

            while (sum > K) {
                ++j;
                for (Deque<Pairii> deq: deqs)
                    while (!deq.isEmpty() && deq.peekFirst().second == j)
                        deq.pollFirst();

                sum = 0;
                for (Deque<Pairii> deq: deqs)
                    if (!deq.isEmpty())
                        sum += deq.peekFirst().first;
            }

            if (i - j > ans) {
                ans = i - j;
                for (int k = 0; k < M; ++k)
                    shots[k] = (deqs[k].isEmpty() ? 0: deqs[k].peekFirst().first);
            }
        }
        
        for (int p: shots)
            out.print("" + p + ' ');
        out.println();
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

class Pairii implements Comparable<Pairii> {
    public int first, second;

    public Pairii(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pairii other) {
        if (first != other.first) return first < other.first ? -1: 1;
        if (second != other.second) return second < other.second ? -1: 1;
        return 0;
    }

    public boolean equals(Object other) {
        if (!(other instanceof Pairii)) return false;
        return compareTo((Pairii) other) == 0;
    }

    public int hashCode() {
        return first * 31 + second;
    }
}