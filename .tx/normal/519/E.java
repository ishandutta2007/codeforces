import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    List<Integer>[] g;
    int[] tin, tout;
    int[][] up;
    int[] sz, h;
    int time = 0;

    void dfs(int v, int p, int h) {
        tin[v] = time++;
        this.h[v] = h;
        int op = p;
        sz[v] = 1;
        for (int i = 0; p != -1; i++) {
            up[v][i] = p;
            p = up[p][i];
        }
        p = op;
        for (int i : g[v]) {
            if (i != p) {
                dfs(i, v, h + 1);
                sz[v] += sz[i];
            }
        }
        tout[v] = time++;
    }

    boolean isParent(int child, int parent) {
        return tin[parent] < tin[child] && tout[parent] > tout[child];
    }

    int lca(int a, int b) {
        if (isParent(a, b)) {
            return b;
        }
        if (isParent(b, a)) {
            return a;
        }

        for (int i = 19; i >= 0; i--) {
            if (up[a][i] != -1 && !isParent(b, up[a][i])) {
                a = up[a][i];
            }
        }
        return up[a][0];
    }

    int top(int a, int d) {
        for (int i = 19; i >= 0; i--) {
            if ((d & (1 << i)) != 0) {
                a = up[a][i];
            }
        }
        return a;
    }

    void solve() throws IOException {
        int n = nextInt();
        g = createAdjacencyList(n);
        for (int i = 1; i < n; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }

        tin = new int[n];
        tout = new int[n];
        sz = new int[n];
        h = new int[n];
        up = new int[n][20];
        for (int[] i : up) {
            Arrays.fill(i, -1);
        }

        dfs(0, -1, 0);

        int m = nextInt();
        while (m-- > 0) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;

            if (x == y) {
                println(n);
                continue;
            }

//            if (isParent(x, y)) {
//                int _ = x;
//                x = y;
//                y = _;
//            }
//
//            if (isParent(y, x)) {
//                int d = h[y] - h[x];
//                if (d % 2 == 0) {
//                    println(1);
//                } else {
//                    println(0);
//                }
//                continue;
//            }

            int c = lca(x, y);
            int d1 = h[x] - h[c];
            int d2 = h[y] - h[c];
            if ((d1 + d2) % 2 == 1) {
                println(0);
                continue;
            }

            if (d1 < d2) {
                int _ = d1;
                d1 = d2;
                d2 = _;
                _ = x;
                x = y;
                y = _;
            }

            if (d1 == d2) {
                int t1 = top(x, d1 - 1);
                int t2 = top(y, d2 - 1);
                println(n - sz[t1] - sz[t2]);
                continue;
            }

            int d = (d1 + d2) / 2;
            int t = top(x, d - 1);
            println(sz[up[t][0]] - sz[t]);
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