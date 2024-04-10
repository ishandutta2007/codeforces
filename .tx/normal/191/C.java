import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Edge {
        int to, id;

        public Edge(int to, int id) {
            this.to = to;
            this.id = id;
        }
    }

    List<Edge>[] g;

    int[] cntUp;
    int[] cntDone;

    int[] tin;
    int[] tout;
    int time = 0;

    int[][] up;

    void dfs1(int v, int p) {
        tin[v] = time++;

        int op = p;
        for (int i = 0; p != -1; i++) {
            up[v][i] = p;
            p = up[p][i];
        }
        p = op;

        for (Edge e : g[v]) {
            if (e.to != p) {
                dfs1(e.to, v);
            }
        }
        tout[v] = time++;
    }

    boolean isParent(int parent, int child) {
        return tin[parent] <= tin[child] && tout[parent] >= tout[child];
    }

    int lca(int a, int b) {
        if (isParent(a, b)) {
            return a;
        }
        if (isParent(b, a)) {
            return b;
        }

        for (int i = 20; i >= 0; i--) {
            if (up[a][i] != -1 && !isParent(up[a][i], b)) {
                a = up[a][i];
            }
        }
        return up[a][0];
    }

    int[] ans;

    int dfs2(int v, int p) {
        int curUp = cntUp[v];
        for (Edge e : g[v]) {
            if (e.to != p) {
                int x = dfs2(e.to, v);
                ans[e.id] = x;
                curUp += x;
            }
        }
        return curUp - cntDone[v];
    }

    void solve() throws IOException {
        int n = nextInt();
        g = createAdjacencyList(n);
        for (int i = 0; i + 1 < n; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            g[x].add(new Edge(y, i));
            g[y].add(new Edge(x, i));
        }

        cntUp = new int[n];
        cntDone = new int[n];

        tin = new int[n];
        tout = new int[n];

        up = new int[n][21];
        for (int[] i : up) {
            Arrays.fill(i, -1);
        }
        dfs1(0, -1);

        int m = nextInt();

        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            int z = lca(x, y);
            cntUp[x]++;
            cntUp[y]++;
            cntDone[z] += 2;
        }

        ans = new int[n - 1];
        dfs2(0, -1);

        for (int i : ans) {
            print(i);
            print(" ");
        }
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