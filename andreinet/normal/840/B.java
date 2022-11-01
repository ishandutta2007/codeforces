import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int[] firstEdge;
        int[] nextEdge;
        int[] to;
        int edges;
        int[] values;
        IntList fans;
        boolean[] used;
        int[] deg;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            firstEdge = new int[n];
            Arrays.fill(firstEdge, -1);
            nextEdge = new int[2 * m];
            to = new int[2 * m];
            values = new int[n];
            int odd = 0;
            int root = 0;
            for (int i = 0; i < n; ++i) {
                values[i] = in.nextInt();
                if (values[i] == 1) {
                    odd++;
                }
                if (values[i] == -1) {
                    root = i;
                }
            }
            if (odd % 2 == 1 && values[root] != -1) {
                out.println(-1);
                return;
            }
            while (m-- > 0) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                addEdge(x, y);
                addEdge(y, x);
            }
            used = new boolean[n];
            deg = new int[n];
            fans = new IntList();
            dfs(root);
            out.println(fans.size());
            for (IntIterator it = fans.iterator(); it.hasNext(); ) {
                int e = it.nextInt();
                out.println(e + 1);
            }
        }

        private void dfs(int node) {
            used[node] = true;
            for (int e = firstEdge[node]; e != -1; e = nextEdge[e]) {
                int to = this.to[e];
                if (!used[to]) {
                    dfs(to);
                    if (values[to] != -1 && deg[to] != values[to]) {
                        deg[node] ^= 1;
                        fans.add(e / 2);
                    }
                }
            }
        }

        private void addEdge(int from, int to) {
            this.to[edges] = to;
            nextEdge[edges] = firstEdge[from];
            firstEdge[from] = edges++;
        }

    }

    static interface IntIterator extends Iterator<Integer> {
        int nextInt();

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

    static class IntList implements Iterable<Integer> {
        int[] elem;
        int size;

        public IntList() {
            this(0, 0, 1);
        }

        public IntList(int size) {
            this(size, 0, Math.max(1, size));
        }

        public IntList(int size, int value) {
            this(size, value, Math.max(1, size));
        }

        public IntList(int size, int value, int capacity) {
            elem = new int[capacity];
            Arrays.fill(elem, 0, size, value);
            this.size = size;
        }

        private IntList(int... e) {
            elem = e.clone();
            size = e.length;
        }

        public void add(int e) {
            if (size + 1 > elem.length) {
                increaseCapacity();
            }
            elem[size++] = e;
        }

        private void increaseCapacity() {
            changeCapacity(3 * elem.length / 2 + 1);
        }

        private void changeCapacity(int newCapacity) {
            int[] nElem = new int[newCapacity];
            System.arraycopy(elem, 0, nElem, 0, Math.min(elem.length, newCapacity));
            elem = nElem;
        }

        public IntIterator iterator() {
            return new IntIterator() {
                int pos = 0;


                public Integer next() {
                    return IntList.this.elem[pos++];
                }


                public boolean hasNext() {
                    return pos < IntList.this.size;
                }


                public int nextInt() {
                    return IntList.this.elem[pos++];
                }
            };
        }

        public int size() {
            return size;
        }

        public int hashCode() {
            int hashCode = 0;
            for (int i = 0; i < size; ++i) {
                hashCode = 31 * hashCode + elem[i];
            }
            return hashCode;
        }

    }
}