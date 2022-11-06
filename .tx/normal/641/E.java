import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Treap {
        int x, y, sz;
        Treap l, r;

        public Treap(int x) {
            this.x = x;
            y = rand.nextInt();
            sz = 1;
            l = r = null;
        }
    }

    int getSz(Treap t) {
        if (t == null) {
            return 0;
        }
        return t.sz;
    }

    void recalc(Treap t) {
        if (t != null) {
            t.sz = getSz(t.l) + getSz(t.r) + 1;
        }
    }

    Treap[] split(Treap t, int x) {
        if (t == null) {
            return new Treap[] {null, null};
        }
        Treap[] r;
        if (x < t.x) {
            r = split(t.l, x);
            t.l = r[1];
            r[1] = t;
        } else {
            r = split(t.r, x);
            t.r = r[0];
            r[0] = t;
        }
        recalc(r[0]);
        recalc(r[1]);
        return r;
    }

    Treap merge(Treap l, Treap r) {
        if (l == null || r == null) {
            return l == null ? r : l;
        }
        Treap t;
        if (l.y < r.y) {
            l.r = merge(l.r, r);
            t = l;
        } else {
            r.l = merge(l, r.l);
            t = r;
        }
        recalc(t);
        return t;
    }

    Treap insert(Treap t, int x) {
        Treap[] a = split(t, x);
        a[0] = merge(a[0], new Treap(x));
        return merge(a[0], a[1]);
    }

    int query(Treap t, int x) {
        Treap[] a = split(t, x);
        int res = getSz(a[0]);
        t = merge(a[0], a[1]);
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        Map<Integer, Treap> ins = new HashMap<>(n);
        Map<Integer, Treap> del = new HashMap<>(n);

        for (int i = 0; i < n; i++) {
            int a = nextInt();
            int t = nextInt();
            int x = nextInt();

            if (a == 1) {
                ins.compute(x, (k, v) -> insert(v, t));
            } else if (a == 2) {
                del.compute(x, (k, v) -> insert(v, t));
            } else {
                println(query(ins.get(x), t) - query(del.get(x), t));
            }
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