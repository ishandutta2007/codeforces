import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.Locale;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    class Segment implements Comparable<Segment> {
        int left, right;
        double p;
        public Segment(int left, int right, double p) {
            this.left = left;
            this.right = right;
            this.p = p;
        }

        public int compareTo(Segment other) {
            return (right - left) - (other.right - other.left);
        }

        public boolean contains(Segment other) {
            return left <= other.left && other.right <= right;
        }
    }

    class Node {
        int value;
        double pr;
        boolean taken;
        ArrayList<Node> edges;

        Node() {
            taken = false;
            edges = new ArrayList<>();
        }

        double[] getProbabilities(Node father) {
            double[][] sons = new double[edges.size()][];
            int maxval = 3;
            for (int i = 0; i < edges.size(); ++i) {
                if (edges.get(i) == father) continue;
                sons[i] = edges.get(i).getProbabilities(this);
                maxval = Math.max(maxval, edges.get(i).value - value + sons[i].length + 1);
            }
            double[] ret = new double[maxval];
            for (int i = 0; i < ret.length; ++i) {
                double p1 = 1 - pr, p2 = i == 0 ? 0: pr;
                for (int j = 0; j < edges.size(); ++j) {
                    Node p = edges.get(j);
                    double[] son = sons[j];
                    if (p.value + son.length - 1 >= value + i)
                        p1 *= son[value + i - p.value];
                    if (p.value - 1 + son.length - 1 >= value + i && value + i >= p.value + 1)
                        p2 *= son[value + i - p.value - 1];
                }
                ret[i] = p1 + p2;
            }
            return ret;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt() + 1;
        int[] values = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            values[i] = in.nextInt();
        SegmentTree A = new SegmentTree(values);
        Segment[] segments = new Segment[M];
        for (int i = 1; i < M; ++i) {
            int l = in.nextInt(), r = in.nextInt();
            double p = in.nextDouble();
            segments[i] = new Segment(l, r, p);
        }
        segments[0] = new Segment(1, N, 0);
        Arrays.sort(segments);

        Node[] nodes = new Node[M];
        for (int i = 0; i < M; ++i) {
            nodes[i] = new Node();
            nodes[i].value = A.query(segments[i].left, segments[i].right);
            nodes[i].pr = segments[i].p;
            for (int j = 0; j < i; ++j)
                if (segments[i].contains(segments[j]) && !nodes[j].taken) {
                    nodes[i].edges.add(nodes[j]);
                    nodes[j].taken = true;
                }
        }

        double[] pr = nodes[M - 1].getProbabilities(null);
        for (int i = pr.length - 1; i > 0; --i) pr[i] -= pr[i - 1];
        double ans = 0;
        for (int i = 0; i < pr.length; ++i)
            ans += pr[i] * (nodes[M - 1].value + i);
        Locale.setDefault(Locale.US);
        out.println(String.format("%.9f", ans));
    }

    class SegmentTree {
        private int[] tree;
        private int size;

        public SegmentTree(int[] values) {
            size = values.length - 1;
            tree = new int[4 * size + 5];
            build(1, 1, size, values);
        }

        private void build(int node, int left, int right, int[] values) {
            if (left == right) {
                tree[node] = values[left];
            } else {
                int mid = (left + right) / 2;
                build(2 * node, left, mid, values);
                build(2 * node + 1, mid + 1, right, values);
                tree[node] = Math.max(tree[2 * node], tree[2 * node + 1]);
            }
        }

        public int query(int left, int right) {
            if (left > right) return 0;
            return Query(1, 1, size, left, right);
        }

        private int Query(int node, int left, int right, int lq, int rq) {
            if (lq <= left && right <= rq) return tree[node];
            else {
                int mid = (left + right) / 2, ret = 0;
                if (lq <= mid) ret = Query(2 * node, left, mid, lq, rq);
                if (rq > mid) ret = Math.max(ret, Query(2 * node + 1, mid + 1, right, lq, rq));
                return ret;
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

    public double nextDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, nextInt());
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    private boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

}