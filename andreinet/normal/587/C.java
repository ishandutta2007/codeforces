import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private final int maxSize = 10;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            Tree t = new Tree(n);
            for (int i = 1; i < n; ++i)
                t.addEdge(in.nextInt() - 1, in.nextInt() - 1);

            int[] citizens = new int[m];
            for (int i = 0; i < m; ++i) citizens[i] = in.nextInt();

            t.build(citizens);

            while (q-- > 0) {
                int node1 = in.nextInt() - 1, node2 = in.nextInt() - 1, a = in.nextInt();
                int[] result = t.query(node1, node2);
                int cnt = a;
                while (cnt > 0 && result[cnt - 1] == -1) --cnt;

                out.print(cnt + " ");
                for (int i = 0; i < cnt; ++i) out.print((result[i] + 1) + " ");
                out.println();
            }
        }

        private void merge(int[] a, int[] b, int[] dest) {
            int pos = 0, i = 0, j = 0;
            while (pos < maxSize) {
                if ((a[i] < b[j] && a[i] != -1) || b[j] == -1) dest[pos++] = a[i++];
                else dest[pos++] = b[j++];
            }
        }

        private class Tree {
            int[] firstEdge;
            int[] nextEdge;
            int[] edgeTo;
            int nodes;
            int edges;
            int[] countCitizens;
            int[][] citizenIndexes;
            int[] posInPath;
            int[] subtreeSize;
            int[] nodePath;
            int[] pathFather;
            int[] pathSize;
            int[] pathLevel;
            int[][] paths;
            int countPaths;
            SegmentTree[] trees;

            Tree(int nodes) {
                this.nodes = nodes;
                firstEdge = new int[nodes];
                Arrays.fill(firstEdge, -1);
                nextEdge = new int[2 * nodes - 2];
                edgeTo = new int[2 * nodes - 2];
                edges = 0;
            }

            private void addSingleEdge(int from, int to) {
                edgeTo[edges] = to;
                nextEdge[edges] = firstEdge[from];
                firstEdge[from] = edges++;
            }

            public void addEdge(int n1, int n2) {
                addSingleEdge(n1, n2);
                addSingleEdge(n2, n1);
            }

            public void build(int[] citizens) {
                countCitizens = new int[nodes];
                citizenIndexes = new int[nodes][];
                for (int p : citizens) countCitizens[p - 1]++;

                for (int i = 0; i < nodes; ++i) {
                    citizenIndexes[i] = new int[countCitizens[i]];
                    countCitizens[i] = 0;
                }

                for (int i = 0; i < citizens.length; ++i) {
                    int p = citizens[i] - 1;
                    citizenIndexes[p][countCitizens[p]++] = i;
                }

                nodePath = new int[nodes];
                decomposition();
            }

            private void decomposition() {
                subtreeSize = new int[nodes];
                dfs1(0, -1);
                paths = new int[countPaths][];
                pathSize = new int[countPaths];
                for (int i = 0; i < nodes; ++i)
                    pathSize[nodePath[i]]++;
                paths = new int[countPaths][];
                for (int i = 0; i < countPaths; ++i) {
                    paths[i] = new int[pathSize[i]];
                    pathSize[i] = 0;
                }
                pathLevel = new int[countPaths];
                pathFather = new int[countPaths];
                posInPath = new int[nodes];
                dfs2(0, -1);

                trees = new SegmentTree[countPaths];
                for (int i = 0; i < countPaths; ++i) {
                    int[][] citizens = new int[pathSize[i]][];
                    for (int j = 0; j < pathSize[i]; ++j)
                        citizens[j] = citizenIndexes[paths[i][j]];
                    trees[i] = new SegmentTree(citizens);
                }
            }

            private void dfs1(int node, int prev) {
                int leaf = -1;
                subtreeSize[node] = 1;
                for (int p = firstEdge[node]; p != -1; p = nextEdge[p]) {
                    int to = edgeTo[p];
                    if (to == prev) continue;
                    dfs1(to, node);
                    if (leaf == -1 || subtreeSize[to] > subtreeSize[leaf])
                        leaf = to;
                    subtreeSize[node] += subtreeSize[to];
                }

                if (leaf == -1) nodePath[node] = countPaths++;
                else nodePath[node] = nodePath[leaf];
            }

            private void dfs2(int node, int prev) {
                posInPath[node] = pathSize[nodePath[node]];
                paths[nodePath[node]][pathSize[nodePath[node]]++] = node;
                for (int p = firstEdge[node]; p != -1; p = nextEdge[p]) {
                    int to = edgeTo[p];
                    if (to == prev) continue;
                    if (nodePath[to] != nodePath[node]) {
                        pathFather[nodePath[to]] = node;
                        pathLevel[nodePath[to]] = pathLevel[nodePath[node]] + 1;
                    }
                    dfs2(to, node);
                }
            }

            public int[] query(int node1, int node2) {
                int p1 = nodePath[node1], p2 = nodePath[node2];
                int[] result = new int[maxSize];
                Arrays.fill(result, -1);
                while (p1 != p2) {
                    if (pathLevel[p1] > pathLevel[p2]) {
                        merge(result.clone(), trees[p1].query(0, posInPath[node1] + 1), result);
                        node1 = pathFather[p1];
                        p1 = nodePath[node1];
                    } else {
                        merge(result.clone(), trees[p2].query(0, posInPath[node2] + 1), result);
                        node2 = pathFather[p2];
                        p2 = nodePath[node2];
                    }
                }
                int left = Math.min(posInPath[node1], posInPath[node2]);
                int right = Math.max(posInPath[node1], posInPath[node2]) + 1;
                merge(result.clone(), trees[p1].query(left, right), result);
                return result;
            }

        }

        private class SegmentTree {
            int size;
            int[][] tree;

            SegmentTree(int[][] numbers) {
                this.size = numbers.length;
                this.tree = new int[4 * size + 5][maxSize];

                build(0, 0, size - 1, numbers);
            }

            private void build(int node, int left, int right, int[][] numbers) {
                if (left == right) {
                    int[] cnode = this.tree[node];
                    Arrays.fill(cnode, -1);
                    int[] cnumbers = numbers[left].clone();
                    ArraysUtils.paranoidSort(cnumbers);
                    for (int i = 0; i < cnode.length && i < cnumbers.length; ++i)
                        cnode[i] = cnumbers[i];
                } else {
                    int mid = (left + right) / 2;
                    build(2 * node + 1, left, mid, numbers);
                    build(2 * node + 2, mid + 1, right, numbers);
                    merge(tree[2 * node + 1], tree[2 * node + 2], tree[node]);
                }
            }

            public int[] query(int from, int to) {
                int[] result = new int[maxSize];
                Arrays.fill(result, -1);
                cquery(0, 0, size - 1, from, to - 1, result);
                return result;
            }

            private void cquery(int node, int left, int right, int lq, int rq, int[] result) {
                if (lq <= left && right <= rq) {
                    merge(tree[node], result.clone(), result);
                } else {
                    int mid = (left + right) / 2;
                    if (lq <= mid) cquery(2 * node + 1, left, mid, lq, rq, result);
                    if (rq > mid) cquery(2 * node + 2, mid + 1, right, lq, rq, result);
                }
            }

        }

    }

    static class ArraysUtils {
        public static void randomShuffle(int[] A, int from, int to) {
            Random rnd = new Random();
            for (int i = from; i < to; ++i) {
                int pos = i + rnd.nextInt(to - i);
                swap(A, i, pos);
            }
        }

        public static void paranoidSort(int[] A, int from, int to) {
            randomShuffle(A, from, to);
            Arrays.sort(A, from, to);
        }

        public static void paranoidSort(int[] A) {
            paranoidSort(A, 0, A.length);
        }

        public static void swap(int[] A, int i, int j) {
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
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