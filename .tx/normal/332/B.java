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

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int[] a = nextIntArray(n);
        long[] s = new long[n - k + 1];
        long t = 0;
        for (int i = 0; i < k; i++) {
            t += a[i];
        }
        s[0] = t;
        for (int i = k; i < n; i++) {
            t += a[i] - a[i - k];
            s[i - k + 1] = t;
        }

        long[] lmax = new long[s.length];
        long[] rmax = new long[s.length];
        lmax[0] = s[0];
        rmax[s.length - 1] = s[s.length - 1];
        int[] pmax = new int[s.length];
        pmax[s.length - 1] = s.length - 1;
        for (int i = s.length - 2; i >= 0; i--) {
            if (s[i] >= rmax[i + 1]) {
                rmax[i] = s[i];
                pmax[i] = i;
            } else {
                rmax[i] = rmax[i + 1];
                pmax[i] = pmax[i + 1];
            }
        }
        long ans = 0;
        int aa = -1, ab = -1;
        for (int i = 0; i <= n - 2 * k; i++) {
            t = s[i] + rmax[i + k];
            if (t > ans) {
                ans = t;
                aa = i;
                ab = pmax[i + k];
            }
        }
        printf("%d %d", aa + 1, ab + 1);
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