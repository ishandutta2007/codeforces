import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
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
            int n = in.nextInt(), m = in.nextInt();
            final int BUCKET = 500;

            int[] from = new int[m];
            int[] to = new int[m];
            int[] nextEdge = new int[m];

            int[] colorFirstEdge = new int[m];
            int[] colorDeg = new int[m];
            Arrays.fill(colorFirstEdge, -1);


            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1, c = in.nextInt() - 1;
                from[i] = x;
                to[i] = y;
                nextEdge[i] = colorFirstEdge[c];
                colorFirstEdge[c] = i;
                colorDeg[c]++;
            }

            int q = in.nextInt();
            int[] x = new int[q];
            int[] y = new int[q];
            int[] answer = new int[q];
            for (int i = 0; i < q; ++i) {
                x[i] = in.nextInt() - 1;
                y[i] = in.nextInt() - 1;
                if (x[i] > y[i]) {
                    int aux = x[i];
                    x[i] = y[i];
                    y[i] = aux;
                }
            }

            Map<Pairii, Integer> compAdd = new HashMap<>();

            int[] father = new int[n];
            boolean[] used = new boolean[n];
            int[] nodes = new int[n];
            for (int c = 0; c < m; ++c) {
                if (colorDeg[c] > BUCKET) {
                    for (int e = colorFirstEdge[c]; e != -1; e = nextEdge[e]) {
                        union(father, from[e], to[e]);
                    }
                    for (int i = 0; i < q; ++i) {
                        if (find(father, x[i]) == find(father, y[i])) {
                            answer[i]++;
                        }
                    }
                    for (int e = colorFirstEdge[c]; e != -1; e = nextEdge[e]) {
                        father[from[e]] = 0;
                        father[to[e]] = 0;
                    }
                } else {
                    int pos = 0;
                    for (int e = colorFirstEdge[c]; e != -1; e = nextEdge[e]) {
                        union(father, from[e], to[e]);
                        if (!used[from[e]]) {
                            nodes[pos++] = from[e];
                            used[from[e]] = true;
                        }
                        if (!used[to[e]]) {
                            nodes[pos++] = to[e];
                            used[to[e]] = true;
                        }
                    }
                    for (int i = 0; i < pos; ++i) {
                        int n1 = nodes[i];
                        for (int j = 0; j < i; ++j) {
                            int n2 = nodes[j];
                            if (find(father, n1) == find(father, n2)) {
                                if (n1 < n2) {
                                    add(compAdd, new Pairii(n1, n2));
                                } else {
                                    add(compAdd, new Pairii(n2, n1));
                                }
                            }
                        }
                    }
                    for (int e = colorFirstEdge[c]; e != -1; e = nextEdge[e]) {
                        father[from[e]] = 0;
                        father[to[e]] = 0;
                        used[from[e]] = false;
                        used[to[e]] = false;
                    }
                }
            }

            for (int i = 0; i < q; ++i) {
                answer[i] += get(compAdd, new Pairii(x[i], y[i]));
                out.println(answer[i]);
            }
        }

        int find(int[] father, int x) {
            int y, p;
            for (y = x; father[y] != 0; y = father[y]) ;
            for (; x != y; x = p) {
                p = father[x];
                father[x] = y;
            }
            return y;
        }

        void union(int[] father, int x, int y) {
            x = find(father, x);
            y = find(father, y);
            if (x == y) return;
            father[x] = y;
        }

        void add(Map<Pairii, Integer> m, Pairii e) {
            m.put(e, get(m, e) + 1);
        }

        int get(Map<Pairii, Integer> m, Pairii e) {
            Integer p = m.get(e);
            return p == null ? 0 : p;
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