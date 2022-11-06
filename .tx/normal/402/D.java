import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int[] b;
    int rg, rb;
    void cgb(int x) {
        rg = rb = 0;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                boolean bad = Arrays.binarySearch(b, i) >= 0;
                do {
                    x /= i;
                    if (bad) {
                        rb++;
                    } else {
                        rg++;
                    }
                } while (x % i == 0);
            }
        }
        if (x != 1) {
            boolean bad = Arrays.binarySearch(b, x) >= 0;
            if (bad) {
                rb++;
            } else {
                rg++;
            }
        }
    }

    Set<Integer> sb;
    Map<Integer, Integer> sf = new HashMap<>();

    int f(int x) {
        if (x == 1) {
            return 0;
        }
        Integer t = sf.get(x);
        if (t != null) {
            return t;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int a = 1;
                if (sb.contains(i)) {
                    a = -1;
                }
                int res = f(x / i) + a;
                sf.put(x, res);
                return res;
            }
        }
        int res = sb.contains(x) ? -1 : 1;
        sf.put(x, res);
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] a = nextIntArray(n);
        b = nextIntArray(m);
        sb = new HashSet<>(m);
        for (int i : b) {
            sb.add(i);
        }
        int[] s = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            s[i] = f(a[i - 1]) + s[i - 1];
        }
        int[] gs = new int[n + 1];
        gs[0] = 1;
        gs[1] = a[0];
        for (int i = 2; i <= n; i++) {
            gs[i] = gcd(gs[i - 1], a[i - 1]);
        }

        int[][] d = new int[n][n + 1];
        d[0][1] = 0;
        d[0][0] = f(a[0]);
        for (int i = 1; i < n; i++) {
            d[i][i + 1] = -inf;
            int fai = f(a[i]);
            int fgsi1 = f(gs[i + 1]);
            for (int j = i; j >= 0; j--) {
                d[i][j] = d[i - 1][j] + fai;
                d[i][i + 1] = max(d[i][i + 1], d[i - 1][j] + fai - fgsi1 * (i - j + 1));
            }
        }

        int mx = -inf;
        for (int i = 0; i <= n; i++) {
            mx = max(mx, d[n - 1][i]);
        }
        println(mx);
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