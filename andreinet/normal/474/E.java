import java.io.IOException;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
        int N = in.nextInt(), D = in.nextInt();
        long[] A = new long[N];

        for (int i = 0; i < N; ++i)
            A[i] = in.nextLong();

        rnd = new Random(System.currentTimeMillis());
        Node root = null;

        int[] next = new int[N], values = new int[N];

        int ans = 0, ansp = -1;
        for (int i = 0; i < N; ++i) {
            long x = A[i];
            int p = query(root, A[i], D), m = p == -1 ? 0: values[p];

            next[i] = p;

            root = insert(root, A[i], m + 1, i);

            if (m + 1 > ans) {
                ans = m + 1;
                ansp = i;
            }

            values[i] = m + 1;
        }

        out.println(ans);
        int[] Sol = new int[ans];
        for (int i = ansp, j = ans - 1; i >= 0; i = next[i], --j)
            Sol[j] = i + 1;

        for (int i = 0; i < ans; ++i)
            out.print("" + Sol[i] + ' ');

        out.println();
    }

    private int query(Node root, long val, int D) {
        Node left, mid, right;
        PairNode rsplit = split(root, val - D + 1);
        left = rsplit.left;
        rsplit = split(rsplit.right, val + D);
        mid = rsplit.left;
        right = rsplit.right;

        int ans = (left == null && right == null) ? -1: (left == null || (right != null && right.ans > left.ans) ? right.ansp: left.ansp);
        root = merge(merge(left, mid), right);
        return ans;
    }

    private Random rnd;

    private class Node {
        public long key;
        public int ans, ansp, nr, pos, pry;

        public Node left, right;

        Node(long key, int nr, int pos) {
            this.key = key;
            this.nr = nr;
            this.pos = pos;
            ans = nr;
            ansp = pos;
            pry = rnd.nextInt();
            left = right = null;
        }

        public void update() {
            ans = Math.max(nr, Math.max(left == null ? 0: left.ans, right == null ? 0: right.ans));
            if (ans == nr)
                ansp = pos;
            else if (ans == (left == null ? 0: left. ans))
                ansp = left.ansp;
            else
                ansp = right.ansp;
        }
    }

    private class PairNode {
        public Node left, right;

        PairNode(Node left, Node right) {
            this.left = left;
            this.right = right;
        }
    }

    private PairNode split(Node root, long val) {
        if (root == null)
            return new PairNode(null, null);

        if (val > root.key) {
            PairNode rsplit = split(root.right, val);
            root.right = rsplit.left;
            root.update();
            rsplit.left = root;
            return rsplit;
        } else {
            PairNode rsplit = split(root.left, val);
            root.left = rsplit.right;
            root.update();
            rsplit.right = root;
            return rsplit;
        }
    }

    private Node merge(Node left, Node right) {
        if (left == null)
            return right;

        if (right == null)
            return left;

        if (left.pry > right.pry) {
            left.right = merge(left.right, right);
            left.update();
            return left;
        } else {
            right.left = merge(left, right.left);
            right.update();
            return right;
        }
    }

    private Node insert(Node root, long key, int nr, int pos) {
        Node p = new Node(key, nr, pos);
        PairNode rsplit = split(root, key);
        return merge(merge(rsplit.left, p), rsplit.right);
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

    public long nextLong() {
        return Long.parseLong(nextString());
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