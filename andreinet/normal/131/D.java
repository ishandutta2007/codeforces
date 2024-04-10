import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
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
    private final int Inf = 0x3f3f3f3f;

    private ArrayList<Integer> G[];
    private boolean[] Used;
    private int[] Dist;
    private Queue<Integer> Q;


    private int Dfs(int node, int from) {
        Used[node] = true;

        int ret = -1;
        for (int p: G[node]) {
            if (p == from)
                continue;

            if (Used[p]) {
                if (ret == -1)
                    ret = p;
            } else {
                ret = Math.max(ret, Dfs(p, node));
            }
        }

        if (ret != -1) {
            Dist[node] = 0;
            Q.add(node);
        }

        if (ret == node)
            return -1;
        else
            return ret;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();

        G = new ArrayList[N + 1];
        for (int i = 1; i < N + 1; ++i)
            G[i] = new ArrayList<Integer>();

        for (int i = 1; i <= N; ++i) {
            int x = in.nextInt(), y = in.nextInt();
            G[x].add(y);
            G[y].add(x);
        }

        Used = new boolean[N + 1];
        Dist = new int[N + 1];
        Arrays.fill(Dist, Inf);
        Q = new LinkedList<Integer>();

        Dfs(1, 0);

        while (!Q.isEmpty()) {
            int node = Q.poll();

            for (int p: G[node]) {
                if (Dist[p] == Inf) {
                    Dist[p] = Dist[node] + 1;
                    Q.add(p);
                }
            }
        }

        for (int i = 1; i <= N; ++i)
            out.print("" + Dist[i] + ' ');

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