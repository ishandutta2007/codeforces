import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.ArrayDeque;
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

    static class TaskF {
        private final int bucketSize = 500;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            String[] words = new String[n];
            for (int i = 0; i < n; ++i) words[i] = in.next();

            int[] firstQuery = new int[n], nextQuery = new int[q];
            Arrays.fill(firstQuery, -1);

            Query[] queries = new Query[q];
            for (int i = 0; i < q; ++i) {
                int left = in.nextInt() - 1;
                int right = in.nextInt() - 1;
                int k = in.nextInt() - 1;
                queries[i] = new Query(left, right, k);

                nextQuery[i] = firstQuery[k];
                firstQuery[k] = i;
            }

            Node root = new Node();
            for (int i = 0; i < n; ++i)
                add(root, words[i], 0, i);

            buildAutomaton(root);

            long[] answers = new long[q];

            long[] sum = new long[n + 1];
            for (int i = 0; i < n; ++i) {
                if (words[i].length() > bucketSize) {
                    Arrays.fill(sum, 0);
                    dfs1(root, i, sum);
                    for (int j = 1; j <= n; ++j) sum[j] += sum[j - 1];
                    for (int p = firstQuery[i]; p != -1; p = nextQuery[p]) {
                        int left = queries[p].left, right = queries[p].right;
                        answers[p] = sum[right + 1] - sum[left];
                    }
                    firstQuery[i] = -1;
                }
            }

            dfs2(root, firstQuery, nextQuery, answers, new PartialSums(n), queries);

            for (long p : answers) out.println(p);
        }

        private void add(Node node, String word, int pos, int index) {
            node.passingThrough.add(index);
            if (pos == word.length()) {
                node.ending.add(index);
                return;
            }

            int n = word.charAt(pos) - 'a';
            if (node.next[n] == null) node.next[n] = new Node();
            add(node.next[n], word, pos + 1, index);
        }

        private void buildAutomaton(Node root) {
            Queue<Node> q = new ArrayDeque<>();
            root.fail = root;
            q.add(root);

            while (!q.isEmpty()) {
                Node node = q.remove();
                for (int i = 0; i < 26; ++i) {
                    if (node.next[i] != null) {
                        Node k = node.fail;
                        while (k != root && k.next[i] == null)
                            k = k.fail;
                        if (k != node && k.next[i] != null) k = k.next[i];
                        node.next[i].fail = k;
                        k.sons.add(node.next[i]);
                        q.add(node.next[i]);
                    }
                }
            }

            root.fail = null;
        }

        private long dfs1(Node node, int index, long[] sum) {
            long cnt = 0;
            for (int p : node.passingThrough) if (p == index) ++cnt;

            for (Node next : node.sons)
                if (next != null)
                    cnt += dfs1(next, index, sum);

            for (int p : node.ending) sum[p + 1] += cnt;

            return cnt;
        }

        private void dfs2(Node node, int[] firstQuery, int[] nextQuery,
                          long[] answers, PartialSums sums, Query[] queries) {
            for (int p : node.ending) sums.add(p, 1);

            for (int p : node.passingThrough) {
                for (int q = firstQuery[p]; q != -1; q = nextQuery[q]) {
                    int left = queries[q].left, right = queries[q].right;
                    answers[q] += sums.query(left, right);
                }
            }

            for (Node next : node.sons)
                if (next != null)
                    dfs2(next, firstQuery, nextQuery,
                            answers, sums, queries);

            for (int p : node.ending) sums.add(p, -1);
        }

        private class Query {
            int left;
            int right;
            int k;

            Query(int left, int right, int k) {
                this.left = left;
                this.right = right;
                this.k = k;
            }

        }

        private class Node {
            List<Integer> passingThrough;
            List<Integer> ending;
            List<Node> sons;
            Node[] next;
            Node fail;

            Node() {
                passingThrough = new ArrayList<>();
                ending = new ArrayList<>();
                sons = new ArrayList<>();
                next = new Node[26];
                fail = null;
            }

        }

        private class PartialSums {
            int[] bucketSum;
            int[] remSum;
            int size;
            int bucketCount;

            PartialSums(int n) {
                size = n;
                bucketCount = (n - 1) / bucketSize + 1;
                bucketSum = new int[bucketCount];
                remSum = new int[n];
            }

            public void add(int pos, int value) {
                for (int i = pos / bucketSize; i < bucketCount; ++i)
                    bucketSum[i] += value;
                for (int i = pos; i < size &&
                        i / bucketSize == pos / bucketSize; ++i)
                    remSum[i] += value;
            }

            public int query(int pos) {
                return pos < 0 ? 0 : remSum[pos] +
                        (pos >= bucketSize ? bucketSum[pos / bucketSize - 1] : 0);
            }

            public int query(int left, int right) {
                return query(right) - query(left - 1);
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