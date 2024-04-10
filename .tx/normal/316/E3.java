import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    final int mod = inf;

    int[] fib;
    int[] sfib;

    class SegmentTree {
        int[] s0, s1;
        int[] add;

        SegmentTree(int n, int[] a) {
            s0 = new int[4 * n];
            s1 = new int[4 * n];
            add = new int[4 * n];
            build(0, 0, n, a);
        }

        int s(int i, int x) {
            if (x == 0) {
                return s0[i];
            }
            if (x == 1) {
                return s1[i];
            }
            return (int) ((1L * fib[x - 2] * s0[i] + 1L * fib[x - 1] * s1[i]) % mod);
        }

        void build(int i, int l, int r, int[] a) {
            if (l + 1 == r) {
                s0[i] = s1[i] = a[l];
            } else {
                int m = (l + r) >> 1;
                build(i * 2 + 1, l, m, a);
                build(i * 2 + 2, m, r, a);

                s0[i] = (s0[i * 2 + 1] + s(i * 2 + 2, m - l)) % mod;
                s1[i] = (s1[i * 2 + 1] + s(i * 2 + 2, m - l + 1)) % mod;
            }
        }

        void push(int i, int l, int r) {
            if (add[i] == 0) {
                return;
            }
            int len = r - l;
            s0[i] = (int) ((s0[i] + 1L * add[i] * sfib[len - 1]) % mod);
            s1[i] = (int) (((s1[i] + 1L * add[i] * sfib[len] - 1L * add[i] * fib[0]) % mod));
            if (l + 1 != r) {
                add[i * 2 + 1] = (add[i * 2 + 1] + add[i]) % mod;
                add[i * 2 + 2] = (add[i * 2 + 2] + add[i]) % mod;
            }
            add[i] = 0;
        }

        int get(int i, int l, int r, int ql, int qr, int x) {
            push(i, l, r);
            if (r <= ql || l >= qr) {
                return 0;
            }
            if (ql <= l && r <= qr) {
                return s(i, x);
            }

            int m = (l + r) >> 1;
            int rl = get(i * 2 + 1, l, m, ql, qr, x);
            int rr = get(i * 2 + 2, m, r, ql, qr, x + max(0, m - max(l, ql)));
            return (rl + rr) % mod;
        }

        void add(int i, int l, int r, int ql, int qr, int x) {
            push(i, l, r);
            if (r <= ql || l >= qr) {
                return;
            }
            if (ql <= l && r <= qr) {
                add[i] = x;
                push(i, l, r);
                return;
            }
            int m = (l + r) >> 1;
            add(i * 2 + 1, l, m, ql, qr, x);
            add(i * 2 + 2, m, r, ql, qr, x);
            s0[i] = (s0[i * 2 + 1] + s(i * 2 + 2, m - l)) % mod;
            s1[i] = (s1[i * 2 + 1] + s(i * 2 + 2, m - l + 1)) % mod;
        }

        void set(int i, int l, int r, int qi, int x) {
            push(i, l, r);
            if (l + 1 == r) {
                s0[i] = s1[i] = x;
                return;
            }
            int m = (l + r) >> 1;
            if (qi < m) {
                set(i * 2 + 1, l, m, qi, x);
                push(i * 2 + 2, m, r);
            } else {
                push(i * 2 + 1, l, m);
                set(i * 2 + 2, m, r, qi, x);
            }
            s0[i] = (s0[i * 2 + 1] + s(i * 2 + 2, m - l)) % mod;
            s1[i] = (s1[i * 2 + 1] + s(i * 2 + 2, m - l + 1)) % mod;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        fib = new int[n + 1];
        fib[0] = fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        }

        sfib = new int[n + 1];
        sfib[0] = fib[0];
        for (int i = 1; i <= n; i++) {
            sfib[i] = (sfib[i - 1] + fib[i]) % mod;
        }


        int[] a = nextIntArray(n);
        SegmentTree st = new SegmentTree(n, a);

        while (m-- > 0) {
            int t = nextInt();
            if (t == 1) {
                st.set(0, 0, n, nextInt() - 1, nextInt());
            } else if (t == 2) {
                println(st.get(0, 0, n, nextInt() - 1, nextInt(), 0));
            } else {
                st.add(0, 0, n, nextInt() - 1, nextInt(), nextInt());
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