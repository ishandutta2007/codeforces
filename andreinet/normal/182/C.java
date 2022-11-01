import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private Random rnd;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            rnd = new Random(System.currentTimeMillis());

            int N = in.nextInt(), len = in.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; ++i)
                A[i] = in.nextInt();
            int K = in.nextInt();

            long ans = go(N, len, K, A);

            for (int i = 0; i < N; ++i)
                A[i] *= -1;

            ans = Math.max(ans, go(N, len, K, A));

            out.println(ans);
        }

        private long go(int N, int len, int K, int[] A) {
            K = Math.min(K, len);

            TaskC.Node root = null;

            long ans = 0, sump = 0;

            for (int i = 0; i < len; ++i) {
                sump += A[i];
                if (A[i] < 0) {
                    root = insert(root, A[i]);
                }
            }

            TaskC.Node[] spl;

            spl = splitPos(root, K);
            if (getSize(spl[0]) > K) throw new RuntimeException();
            long sumc = getSum(spl[0]);
            ans = Math.max(ans, sump + (-sumc) * 2);
            root = merge(spl[0], spl[1]);

            for (int i = len; i < N; ++i) {
                sump -= A[i - len];
                if (A[i - len] < 0)
                    root = remove(root, A[i - len]);

                sump += A[i];
                if (A[i] < 0)
                    root = insert(root, A[i]);

                spl = splitPos(root, K);
                if (getSize(spl[0]) > K) throw new RuntimeException();
                sumc = getSum(spl[0]);
                ans = Math.max(ans, sump + (-sumc) * 2);
                root = merge(spl[0], spl[1]);
            }

            return ans;
        }

        private int getSize(TaskC.Node node) {
            return node == null ? 0 : node.size;
        }

        private long getSum(TaskC.Node node) {
            return node == null ? 0 : node.sum;
        }

        private void update(TaskC.Node node) {
            node.size = 1 + getSize(node.left) + getSize(node.right);
            node.sum = node.val + getSum(node.left) + getSum(node.right);
        }

        private TaskC.Node[] split(TaskC.Node node, int val) {
            if (node == null)
                return new TaskC.Node[2];

            if (val <= node.val) {
                TaskC.Node[] spl = split(node.left, val);
                node.left = spl[1];
                update(node);
                spl[1] = node;
                return spl;
            } else {
                TaskC.Node[] spl = split(node.right, val);
                node.right = spl[0];
                update(node);
                spl[0] = node;
                return spl;
            }
        }

        private TaskC.Node[] splitPos(TaskC.Node node, int pos) {
            if (node == null)
                return new TaskC.Node[2];

            if (pos <= getSize(node.left)) {
                TaskC.Node[] spl = splitPos(node.left, pos);
                node.left = spl[1];
                update(node);
                spl[1] = node;
                return spl;
            } else {
                TaskC.Node[] spl = splitPos(node.right, pos - getSize(node.left) - 1);
                node.right = spl[0];
                update(node);
                spl[0] = node;
                return spl;
            }
        }

        private TaskC.Node merge(TaskC.Node left, TaskC.Node right) {
            if (left == null) return right;
            if (right == null) return left;

            if (left.pry > right.pry) {
                left.right = merge(left.right, right);
                update(left);
                return left;
            } else {
                right.left = merge(left, right.left);
                update(right);
                return right;
            }
        }

        private TaskC.Node insert(TaskC.Node root, int val) {
            TaskC.Node[] spl = split(root, val);
            return merge(merge(spl[0], new TaskC.Node(val)), spl[1]);
        }

        private TaskC.Node remove(TaskC.Node root, int val) {
            if (root == null) return null;

            if (val == root.val) {
                root = merge(root.left, root.right);
                return root;
            } else if (val < root.val) {
                root.left = remove(root.left, val);
                update(root);
                return root;
            } else {
                root.right = remove(root.right, val);
                update(root);
                return root;
            }
        }

        private class Node {
            int val;
            int pry;
            int size;
            long sum;
            TaskC.Node left;
            TaskC.Node right;

            Node(int val) {
                this.val = val;
                pry = rnd.nextInt();
                size = 1;
                sum = val;
                left = right = null;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
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
}