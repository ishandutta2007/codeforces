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

    List<Integer>[] g;
    int[] used;
    boolean hasCycle = false;

    void dfs(int v, int p) {
        used[v] = 1;
        for (Integer to : g[v]) {
            if (to == p) {
                continue;
            }
            if (used[to] == 0) {
                dfs(to, v);
            } else {
                hasCycle = true;
            }
        }
        used[v] = 2;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        g = createAdjacencyList(n);
        used = new int[n];
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        dfs(0, -1);
        Arrays.sort(g, (a, b) -> Integer.compare(a.size(), b.size()));
        boolean visitedAll = true;
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                visitedAll = false;
            }
        }
        final String UNKNOWN = "unknown topology";
        final String BUS = "bus topology";
        final String RING = "ring topology";
        final String STAR = "star topology";
        if (!visitedAll) {
            println(UNKNOWN);
            return;
        }
        if (!hasCycle) {
            if (g[0].size() == 1 && g[1].size() == 1 && g[2].size() == 2 && g[n - 1].size() == 2) {
                println(BUS);
            } else {
                boolean allOne = true;
                for (int i = 0; i < n - 1; i++) {
                    if (g[i].size() != 1) {
                        allOne = false;
                    }
                }
                if (allOne && g[n - 1].size() == n - 1) {
                    print(STAR);
                } else {
                    print(UNKNOWN);
                }
            }
        } else {
            if (g[0].size() == 2 && g[n - 1].size() == 2) {
                println(RING);
            } else {
                println(UNKNOWN);
            }
        }
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