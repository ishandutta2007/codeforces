import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    Set<Integer>[] g;
    boolean[] onCyc;
    boolean[] used;

    int dfs(int v, int p) {
        used[v] = true;
        for (Integer to : g[v]) {
            if (to == p) {
                continue;
            }
            if (used[to]) {
                onCyc[v] = true;
                g[v].remove(to);
                g[to].remove(v);
                return to;
            }
            int x = dfs(to, v);
            if (x == -2) {
                return -2;
            }
            if (x == -1) {
                continue;
            }
            if (x == v) {
                onCyc[v] = true;
                g[v].remove(to);
                g[to].remove(v);
                return -2;
            }
            onCyc[v] = true;
            g[v].remove(to);
            g[to].remove(v);
            return x;
        }
        return -1;
    }

    boolean dfs2(int v, int p) {
        used[v] = true;
        for (Integer to : g[v]) {
            if (to == p) {
                continue;
            }
            if (used[to]) {
                return false;
            }
            if (onCyc[to]) {
                return false;
            }
            if (!dfs2(to, v)) {
                return false;
            }
        }
        return true;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        g = new Set[n];
        for (int i = 0; i < n; i++) {
            g[i] = new TreeSet<>();
        }
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        onCyc = new boolean[n];
        used = new boolean[n];
        int x = dfs(0, -1);
        if (x != -2) {
            println("NO");
            return;
        }
        Arrays.fill(used, false);
        for (int i = 0; i < n; i++) {
            if (onCyc[i]) {
                if (!dfs2(i, -1)) {
                    println("NO");
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                println("NO");
                return;
            }
        }
        println("FHTAGN!");

    }

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
}