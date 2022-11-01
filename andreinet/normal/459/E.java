import java.io.IOException;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();

        Edge[] Edges = new Edge[M];

        for (int i = 0; i < M; i++) {
            int x = in.nextInt(), y = in.nextInt(), cost = in.nextInt();
            Edges[i] = new Edge(x, y, cost);
        }

        Arrays.sort(Edges);

        int[] Path = new int[N + 1];
        for (int i = 0; i < M; ) {
            int j = i;
            ArrayList<Pair> New = new ArrayList<Pair>();
            do {
                int from = Edges[j].from, to = Edges[j].to;
                New.add(new Pair(Edges[j].to, Path[Edges[j].from] + 1));
                ++j;
            } while(j < M && Edges[j].cost == Edges[j - 1].cost);

            for (Pair p: New)
                Path[p.first] = Math.max(Path[p.first], p.second);
            i = j;
        }

        int Ans = 0;
        for (int i = 1; i <= N; i++)
            Ans = Math.max(Ans, Path[i]);

        out.println(Ans);
    }

    private static class Edge implements Comparable<Edge> {
        int from, to, cost;

        Edge() {}

        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Edge other) {
            if (cost != other.cost)
                return cost < other.cost ? -1: 1;

            return 0;
        }
    }

    private static class Pair {
        int first, second;

        Pair() {}

        private Pair(int first, int second) {
            this.first = first;
            this.second = second;
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