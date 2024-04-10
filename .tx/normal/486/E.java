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

    class FenvTree {
        int[] a;

        FenvTree(int n) {
            a = new int[n];
        }

        int getMax(int r) {
            int res = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                res = max(res, a[r]);
            }
            return res;
        }

        void update(int i, int x) {
            for (; i < a.length; i |= (i + 1)) {
                a[i] = max(a[i], x);
            }
        }
    }

    class Item {
        int v;
        long w;

        public Item(int v, long w) {
            this.v = v;
            this.w = w;
        }
    }

    class SegmentTree {
        Item[] a;
        int n;

        SegmentTree(int x) {
            n = 1;
            while (n < x) {
                n *= 2;
            }
            a = new Item[2 * n - 1];
        }

        Item merge(Item a, Item b) {
            if (a == null || b == null) {
                return a == null ? b : a;
            }
            if (a.v != b.v) {
                return a.v > b.v ? a : b;
            }
            return new Item(a.v, (a.w + b.w) % mod);
        }

        void update(int i, Item x) {
            i += n - 1;
            a[i] = merge(a[i], x);
            while (i > 0) {
                i = (i - 1) >> 1;
                a[i] = merge(a[i * 2 + 1], a[i * 2 + 2]);
            }
        }

        Item get(int l, int r) {
            return get(0, 0, n, l, r);
        }

        Item get(int i, int l, int r, int ql, int qr) {
            if (ql >= qr) {
                return null;
            }
            if (l == ql && r == qr) {
                return a[i];
            }
            int m = (l + r) >> 1;
            return merge(get(i * 2 + 1, l, m, ql, min(qr, m)), get(i * 2 + 2, m, r, max(ql, m), qr));
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int[] a = nextIntArray(n);
        int m = (int) 1e5;
        SegmentTree st = new SegmentTree(m + 1);
        int[] v1 = new int[n];
        long[] w1 = new long[n];
        for (int i = 0; i < n; i++) {
            Item x = st.get(0, a[i]);
            Item y = x == null ? new Item(1, 1) : new Item(x.v + 1, x.w);
            v1[i] = y.v;
            w1[i] = y.w;
            st.update(a[i], y);
        }
        Arrays.fill(st.a, null);
        int[] v2 = new int[n];
        long[] w2 = new long[n];
        for (int i = n - 1; i >= 0; i--) {
            Item x = st.get(a[i] + 1, m + 1);
            Item y = x == null ? new Item(1, 1) : new Item(x.v + 1, x.w);
            v2[i] = y.v;
            w2[i] = y.w;
            st.update(a[i], y);
        }
        int v = 0;
        for (int i : v1) {
            v = max(v, i);
        }
        long w = 0;
        for (int i = 0; i < n; i++) {
            if (v1[i] == v) {
                w += w1[i];
                w %= mod;
            }
        }
        for (int i = 0; i < n; i++) {
            if (v1[i] + v2[i] <= v) {
                print(1);
            } else if (w1[i] * w2[i] % mod == w) {
                print(3);
            } else {
                print(2);
            }
        }
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