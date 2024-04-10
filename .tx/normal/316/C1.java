import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Edge {
        int to, f, c, cost;

        public Edge(int to, int c, int cost) {
            this.to = to;
            this.c = c;
            this.cost = cost;
            this.f = 0;
        }
    }

    List<Edge> edges = new ArrayList<>();
    List<Integer>[] g;

    void addEdge(int from, int to, int cap, int cost) {
        g[from].add(edges.size());
        edges.add(new Edge(to, cap, cost));
        g[to].add(edges.size());
        edges.add(new Edge(from, 0, -cost));
    }

    class QItem implements Comparable<QItem> {
        int d, id;

        public QItem(int d, int id) {
            this.d = d;
            this.id = id;
        }

        @Override
        public int compareTo(QItem o) {
            return Integer.compare(d, o.d);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[][] a = new int[n][];
        for (int i = 0; i < n; i++) {
            a[i] = nextIntArray(m);
        }

        int s = 0;
        int t = n * m + 1;
        g = createAdjacencyList(n * m + 2);
        int[] dx = new int[] {-1, 1, 0, 0};
        int[] dy = new int[] {0, 0, 1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (((i + j) & 1) == 0) {
                    addEdge(0, i * m + j + 1, 1, 0);
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        addEdge(i * m + j + 1, x * m + y + 1, 1, a[i][j] == a[x][y] ? 0 : 1);
                    }
                } else {
                    addEdge(i * m + j + 1, t, 1, 0);
                }
            }
        }

        int flow = 0;
        int cost = 0;
        n = n * m + 2;
        int[] d = new int[n];
        int[] p = new int[n];
        int[] phi = new int[n];
        int[] f = new int[n];
        f[s] = inf;
        Queue<QItem> q = new PriorityQueue<>();
        boolean[] done = new boolean[n];

        while (true) {
            Arrays.fill(d, inf);
            Arrays.fill(p, -1);
            d[s] = 0;
            Arrays.fill(done, false);

            q.add(new QItem(0, s));

            while (!q.isEmpty()) {
                int v = q.poll().id;
                if (done[v]) {
                    continue;
                }
                done[v] = true;
                for (int i : g[v]) {
                    Edge e = edges.get(i);
                    if (e.f == e.c) {
                        continue;
                    }
                    int c = d[v] + e.cost + phi[v] - phi[e.to];
                    if (d[e.to] > c) {
                        d[e.to] = c;
                        q.add(new QItem(d[e.to], e.to));
                        p[e.to] = i;
                        f[e.to] = min(f[v], e.c - e.f);
                    }
                }
            }

            if (p[t] == -1) {
                break;
            }

            int cf = f[t];
            int x = t;
            int cc = 0;
            while (p[x] != -1) {
                Edge e = edges.get(p[x]);
                e.f += cf;
                cc += e.cost;
                e = edges.get(p[x] ^ 1);
                e.f -= cf;
                x = e.to;
            }

            flow += cf;
            cost += cf * cc;

            for (int i = 0; i < n; i++) {
                if (d[i] != inf) {
                    phi[i] += d[i] - d[t];
                }
            }
        }

        println(cost);
    }

    BufferedReader in;
    StringTokenizer stok;

    Main() {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String fileIn, String fileOut) throws IOException {
        super(fileOut);
        in = new BufferedReader(new FileReader(fileIn));
    }

    public static void main(String[] args) throws IOException {
        Main main;
        if ("_std".equals(IO)) {
            main = new Main();
        } else if ("_iotxt".equals(IO)) {
            main = new Main("input.txt", "output.txt");
        } else {
            main = new Main(IO + ".in", IO + ".out");
        }
        main.solve();
        main.close();
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    int[] nextIntArraySorted(int len) throws IOException {
        int[] a = nextIntArray(len);
        shuffle(a);
        Arrays.sort(a);
        return a;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    void shuffleAndSort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    boolean nextPermutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a) {
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int n) {
        List<T>[] res = new List[n];
        for (int i = 0; i < n; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }

    void println(Object... a) {
        for (int i = 0; i < a.length; i++) {
            if (i != 0) {
                print(" ");
            }
            print(a[i]);
        }
        println();
    }
}