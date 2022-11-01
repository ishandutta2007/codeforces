import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt(), q = in.nextInt();

            Node root = new Node();
            while (q-- > 0) {
                String type = in.next();
                if (type.equals("add")) {
                    int x = in.nextInt(), value = in.nextInt();
                    int pos = 30 - Integer.numberOfLeadingZeros(x);
                    add(root, x, value, pos);
                } else {
                    double ans = getDecay(root, 0, 1);
                    out.println(String.format("%.17f", ans));
                }
            }
        }

        private int getCount(Node e) {
            return e == null ? 0 : e.count;
        }

        private void add(Node node, int x, int value, int pos) {
            node.count += value;
            if (pos != -1) {
                if ((x & (1 << pos)) == 0) {
                    if (node.left == null) node.left = new Node();
                    add(node.left, x, value, pos - 1);
                } else {
                    if (node.right == null) node.right = new Node();
                    add(node.right, x, value, pos - 1);
                }
            }
        }

        private double getDecay(Node node, int maxSum, double p) {
            if (node == null) return 0;

            int cleft = getCount(node.left);
            int cright = getCount(node.right);
            int c = node.count - cleft - cright;
            double ret = 0;

            if (cleft > c + cright) {
                ret += p * 0.5 * Math.max(maxSum, c + cleft);
                ret += getDecay(node.left, Math.max(maxSum, c + cright), p * 0.5);
            } else if (cright > c + cleft) {
                ret += p * 0.5 * Math.max(maxSum, c + cright);
                ret += getDecay(node.right, Math.max(maxSum, c + cleft), p * 0.5);
            } else {
                ret += p * 0.5 * (Math.max(maxSum, c + cleft) +
                        Math.max(maxSum, c + cright));
            }
            return ret;
        }

        private class Node {
            int count = 0;
            Node left = null;
            Node right = null;

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