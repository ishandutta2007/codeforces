import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;
    final int mod = inf + 7;


    final static String IO = "_std";

    long pow(long a, int pow) {
        if (pow == 0) {
            return 1;
        }
        long t = pow(a, pow / 2);
        t = t * t % mod;
        if (pow % 2 == 1) {
            t = t * a % mod;
        }
        return t;
    }

    int MAX_F = 200031;
    long[] fact = new long[MAX_F + 1];
    long[] backFact = new long[fact.length];

    void initFact() {
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        for (int i = 0; i < fact.length; i++) {
            backFact[i] = pow(fact[i], mod - 2);
        }
    }

    long c(int n, int k) {
        return fact[n] * backFact[k] % mod * backFact[n - k] % mod;
    }

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    void solve() throws IOException {
        initFact();
        int h = nextInt();
        int w = nextInt();
        int n = nextInt();

        Point[] a = new Point[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(nextInt() - 1, nextInt() - 1);
        }
        a[n] = new Point(h - 1, w - 1);
        Arrays.sort(a, (x, y) -> x.x == y.x ? Integer.compare(x.y, y.y) : Integer.compare(x.x, y.x));

        long[] d = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            int x = a[i].x;
            int y = a[i].y;

            long cur = c(x + y, x);
            for (int j = 0; j < i; j++) {
                if (a[j].x <= x && a[j].y <= y) {
                    cur = ((cur - d[j] * c(x - a[j].x + y - a[j].y, x - a[j].x)) % mod + mod) % mod;
                }
            }
            d[i] = cur;
        }
        println(d[n]);
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
        } else if ("_iodef".equals(IO)) {
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