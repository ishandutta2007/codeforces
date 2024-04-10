import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    public void solve() throws IOException {
        int n = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        int m = a[0].length;
        long[] d1 = new long[1 << m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int x = 0;
                    for (int k = 0; k < m; k++) {
                        if (a[i][k] == a[j][k]) {
                            x |= (1 << k);
                        }
                    }
                    d1[x] |= (1L << i);
                    d1[x] |= (1L << j);
                }
            }
        }
        for (int i = (1 << m) - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                d1[i] |= d1[i | (1 << j)];
            }
        }
        double[] d = new double[1 << m];
        d[0] = 1;
        for (int mask = 0; mask < (1 << m); mask++) {
            double bc = Integer.bitCount(mask);
            int bc1 = Long.bitCount(d1[mask]);
            if (bc1 == 0) {
                continue;
            }
            for (int i = 0; i < m; i++) {
                if ((mask & (1 << i)) == 0) {
                    int nmask = mask | (1 << i);
                    double nbc1 = Long.bitCount(d1[nmask]);
                    d[nmask] += d[mask] * (nbc1 / bc1) / (m - bc);
                }
            }
        }
        double ans = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            double finish = 0;
            int bc1 = Long.bitCount(d1[mask]);
            int bc = Long.bitCount(mask);
            for (int i = 0; i < m; i++) {
                if ((mask & (1 << i)) > 0) {
                    int nmask = mask & ~(1 << i);
                    int nbc1 = Long.bitCount(d1[nmask]);
                    if (nbc1 == 0) {
                        continue;
                    }
                    int nbc = Long.bitCount(nmask);
                    finish += d[nmask] * (nbc1 - bc1) / nbc1 / (m - nbc);
                }
            }
            ans += bc * finish;
        }
        printf("%.11f", ans);
    }

    public void run() {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : (s + ".out"));
        in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : (s + ".in")));
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignored) {
        }
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

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[x];
            a[x] = t;
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