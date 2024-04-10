import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
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
            int n = in.nextInt(), m = in.nextInt();

            int[] from = new int[m], to = new int[m];
            int[] color = new int[m], cost = new int[m];

            List<Integer>[] graph = new List[n];
            for (int i = 0; i < n; ++i) graph[i] = new ArrayList<>();

            int[] removeEdge1 = new int[n], removeEdge2 = new int[n];
            Arrays.fill(removeEdge1, -1);
            Arrays.fill(removeEdge2, -1);

            HashMap<Pairii, Integer> h = new HashMap<>();
            int[] needRemove = new int[n];
            boolean[] mightRemove = new boolean[m];

            for (int i = 0; i < m; ++i) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
                color[i] = in.nextInt();
                cost[i] = in.nextInt();

                Pairii p;

                p = new Pairii(from[i], color[i]);
                if (h.containsKey(p)) {
                    needRemove[from[i]]++;
                    removeEdge1[from[i]] = i;
                    removeEdge2[from[i]] = h.get(p);
                    mightRemove[i] = true;
                    mightRemove[h.get(p)] = true;
                } else {
                    h.put(p, i);
                }

                p = new Pairii(to[i], color[i]);
                if (h.containsKey(p)) {
                    needRemove[to[i]]++;
                    removeEdge1[to[i]] = i;
                    removeEdge2[to[i]] = h.get(p);
                    mightRemove[i] = true;
                    mightRemove[h.get(p)] = true;
                } else {
                    h.put(p, i);
                }

                graph[from[i]].add(i);
                graph[to[i]].add(i);
            }

            for (int i = 0; i < n; ++i) {
                if (needRemove[i] > 1) {
                    out.println("No");
                    return;
                }
            }

            out.println("Yes");

            int nvar = 3 * m;

            SATBuilder builder = (solver, currentCost) -> {
                int cvar = m;
                for (int i = 0; i < n; ++i) {
                    if (needRemove[i] == 1) {
                        int edge1 = removeEdge1[i], edge2 = removeEdge2[i];
                        solver.addOr(edge1, edge2);
                    }
                    int prev = -1;
                    for (int curr : graph[i]) {
                        int c = cvar++;
                        solver.addOr(nvar + curr, c);
                        if (prev != -1) {
                            solver.addOr(nvar + prev, c);
                            solver.addOr(nvar + prev, nvar + curr);
                        }
                        prev = c;
                    }
                }
                for (int i = 0; i < m; ++i)
                    if (cost[i] > currentCost || !mightRemove[i])
                        solver.fixVariable(nvar + i);
            };

            int ans = (int) 1e9;

            for (int step = 1 << 29; step > 0; step >>= 1) {
                if (ans - step < 0) continue;
                int currentCost = ans - step;

                Solver2Sat solver = new Solver2Sat(nvar);
                builder.build(solver, currentCost);

                if (solver.hasSolution()) ans -= step;
            }

            Solver2Sat solver = new Solver2Sat(nvar);
            builder.build(solver, ans);

            boolean[] values = solver.getSolution();
            int cnt = 0;
            for (int i = 0; i < m; ++i)
                if (values[i])
                    ++cnt;

            out.println(ans + " " + cnt);
            for (int i = 0; i < m; ++i)
                if (values[i])
                    out.print((i + 1) + " ");

            out.println();
        }

        private interface SATBuilder {
            void build(Solver2Sat solver, int currentCost);

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

    static class Solver2Sat {
        private static final int initialCapacity = 1;
        private int[] firstEdge;
        private int[] edgeTo;
        private int[] nextEdge;
        private int[] t_firstEdge;
        private int[] t_edgeTo;
        private int[] t_nextEdge;
        private boolean[] values;
        int size;
        int edges;
        int capacity;

        public Solver2Sat(int size) {
            this.size = size;
            firstEdge = new int[2 * size];
            Arrays.fill(firstEdge, -1);
            t_firstEdge = firstEdge.clone();
            edgeTo = new int[initialCapacity];
            nextEdge = new int[initialCapacity];
            t_edgeTo = new int[initialCapacity];
            t_nextEdge = new int[initialCapacity];
            edges = 0;
            capacity = initialCapacity;
            values = null;
        }

        public void addOr(int from, int to) {
            addImply(non(from), to);
            addImply(non(to), from);
        }

        public void fixVariable(int x) {
            addImply(non(x), x);
        }

        public void addImply(int from, int to) {
            ensureEdgeCapacity(edges + 1);
            edgeTo[edges] = to;
            nextEdge[edges] = firstEdge[from];
            firstEdge[from] = edges;

            t_edgeTo[edges] = from;
            t_nextEdge[edges] = t_firstEdge[to];
            t_firstEdge[to] = edges++;
        }

        public void solveSystem() {
            boolean[] used = new boolean[2 * size];
            int[] order = new int[2 * size];
            int pos = 0;
            for (int i = 0; i < 2 * size; ++i)
                if (!used[i])
                    pos = dfs1(used, order, pos, i);
            values = new boolean[2 * size];
            for (int i = 2 * size - 1; i >= 0; --i) {
                int node = order[i];
                if (!values[node] && !values[non(node)])
                    dfs2(used, node);
            }

            for (int i = 0; i < 2 * size; ++i) {
                for (int p = firstEdge[i]; p != -1; p = nextEdge[p]) {
                    int to = edgeTo[p];
                    if (values[i] && !values[to]) {
                        values = new boolean[0];
                        return;
                    }
                }
                if (values[i] == values[non(i)]) {
                    values = new boolean[0];
                    return;
                }
            }
        }

        public boolean[] getSolution() {
            if (values == null) solveSystem();
            return Arrays.copyOf(values, size);
        }

        public boolean hasSolution() {
            if (values == null) solveSystem();
            return values.length != 0;
        }

        private int non(int x) {
            return x < size ? x + size : x - size;
        }

        private void ensureEdgeCapacity(int edges) {
            if (edges > capacity) {
                capacity = 2 * capacity + 1;
                edgeTo = resize(edgeTo, capacity);
                nextEdge = resize(nextEdge, capacity);
                t_edgeTo = resize(t_edgeTo, capacity);
                t_nextEdge = resize(t_nextEdge, capacity);
            }
        }

        private int[] resize(int[] a, int newSize) {
            int[] b = new int[newSize];
            System.arraycopy(a, 0, b, 0, a.length);
            return b;
        }

        private int dfs1(boolean[] used, int[] order, int pos, int node) {
            used[node] = true;
            for (int p = firstEdge[node]; p != -1; p = nextEdge[p])
                if (!used[edgeTo[p]])
                    pos = dfs1(used, order, pos, edgeTo[p]);
            order[pos++] = node;
            return pos;
        }

        private void dfs2(boolean[] used, int node) {
            used[node] = false;
            values[non(node)] = true;
            for (int p = t_firstEdge[node]; p != -1; p = t_nextEdge[p])
                if (used[t_edgeTo[p]])
                    dfs2(used, t_edgeTo[p]);
        }

    }

    static class Pairii implements Comparable<Pairii> {
        public int first;
        public int second;

        public Pairii() {
        }

        public Pairii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pairii other) {
            if (first != other.first) return first < other.first ? -1 : 1;
            if (second != other.second) return second < other.second ? -1 : 1;
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
}