import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Item implements Comparable<Item> {
        int f, t;
        long s;

        public Item(int f, int t, long s) {
            this.f = f;
            this.t = t;
            this.s = s;
        }

        @Override
        public int compareTo(Item o) {
            return Integer.compare(t, o.t);
        }

        @Override
        public String toString() {
            return "Item{" +
                    "f=" + f +
                    ", t=" + t +
                    ", s=" + s +
                    '}';
        }
    }

    class SegmentTree {
        Item[] a;

        SegmentTree(int n) {
            a = new Item[4 * n];
        }

        Item merge(Item il, Item ir) {
            if (il == null || ir == null) {
                return il == null ? ir : il;
            }
            if (il.t >= ir.t) {
                return il;
            }
            return ir;
        }

        Item get(int i, int l, int r, int ql, int qr) {
            if (r <= ql || l >= qr) {
                return null;
            }
            if (ql <= l && r <= qr) {
                return a[i];
            }

            int m = (l + r) >> 1;
            Item il = get(i * 2 + 1, l, m, ql, qr);
            Item ir = get(i * 2 + 2, m, r, ql, qr);
            return merge(il, ir);
        }

        void set(int i, int l, int r, int qi, Item x) {
            if (l + 1 == r) {
                a[i] = x;
                return;
            }
            int m = (l + r) >> 1;
            if (qi < m) {
                set(i * 2 + 1, l, m, qi, x);
            } else {
                set(i * 2 + 2, m, r, qi, x);
            }
            a[i] = merge(a[i * 2 + 1], a[i * 2 + 2]);
        }

    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = nextIntArray(n - 1);
        SegmentTree st = new SegmentTree(n);
        long ans = 0;
        st.set(0, 0, n, n - 1, new Item(n - 1, n - 1, 0));
        for (int i = n - 2; i >= 0; i--) {
            Item x = st.get(0, 0, n, i + 1, a[i]);
            int ct = a[i] - 1;
            long cs = ct - i;
            if (x.t > ct) {
                cs -= ct - x.f;
                cs += x.s + (n - 1 - ct);
            }
            ans += cs;
            st.set(0, 0, n, i, new Item(i, ct, cs));
        }
        println(ans);
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