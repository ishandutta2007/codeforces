import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class SegmentTree {
        int[] a;
        int n;

        SegmentTree(int x) {
            n = 1;
            while (n < x) {
                n *= 2;
            }
            a = new int[2 * n - 1];
            Arrays.fill(a, -1);
        }

        void set(int i, int x) {
            i += n - 1;
            a[i] = x;
            while (i > 0) {
                i = (i - 1) / 2;
                a[i] = a[i * 2 + 1] & a[i * 2 + 2];
            }
        }

        int get(int l, int r) {
            return get(0, 0, n, l, r);
        }

        int get(int i, int l, int r, int ql, int qr) {
            if (ql >= qr) {
                return -1;
            }
            if (l == ql && r == qr) {
                return a[i];
            }
            int m = (l + r) >> 1;
            return get(i * 2 + 1, l, m, ql, min(qr, m)) & get(i * 2 + 2, m, r, max(ql, m), qr);
        }
    }

    class Point implements Comparable<Point> {
        int x, id;
        boolean open;

        public Point(int x, int id, boolean open) {
            this.x = x;
            this.id = id;
            this.open = open;
        }

        @Override
        public int compareTo(Point o) {
            return x == o.x ? Boolean.compare(o.open, open) : x - o.x;
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        SegmentTree st = new SegmentTree(max(n, m));
        int[] l = new int[m];
        int[] r = new int[m];
        int[] x = new int[m];
        Point[] points = new Point[2 * m];
        for (int i = 0; i < m; i++) {
            points[2 * i] = new Point(l[i] = nextInt() - 1, i, true);
            points[2 * i + 1] = new Point(r[i] = nextInt() - 1, i, false);
            x[i] = nextInt();
        }
        Arrays.sort(points);
        int last = 0;
        int[] ans = new int[n];
        for (Point p : points) {
            int pr = st.get(0, m);
            while (last < p.x + (p.open ? 0 : 1)) {
                ans[last++] = ~pr;
            }
            if (p.open) {
                st.set(p.id, ~x[p.id]);
            } else {
                st.set(p.id, -1);
            }
        }
//        int pr = st.get(0, n);
//        while (last < n) {
//            ans[last++] = pr;
//        }
        for (int i = 0; i < n; i++) {
            st.set(i, ans[i]);
        }
        for (int i = 0; i < m; i++) {
            int t = st.get(l[i], r[i] + 1);
            if (t != x[i]) {
                println("NO");
                return;
            }
        }
        println("YES");
        for (int i = 0; i < n; i++) {
            print(ans[i]);
            print(" ");
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