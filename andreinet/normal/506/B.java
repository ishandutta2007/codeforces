import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    ArrayList<Integer>[] G, Gt;
    boolean[] used;
    int[] count, cc, snodes;
    int N, ncc;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        N = in.nextInt();
        int M = in.nextInt();

        G = new ArrayList[N];
        for (int i = 0; i < N; ++i)
            G[i] = new ArrayList<>();

        Gt = new ArrayList[N];
        for (int i = 0; i < N; ++i)
            Gt[i] = new ArrayList<>();

        while (M-- > 0) {
            int x = in.nextInt() - 1, y = in.nextInt() - 1;
            G[x].add(y);
            Gt[y].add(x);
        }

        int ans = N;

        ncc = 0;
        used = new boolean[N];
        cc = new int[N];
        for (int i = 0; i < N; ++i) {
            if (!used[i]) {
                ++ncc;
                dfs1(i);
            }
        }

        ans -= ncc;
        ncc = 0;
        Arrays.fill(used, false);
        snodes = new int[N];
        for (int i = 0; i < N; ++i)
            if (!used[i])
                dfs2(i);
        ncc = 0;
        count = new int[N];
        for (int i = N - 1; i >= 0; --i) {
            int node = snodes[i];
            if (used[node]) {
                ncc = 0;
                dfs3(node);
                if (ncc > 1) count[cc[node]]++;
            }
        }

        for (int i = 0; i < N; ++i)
            if (count[i] > 0)
                ++ans;

        out.println(ans);
    }

    private void dfs1(int node) {
        used[node] = true;
        cc[node] = ncc;
        for (int p: G[node])
            if (!used[p])
                dfs1(p);
        for (int p: Gt[node])
            if (!used[p])
                dfs1(p);
    }

    private void dfs2(int node) {
        used[node] = true;
        for (int p: G[node])
            if (!used[p])
                dfs2(p);
        snodes[ncc++] = node;
    }

    private void dfs3(int node) {
        used[node] = false;
        ++ncc;
        for (int p: Gt[node])
            if (used[p])
                dfs3(p);
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