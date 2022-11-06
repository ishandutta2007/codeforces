import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    Random rand = new Random(31);

    int gcd(int a, int b) {
        while (b > 0) {
            int _ = b;
            b = a % b;
            a = _;
        }
        return a;
    }

    class Item {
        int gcd, x;

        Item(int gcd, int x) {
            this.gcd = gcd;
            this.x = x;
        }
    }

    class SegmentTree {
        Item[] a;
        int n;

        SegmentTree(int[] a) {
            n = 1;
            while (n < a.length) {
                n *= 2;
            }
            this.a = new Item[2 * n - 1];
            for (int i = 0; i < a.length; i++) {
                this.a[n - 1 + i] = new Item(a[i], 1);
            }
            for (int i = n - 2; i >= 0; i--) {
                Item a1 = this.a[i * 2 + 1];
                Item a2 = this.a[i * 2 + 2];
                if (a1 == null || a2 == null) {
                    this.a[i] = a1 == null ? a2 : a1;
                    continue;
                }
                Item a0 = new Item(gcd(a1.gcd, a2.gcd), 0);
                if (a0.gcd == a1.gcd) {
                    a0.x += a1.x;
                }
                if (a0.gcd == a2.gcd) {
                    a0.x += a2.x;
                }
                this.a[i] = a0;
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
            Item a1 = get(i * 2 + 1, l, m, ql, min(qr, m));
            Item a2 = get(i * 2 + 2, m, r, max(m, ql), qr);
            if (a1 == null || a2 == null) {
                return a1 == null ? a2 : a1;
            }
            if (a1.gcd == a2.gcd) {
                return new Item(a1.gcd, a1.x + a2.x);
            }
            if (a1.gcd > a2.gcd) {
                Item _ = a1;
                a1 = a2;
                a2 = _;
            }
            if (a2.gcd % a1.gcd == 0) {
                return a1;
            }
            return new Item(gcd(a1.gcd, a2.gcd), 0);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = nextIntArray(n);
        SegmentTree st = new SegmentTree(a);
        int t = nextInt();
        for (; t-- > 0; ) {
            int l = nextInt() - 1;
            int r = nextInt();
            Item it = st.get(l, r);
            if (it == null) {
                println(r - l);
            } else {
                println(r - l - it.x);
            }
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