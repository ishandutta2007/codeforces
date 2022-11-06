import com.sun.org.apache.xpath.internal.operations.Bool;

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

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
            if (x != o.x) {
                return x - o.x;
            }
            if (open != o.open) {
                return Boolean.compare(o.open, open);
            }
            return id - o.id;
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int[] px = new int[n];
        int[] py = new int[n];
        Point[] p = new Point[2 * n];
        for (int i = 0; i < n; i++) {
            px[i] = nextInt();
            py[i] = nextInt();
            p[2 * i] = new Point(px[i], i, true);
            p[2 * i + 1] = new Point(py[i], i, false);
        }
        int m = nextInt();
        int[] ax = new int[m];
        int[] ay = new int[m];
        int[] ak = new int[m];
        Point[] a = new Point[2 * m];
        for (int i = 0; i < m; i++) {
            ax[i] = nextInt();
            ay[i] = nextInt();
            ak[i] = nextInt();
            a[2 * i] = new Point(ax[i], i, true);
            a[2 * i + 1] = new Point(ay[i], i, false);
        }
        Arrays.sort(p);
        Arrays.sort(a);
        int ip = 0, ia = 0;
        TreeSet<Point> as = new TreeSet<>();
        int[] ans = new int[n];
        while (ip < p.length) {
            Point ca = ia < a.length ? a[ia] : null;
            Point cp = p[ip];
            if (ca != null && (ca.x < cp.x || (ca.x == cp.x && ca.open))) {
                if (ca.open) {
                    as.add(new Point(ay[ca.id], ca.id, false));
                }
                ia++;
            } else {
                if (cp.open) {
                    Point end = new Point(py[cp.id], -1, false);
                    Point t = as.ceiling(end);
                    if (t == null) {
                        println("NO");
                        return;
                    }
                    ans[cp.id] = t.id;
                    ak[t.id]--;
                    if (ak[t.id] == 0) {
                        as.remove(t);
                    }
                }
                ip++;
            }
        }
        println("YES");
        for (int an : ans) {
            print(an + 1);
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