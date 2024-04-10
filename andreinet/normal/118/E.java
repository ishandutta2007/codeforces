import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    private ArrayList<Integer> G[];
    private Edge[] Edges;

    private int[] Lvl, Lvlmin;
    private boolean[] Used;
    private boolean ok;

    private void Dfs(int node, int father) {
        Lvlmin[node] = Lvl[node];
        Used[node] = true;

        for (int curr: G[node]) {
            Edge e = Edges[curr];
            int p = e.tto(node);

            if (p == father)
                continue;

            if (Used[p]) {
                Lvlmin[node] = Math.min(Lvlmin[node], Lvl[p]);
                if (Lvl[p] < Lvl[node]) {
                    e.from = node;
                    e.to = p;
                }
            } else {
                Lvl[p] = Lvl[node] + 1;
                Dfs(p, node);
                Lvlmin[node] = Math.min(Lvlmin[node], Lvlmin[p]);

                e.from = node;
                e.to = p;

                if (Lvlmin[p] > Lvl[node])
                    ok = false;
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();

        G = new ArrayList[N + 1];
        for (int i = 1; i <= N; ++i)
            G[i] = new ArrayList<Integer>();

        Edges = new Edge[M];
        for (int i = 0; i < M; ++i) {
            int from = in.nextInt(), to = in.nextInt();
            Edges[i] = new Edge(from, to);

            G[from].add(i);
            G[to].add(i);
        }

        Lvl = new int[N + 1];
        Lvlmin = new int[N + 1];
        Used = new boolean[N + 1];
        ok = true;
        Dfs(1, 0);

        if (!ok) {
            out.println(0);
        } else {
            for (Edge p: Edges)
                out.println("" + p.from + ' ' + p.to);
        }
    }

    private static class Edge {
        public int from, to;

        private Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }

        public int tto(int node) {
            return node == from ? to: from;
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