import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    Random rand = new Random(31);

    class Treap {
        long h;
        int max, y, v;
        Treap l, r;

        Treap(long h, int v) {
            this.h = h;
            this.v = v;
            this.max = v;
            y = rand.nextInt();
            l = r = null;
        }
    }

    int getMax(Treap t) {
        return t == null ? 0 : t.max;
    }

    void recalc(Treap... ts) {
        for (Treap t : ts) {
            if (t != null) {
                t.max = max(t.v, max(getMax(t.l), getMax(t.r)));
            }
        }
    }

    Treap[] split(Treap t, long x) {
        if (t == null) {
            return new Treap[] {null, null};
        }
        Treap[] res;
        if (x <= t.h) {
            res = split(t.l, x);
            t.l = res[1];
            res[1] = t;
        } else {
            res = split(t.r, x);
            t.r = res[0];
            res[0] = t;
        }
        recalc(res);
        return res;
    }

    Treap merge(Treap l, Treap r) {
        if (l == null || r == null) {
            return l == null ? r : l;
        }
        Treap res;
        if (l.y <= r.y) {
            l.r = merge(l.r, r);
            res = l;
        } else {
            r.l = merge(l, r.l);
            res = r;
        }
        recalc(res);
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int d = nextInt();
        Treap t = null;
        int[] ms = new int[n];
        long[] hs = new long[n];
        for (int i = 0; i < n; i++) {
            long h = hs[i] = nextLong();
            int max = 0;
            Treap[] a = split(t, h - d + 1);
            Treap[] b = split(a[1], h + d);
            max = max(max, max(getMax(a[0]), getMax(b[1])));
            a[1] = merge(b[0], b[1]);
            t = merge(a[0], a[1]);
            a = split(t, h);
            a[0] = merge(a[0], new Treap(h, ms[i] = max + 1));
            t = merge(a[0], a[1]);
        }
        int max = getMax(t);
        println(max);
        long last = -1;
        List<Integer> ans = new ArrayList<>();
        for (int i = n - 1; i >= 0; i--) {
            if (ms[i] == max && (last == -1 || abs(hs[i] - last) >= d)) {
                ans.add(i);
                max--;
                last = hs[i];
            }
        }
        Collections.reverse(ans);
        for (int i : ans) {
            print(i + 1);
            print(" ");
        }
    }

    void run() throws IOException {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws FileNotFoundException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(br.readLine());
            }
        } catch (IOException e) {
            return null;
        }
        return stok.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
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

    <T> List<T>[] genAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}