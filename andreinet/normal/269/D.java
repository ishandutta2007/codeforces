import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.TreeSet;
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
            final int MAXV = (int) 1e9;
            int n = in.nextInt(), t = in.nextInt();

            Interval[] intervals = new Interval[n + 1];
            for (int i = 0; i < n; ++i) {
                int h = in.nextInt();
                int l = in.nextInt();
                int r = in.nextInt();
                intervals[i] = new Interval(h, l, r);
            }
            intervals[n++] = new Interval(t, -MAXV, MAXV);
            Arrays.sort(intervals);

            TreeSet<Segment> S = new TreeSet<>();
            S.add(new Segment(-MAXV, MAXV, -MAXV, MAXV, 2 * MAXV));

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int left = intervals[i].left;
                int right = intervals[i].right;

                Segment curr = S.ceiling(new Segment(-MAXV, left + 1,
                        -MAXV, left + 1, 0));

                int maxFlow = 0;

                while (curr != null) {
                    if (curr.remLeft >= right) break;
                    if ((curr.remLeft == curr.left || left >= curr.remLeft) &&
                            (curr.remRight == curr.right || right <= curr.remRight)) {
                        int newFlow = Math.min(curr.flow,
                                Math.min(right, curr.remRight) -
                                        Math.max(left, curr.remLeft));
                        maxFlow = Math.max(maxFlow, newFlow);
                    }
                    S.remove(curr);
                    if (left > curr.remLeft) {
                        S.add(new Segment(curr.left, curr.right,
                                curr.remLeft, left, curr.flow));
                    }
                    if (right < curr.remRight) {
                        S.add(new Segment(curr.left, curr.right,
                                right, curr.remRight, curr.flow));
                    }
                    curr = S.higher(curr);
                }

                S.add(new Segment(left, right, left, right, maxFlow));
                ans = maxFlow;
            }

            out.println(ans);
        }

        private class Interval implements Comparable<Interval> {
            int h;
            int left;
            int right;

            Interval(int h, int left, int right) {
                this.h = h;
                this.left = left;
                this.right = right;
            }

            public int compareTo(Interval other) {
                return Integer.compare(h, other.h);
            }

        }

        private class Segment implements Comparable<Segment> {
            int left;
            int right;
            int remLeft;
            int remRight;
            int flow;

            Segment(int left, int right, int remLeft, int remRight, int flow) {
                this.left = left;
                this.right = right;
                this.remLeft = remLeft;
                this.remRight = remRight;
                this.flow = flow;
            }

            public int compareTo(Segment other) {
                if (remRight != other.remRight) {
                    return Integer.compare(remRight, other.remRight);
                } else if (remLeft != other.remLeft) {
                    return Integer.compare(remLeft, other.remLeft);
                } else if (right != other.right) {
                    return Integer.compare(right, other.right);
                } else {
                    return Integer.compare(left, other.left);
                }
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