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

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int cntOn(int x1, int y1, int x2, int y2) {
        return gcd(abs(x2 - x1), abs(y1 - y2));
    }

    long cross(long x1, long y1, long x2, long y2) {
        return x1 * y2 - x2 * y1;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        double n2 = 1;
        for (int i = 0; i < n; i++) {
            n2 *= 2;
        }
        double all = n2 - 1 - n - 1.0 * n * (n - 1) / 2;
        long s = 0;
        long cntOn = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            s += cross(x[i], y[i], x[j], y[j]);
            cntOn += cntOn(x[i], y[i], x[j], y[j]);
        }
        long cntIn = (s - cntOn) / 2 + 1;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            long ts = 0;
            long on = 0;
            double pr = 0.25;
            double curAll = n2 / 4;
            for (int j = 1; j <= min(74, n - 1); j++) {
                int prev = (i + j - 1) % n;
                int cur = (i + j) % n;
                on += cntOn(x[prev], y[prev], x[cur], y[cur]);
                ts += cross(x[prev] - x[i], y[prev] - y[i], x[cur] - x[i], y[cur] - y[i]);
                long newOn = j == 1 ? 0 : cntOn(x[i], y[i], x[cur], y[cur]) - 1;
                long left = (ts - on - (newOn) - 1) / 2 + 1 + newOn;
                if (j > 1) {
                    if (n <= 200) {
                        ans += left * (curAll - 1) / all;
                    } else {
                        ans += left * pr;
                    }
                }
                pr /= 2;
                curAll /= 2;
            }
        }
        printf("%.11f", cntIn - ans);
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