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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        Pairii[] heights = new Pairii[N];
        for (int i = 0; i < N; ++i)
            heights[i] = new Pairii(in.nextInt(), i);

        Arrays.sort(heights, (o1, o2) -> -o1.compareTo(o2));

        int Q = in.nextInt();
        Query[] queries = new Query[Q];
        for (int i = 0; i < Q; ++i)
            queries[i] = new Query(in.nextInt() - 1, in.nextInt() - 1, in.nextInt(), 0, i);

        SegmentTree A = new SegmentTree(N);
        for (int step = 1 << 29; step > 0; step >>= 1) {
            Arrays.sort(queries, (o1, o2) -> Integer.compare(o2.ans, o1.ans));

            A.reset();
            for (int i = 0, j = 0; i < Q; ++i) {
                for (; j < N && heights[j].first >= queries[i].ans + step; ++j)
                    A.update(heights[j].second);

                int max = A.query(queries[i].left, queries[i].right);
                if (max >= queries[i].size)
                    queries[i].ans += step;
            }
        }

        Arrays.sort(queries, (o1, o2) -> Integer.compare(o1.pos, o2.pos));
        for (Query p: queries) out.println(p.ans);
    }

    class Query {
        int left, right, size, ans, pos;

        public Query(int left, int right, int size, int ans, int pos) {
            this.left = left;
            this.right = right;
            this.size = size;
            this.ans = ans;
            this.pos = pos;
        }
    }

    class SegmentTree {
        private int[] All, Left, Right;
        private int N;

        SegmentTree(int N) {
            this.N = N;
            All = new int[4 * N + 1];
            Left = new int[4 * N + 1];
            Right = new int[4 * N + 1];
        }

        public void reset() {
            Arrays.fill(All, 0);
            Arrays.fill(Left, 0);
            Arrays.fill(Right, 0);
        }

        public void update(int pos) {
            Update(1, 0, N - 1, pos);
        }

        private void Update(int node, int left, int right, int pos) {
            if (left == right) {
                All[node] = Left[node] = Right[node] = 1;
            } else {
                int mid = (left + right) / 2;
                if (pos <= mid) Update(2 * node, left, mid, pos);
                else Update(2 * node + 1, mid + 1, right, pos);
                All[node] = Math.max(Right[2 * node] + Left[2 * node + 1], Math.max(All[2 * node], All[2 * node + 1]));
                Left[node] = Left[2 * node] + (Left[2 * node] == (mid - left + 1) ? Left[2 * node + 1]: 0);
                Right[node] = Right[2 * node + 1] + (Right[2 * node + 1] == (right - mid) ? Right[2 * node]: 0);
            }
        }

        public int query(int left, int right) {
            Pairii ret = new Pairii(0, 0);
            Query(1, 0, N - 1, left, right, ret);
            return ret.first;
        }

        private void Query(int node, int left, int right, int l, int r, Pairii ans) {
            if (l <= left && right <= r) {
                ans.first = Math.max(ans.first, Math.max(All[node], ans.second + Left[node]));
                if (All[node] < right - left + 1) ans.second = 0;
                ans.second += Right[node];
            } else {
                int mid = (left + right) / 2;
                if (l <= mid) Query(2 * node, left, mid, l, r, ans);
                if (r > mid) Query(2 * node + 1, mid + 1, right, l, r, ans);
            }
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