import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.List;
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
    List<Integer>[] G;
    List<Query>[] queries;
    int[] values, cntNodes;
    int[] freq;
    Aib cntFreq;

    int[] ans;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();
        G = new List[N];
        for (int i = 0; i < N; ++i)
            G[i] = new ArrayList<>();

        values = new int[N];
        for (int i = 0; i < N; ++i)
            values[i] = in.nextInt();

        for (int i = 1; i < N; ++i) {
            int x = in.nextInt() - 1, y = in.nextInt() - 1;
            G[x].add(y);
            G[y].add(x);
        }

        queries = new List[N];
        for (int i = 0; i < N; ++i)
            queries[i] = new ArrayList<>();

        for (int i = 0; i < M; ++i) {
            int node = in.nextInt() - 1, val = in.nextInt();
            queries[node].add(new Query(val, i));
        }

        cntNodes = new int[N];
        ans = new int[M];
        getSize(0, -1);
        freq = new int[100005];
        cntFreq = new Aib(N + 1);
        dfs(0, -1);

        for (int p: ans) out.println(p);
    }

    private void getSize(int node, int father) {
        cntNodes[node] = 1;
        for (int p: G[node]) {
            if (p != father) {
                getSize(p, node);
                cntNodes[node] += cntNodes[p];
            }
        }
    }

    private void updateValue(int col, int add) {
        if (freq[col] != 0) cntFreq.update(freq[col], -1);
        freq[col] += add;
        if (freq[col] != 0) cntFreq.update(freq[col], +1);
    }

    private void clearAib(int node, int father) {
        updateValue(values[node], -1);
        for (int p: G[node])
            if (p != father)
                clearAib(p, node);
    }

    private void addAib(int node, int father) {
        updateValue(values[node], 1);
        for (int p: G[node])
            if (p != father)
                addAib(p, node);
    }

    private void dfs(int node, int father) {
        int leaf = -1;
        for (int p: G[node]) {
            if (p == father) continue;
            if (leaf == -1 || cntNodes[p] > cntNodes[leaf])
                leaf = p;
        }

        for (int p: G[node]) {
            if (p == father || p == leaf) continue;
            dfs(p, node);
            clearAib(p, node);
        }

        if (leaf != -1) dfs(leaf, node);
        updateValue(values[node], 1);
        for (int p: G[node])
            if (p != father && p != leaf)
                addAib(p, node);

        for (Query q: queries[node]) {
            ans[q.pos] = cntFreq.query(q.val, cntFreq.size() - 1);
        }
    }

    private class Query {
        int val, pos;
        public Query(int val, int pos) {
            this.val = val;
            this.pos = pos;
        }
    }

    private class Aib {
        int[] tree;
        Aib(int N) {
            tree = new int[N];
        }

        void update(int pos, int val) {
            for (; pos < tree.length; pos += pos & -pos)
                tree[pos] += val;
        }

        int query(int pos) {
            int ret = 0;
            for (; pos > 0; pos -= pos & -pos)
                ret += tree[pos];
            return ret;
        }

        int query(int left, int right) {
            if (left > right || left >= tree.length) return 0;
            return query(right) - query(left - 1);
        }

        int size() {
            return tree.length;
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