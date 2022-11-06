import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class SegmentTree {
        int[] a;
        int[] set;

        SegmentTree(int n) {
            a = new int[4 * n];
            set = new int[4 * n];
            Arrays.fill(set, -1);
            Arrays.fill(a, -1);
        }

        void push(int i, int l, int r) {
            if (set[i] == -1) {
                return;
            }
            a[i] = set[i];
            if (l + 1 != r) {
                set[i * 2 + 1] = set[i];
                set[i * 2 + 2] = set[i];
            }
            set[i] = -1;
        }

        int get(int i, int l, int r, int qi) {
            push(i, l, r);
            if (l + 1 == r) {
                return a[i];
            }
            int m = (l + r) >> 1;
            if (qi < m) {
                return get(i * 2 + 1, l, m, qi);
            }
            return get(i * 2 + 2, m, r, qi);
        }

        void upd(int i, int l, int r, int ql, int qr, int x) {
            push(i, l, r);
            if (r <= ql || l >= qr) {
                return;
            }
            if (ql <= l && r <= qr) {
                set[i] = x;
                push(i, l, r);
                return;
            }

            int m = (l + r) >> 1;
            upd(i * 2 + 1, l, m, ql, qr, x);
            upd(i * 2 + 2, m, r, ql, qr, x);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] a = nextIntArray(n);
        int[] b = nextIntArray(n);
        SegmentTree sx = new SegmentTree(n);
        SegmentTree sy = new SegmentTree(n);

        while (m-- > 0) {
            int t = nextInt();
            if (t == 2) {
                int q = nextInt() - 1;
                int x = sx.get(0, 0, n, q);
                int y = sy.get(0, 0, n, q);
                if (x == -1) {
                    println(b[q]);
                } else {
                    println(a[q - y + x]);
                }
            } else {
                int x = nextInt() - 1;
                int y = nextInt() - 1;
                int k = nextInt();
                sx.upd(0, 0, n, y, y + k, x);
                sy.upd(0, 0, n, y, y + k, y);
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