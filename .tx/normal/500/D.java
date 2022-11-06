import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Edge {
        int to;
        long len;
        int id;

        public Edge(int to, long len, int id) {
            this.to = to;
            this.len = len;
            this.id = id;
        }
    }

    List<Edge>[] g;
    int[] cnt;
    long[] lens;
    int[] vByE;

    int dfs(int v, int p) {
        cnt[v] = 1;
        for (Edge edge : g[v]) {
            if (edge.to != p) {
                lens[edge.to] = edge.len;
                vByE[edge.id] = edge.to;
                cnt[v] += dfs(edge.to, v);
            }
        }
        return cnt[v];
    }

    long c2(long n) {
        return n * (n - 1) / 2;
    }

    void solve() throws IOException {
        int n = nextInt();
        g = createAdjacencyList(n);
        for (int i = 0; i < n - 1; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            long len = nextLong();
            g[x].add(new Edge(y, len, i));
            g[y].add(new Edge(x, len, i));
        }
        cnt = new int[n];
        lens = new long[n];
        vByE = new int[n - 1];
        dfs(0, -1);
        long[] d = new long[n];
        for (int i = 1; i < n; i++) {
            d[i] = 2L * cnt[i] * c2(n - cnt[i]) + 2L * c2(cnt[i]) * (n - cnt[i]);
        }
        double sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int v = vByE[i];
            sum += 1.0 * d[v] * lens[v];
        }
        int q = nextInt();
        long n3 = 1L * n * (n - 1) * (n - 2) / 6;
        for (; q-- > 0; ) {
            int e = nextInt() - 1;
            int w = nextInt();
            int v = vByE[e];
            sum -= 1.0 * d[v] * lens[v];
            lens[v] = w;
            sum += 1.0 * d[v] * lens[v];
            printf("%.11f%n", (double) sum / n3);
        }
    }

    void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        } finally {
            close();
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String filename) throws IOException {
        super("".equals(filename) ? "output.txt" : filename + ".out");
        in = new BufferedReader(new FileReader("".equals(filename) ? "input.txt" : filename + ".in"));
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
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

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    boolean nextPerm(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
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
        return false;
    }

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}