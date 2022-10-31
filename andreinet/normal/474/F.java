import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    private int gcd(int a, int b) {
        int c;
        while (b > 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int[] A = new int[N];

        for (int i = 0; i < N; ++i)
            A[i] = in.nextInt();

        SegmentTree S = new SegmentTree(A);

        int Q = in.nextInt();
        while (Q-- > 0) {
            int left = in.nextInt(), right = in.nextInt();
            int[] q = S.query(left, right);
            
            if (q[0] % q[1] != 0)
                out.println(right - left + 1);
            else
                out.println(right - left + 1 - q[2]);
        }
    }

    private class SegmentTree {
        private class Node {
            public int gcd, min, cnt;
        }

        private Node[] tree;
        private int size;
        private int[] refVector;

        private int qgcd, qmin, qcnt;

        SegmentTree(int[] values) {
            refVector = values;
            size = values.length;
            tree = new Node[values.length * 4 + 3];
            Build(1, 1, size);
            refVector = null;
        }

        private void Build(int node, int left, int right) {
            tree[node] = new Node();

            if (left == right) {
                tree[node].min = refVector[left - 1];
                tree[node].gcd = tree[node].min;
                tree[node].cnt = 1;
            } else {
                int mid = (left + right) / 2;

                Build(2 * node, left, mid);
                Build(2 * node + 1, mid + 1, right);

                tree[node].gcd = gcd(tree[2 * node].gcd, tree[2 * node + 1].gcd);
                tree[node].min = Math.min(tree[2 * node].min, tree[2 * node + 1].min);
                tree[node].cnt = 0;
                if (tree[2 * node].min == tree[node].min)
                    tree[node].cnt += tree[2 * node].cnt;
                if (tree[2 * node + 1].min == tree[node].min)
                    tree[node].cnt += tree[2 * node + 1].cnt;
            }
        }

        public int[] query(int left, int right) {
            qgcd = -1;
            qmin = 0x3f3f3f3f;
            qcnt = 0;
            Query(1, 1, size, left, right);
            return new int[]{qgcd, qmin, qcnt};
        }

        private void Query(int node, int left, int right, int l, int r) {
            if (l <= left && right <= r) {
                qgcd = qgcd == -1 ? tree[node].gcd: gcd(qgcd, tree[node].gcd);
                if (tree[node].min < qmin) {
                    qmin = tree[node].min;
                    qcnt = tree[node].cnt;
                } else if (tree[node].min == qmin)
                    qcnt += tree[node].cnt;
            } else {
                int mid = (left + right) / 2;

                if (l <= mid)
                    Query(2 * node, left, mid, l, r);
                if (r > mid)
                    Query(2 * node + 1, mid + 1, right, l, r);
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