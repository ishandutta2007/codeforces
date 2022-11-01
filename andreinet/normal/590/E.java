import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        boolean[][] graph;
        int[] leftMatch;
        int[] rightMatch;
        boolean[] used;
        boolean[] leftUsed;
        boolean[] rightUsed;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] ribbons = new String[n];

            AhoCorasick t = new AhoCorasick();
            for (int i = 0; i < n; ++i) {
                ribbons[i] = in.next();
                t.add(ribbons[i], i);
            }

            t.buildLinks();
            graph = new boolean[n][n];

            for (int i = 0; i < n; ++i) {
                int node = t.root();
                for (int j = 0; j < ribbons[i].length(); ++j) {
                    int c = ribbons[i].charAt(j) - 'a';
                    node = t.next(node, c);

                    int pnode = t.hasWord(node) ? node : t.nextWordFail(node);
                    while (pnode != -1 && !graph[i][t.ending(pnode)]) {
                        graph[i][t.ending(pnode)] = true;
                        pnode = t.nextWordFail(pnode);
                    }
                }
            }

            for (int i = 0; i < n; ++i)
                graph[i][i] = false;

            leftMatch = new int[n];
            rightMatch = new int[n];
            Arrays.fill(leftMatch, -1);
            Arrays.fill(rightMatch, -1);
            used = new boolean[n];
            for (boolean ok = true; ok; ) {
                ok = false;
                Arrays.fill(used, false);
                for (int i = 0; i < n; ++i)
                    if (leftMatch[i] == -1)
                        ok |= pairUp(i);
            }

            leftUsed = new boolean[n];
            rightUsed = new boolean[n];
            for (int i = 0; i < n; ++i)
                if (leftMatch[i] != -1)
                    leftUsed[i] = true;
            for (int i = 0; i < n; ++i)
                if (!leftUsed[i])
                    support(i);

            int count = 0;
            for (int i = 0; i < n; ++i)
                if (!leftUsed[i] && !rightUsed[i])
                    ++count;

            out.println(count);
            for (int i = 0; i < n; ++i)
                if (!leftUsed[i] && !rightUsed[i])
                    out.print((i + 1) + " ");
            out.println();
        }

        private boolean pairUp(int node) {
            if (used[node]) return false;
            used[node] = true;
            for (int i = 0; i < graph.length; ++i) {
                if (graph[node][i] && rightMatch[i] == -1) {
                    leftMatch[node] = i;
                    rightMatch[i] = node;
                    return true;
                }
            }
            for (int i = 0; i < graph.length; ++i) {
                if (graph[node][i] && pairUp(rightMatch[i])) {
                    leftMatch[node] = i;
                    rightMatch[i] = node;
                    return true;
                }
            }
            return false;
        }

        private void support(int node) {
            for (int i = 0; i < graph.length; ++i) {
                if (graph[node][i] && !rightUsed[i]) {
                    rightUsed[i] = true;
                    leftUsed[rightMatch[i]] = false;
                    support(rightMatch[i]);
                }
            }
        }

        private class AhoCorasick {
            private final int initialCapacity = 3;
            private int[] next0;
            private int[] next1;
            private int[] ending;
            private int[] fail;
            private int[] nextWordFail;
            private int nodes;
            private int capacity;
            private int root;

            AhoCorasick() {
                next0 = new int[initialCapacity];
                next1 = new int[initialCapacity];
                ending = new int[initialCapacity];
                fail = new int[initialCapacity];
                nextWordFail = new int[initialCapacity];
                nodes = 0;
                capacity = initialCapacity;
                root = newNode();
            }

            public void add(String word, int index) {
                int node = root;
                for (char c : word.toCharArray()) {
                    if (c == 'a') {
                        if (next0[node] == -1) {
                            int x = newNode();
                            next0[node] = x;
                        }
                        node = next0[node];
                    } else {
                        if (next1[node] == -1) {
                            int x = newNode();
                            next1[node] = x;
                        }
                        node = next1[node];
                    }
                }
                ending[node] = index;
            }

            private int newNode() {
                ensureCapacity(nodes + 1);
                next0[nodes] = next1[nodes] = -1;
                fail[nodes] = nextWordFail[nodes] = -1;
                ending[nodes] = -1;
                return nodes++;
            }

            private void ensureCapacity(int size) {
                if (capacity < size) {
                    capacity = 2 * capacity + 1;
                    next0 = resize(next0, capacity);
                    next1 = resize(next1, capacity);
                    ending = resize(ending, capacity);
                    fail = resize(fail, capacity);
                    nextWordFail = resize(nextWordFail, capacity);
                }
            }

            private int[] resize(int[] a, int newSize) {
                int[] b = new int[newSize];
                System.arraycopy(a, 0, b, 0, a.length);
                return b;
            }

            public void buildLinks() {
                int[] q = new int[nodes];
                q[0] = root;
                int left = 0, right = 1;

                fail[root] = root;
                while (left < right) {
                    int node = q[left++];

                    for (int i = 0; i < 2; ++i) {
                        int[] next = i == 0 ? next0 : next1;
                        if (next[node] != -1) {
                            int p = next[node], k = fail[node];
                            while (k != root && next[k] == -1) k = fail[k];
                            if (next[k] != -1 && k != node) k = next[k];
                            fail[p] = k;
                            q[right++] = p;
                        }
                    }
                }
                fail[root] = -1;

                for (int i = 1; i < right; ++i) {
                    int node = q[i];
                    if (ending[fail[node]] != -1)
                        nextWordFail[node] = fail[node];
                    else nextWordFail[node] = nextWordFail[fail[node]];
                }
            }

            public int root() {
                return root;
            }

            public int next(int node, int c) {
                return c == 0 ? next0[node] : next1[node];
            }

            public int nextWordFail(int node) {
                return nextWordFail[node];
            }

            public boolean hasWord(int node) {
                return ending[node] != -1;
            }

            public int ending(int node) {
                return ending[node];
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