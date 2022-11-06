import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Treap {
        int sl, sr, y;
        Treap l, r;

        public Treap(int sl, int sr) {
            this.sl = sl;
            this.sr = sr;
            y = rand.nextInt();
            l = r = null;
        }
    }

    Treap[] split(Treap t, int x) {
        if (t == null) {
            return new Treap[]{null, null};
        }
        Treap[] res;
        if (x < t.sl) {
            res = split(t.l, x);
            t.l = res[1];
            res[1] = t;
        } else {
            res = split(t.r, x);
            t.r = res[0];
            res[0] = t;
        }
        return res;
    }

    Treap merge(Treap l, Treap r) {
        if (l == null || r == null) {
            return l == null ? r : l;
        }
        if (l.y < r.y) {
            l.r = merge(l.r, r);
            return r;
        } else {
            r.l = merge(l, r.l);
            return r;
        }
    }

    Treap rightMost(Treap t) {
        if (t == null) {
            return null;
        }
        return t.r == null ? t : rightMost(t.r);
    }

    Treap leftMost(Treap t) {
        if (t == null) {
            return null;
        }
        return t.l == null ? t : leftMost(t.l);
    }

    boolean inOne(Treap t, int x, int y, Dsu dsu) {
        Treap[] a = split(t, x);
        boolean res = false;
        if (a[0] != null) {
            Treap rm = rightMost(a[0]);
            res = y <= rm.sr;
        }
        merge(a[0], a[1]);
        return res;
    }

    Treap remove(Treap t, Treap rm) {
        if (rm == null) {
            return t;
        }
        Treap[] a = split(t, rm.sl);
        Treap[] b = split(a[0], rm.sl - 1);
        return merge(b[0], a[1]);
    }

    Treap add(Treap t, int sl, int sr, Dsu dsu) {
        if (sl == sr) {
            return t;
        }
        int osr = sr;
        Treap[] a = split(t, sl);
        Treap[] b = split(a[1], sr);
        Treap lf = rightMost(a[0]);
        Treap rf = rightMost(b[0]);
        Treap llf = leftMost(b[0]);
        int runF = sl;
        int runT = sr;
        if (lf != null) {
            if (lf.sr >= sl) {
                sl = min(sl, lf.sl);
                sr = max(sr, lf.sr);
                runF = max(runF, lf.sr);
            }
        }
        if (rf != null) {
            sr = max(sr, rf.sr);
            runT = min(runT, llf.sl);
        }
        for (int i = runF; i < runT; i++) {
            dsu.union(i, i + 1);
        }
        if (rf != null) {
            int rdT = runForestRun(b[0], dsu, llf.sr);
            for (int i = rdT; i < osr; i++) {
                dsu.union(i, i + 1);
            }
        }
        a[0] = remove(a[0], lf);
//        b[0] = remove(b[0], rf);
        b[0] = merge(a[0], new Treap(sl, sr));
        return merge(b[0], b[1]);
    }

    int runForestRun(Treap t, Dsu dsu, int from) {
        if (t == null) {
            return -1;
        }
        if (t.l == null) {
            for (int i = from; i < t.sl; i++) {
                dsu.union(i, i + 1);
            }
            if (t.r == null) {
                return t.sr;
            }
            return runForestRun(t.r, dsu, t.sr);
        }
        from = runForestRun(t.l, dsu, from);
        for (int i = from; i < t.sl; i++) {
            dsu.union(i, i + 1);
        }
        if (t.r == null) {
            return t.sr;
        }
        return runForestRun(t.r, dsu, t.sr);
    }

    class SegmentTree {
        int[] a;
        int[] set;

        SegmentTree(int n) {
            a = new int[4 * n];
            set = new int[4 * n];
        }

        void push(int i, int l, int r) {
            if (set[i] == -1) {
                return;
            }
            a[i] = set[i];
            if (l + 1 < r) {
                set[i * 2 + 1] = set[i];
                set[i * 2 + 2] = set[i];
            }
            set[i] = -1;
        }

        void set(int i, int l, int r, int ql, int qr, int x) {
            push(i, l, r);
            if (ql >= qr) {
                return;
            }
            if (l == ql && r == qr) {
                set[i] = x;
                push(i, l, r);
                return;
            }
            int m = (l + r) >> 1;
            set(i * 2 + 1, l, m, ql, min(m, qr), x);
            set(i * 2 + 2, m, r, max(m, ql), qr, x);
        }

        int get(int i, int l, int r, int pos) {
            push(i, l, r);
            if (l == r + 1 && l == pos) {
                return a[i];
            }
            int m = (l + r) >> 1;
            if (pos < m) {
                return get(i * 2 + 1, l, m, pos);
            }
            return get(i * 2 + 2, m, r, pos);
        }
    }

    class Dsu {
        int[] a;
        int[] r;

        Dsu(int n) {
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = i;
            }
            r = new int[n];
        }

        int get(int x) {
            return a[x] == x ? x : (a[x] = get(a[x]));
        }

        void union(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) {
                return;
            }
            if (r[x] > r[y]) {
                a[y] = x;
            } else if (r[x] < r[y]) {
                a[x] = y;
            } else {
                a[x] = y;
                r[y]++;
            }
        }
    }

    class Stupid {
        Dsu dsu;

        Stupid(int n) {
            dsu = new Dsu(n);
        }

        boolean inOne(int x, int y) {
            return dsu.get(x) == dsu.get(y);
        }

        void unionTwo(int x, int y) {
            dsu.union(x, y);
        }

        void unionSegment(int x, int y) {
            for (int i = x; i < y; i++) {
                dsu.union(i, i + 1);
            }
        }
    }

    void solve() throws IOException {
//        int n = 10000;
//        int q = 10000;
//        rand = new Random(System.currentTimeMillis());
        int n = nextInt();
        int q = nextInt();
        Dsu dsu = new Dsu(n);
        Treap t = null;
//        Stupid stupid = new Stupid(n);
//        PrintWriter test = new PrintWriter("input.txt");
//        test.println(n + " " + q);
        for (int i = 0; i < q; i++) {
//            int type = rand.nextInt(3) + 1;
//            int x = rand.nextInt(n);
//            int y = rand.nextInt(n);
//            if (x > y) {
//                int _ = x;
//                x = y;
//                y = _;
//            }
//            test.println(type + " " + (x + 1) + " " + (y + 1));
            int type = nextInt();
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            switch (type) {
                case 1:
                    dsu.union(x, y);
//                    stupid.unionTwo(x, y);
                    break;
                case 2:
                    t = add(t, x, y, dsu);
//                    stupid.unionSegment(x, y);
                    break;
                case 3:
//                    boolean res = dsu.get(x) == dsu.get(y);
//                    if (res != stupid.inOne(x, y)) {
//                        test.close();
//                        throw new AssertionError(i);
//                    }
                    if (dsu.get(x) == dsu.get(y)) {
                        println("YES");
                    } else {
                        println("NO");
                    }
                    break;
            }
        }
//        test.close();
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