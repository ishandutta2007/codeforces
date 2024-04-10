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
        int[] a, suf, pref, max;
        int[] len;
        int n;

        void setSize(int size) {
            n = 1;
            while (n < size) {
                n *= 2;
            }
            a = new int[2 * n - 1];
            suf = new int[2 * n - 1];
            pref = new int[2 * n - 1];
            max = new int[2 * n - 1];
            len = new int[2 * n - 1];
            for (int i = len.length - 1; i >= 0; i--) {
                if (i * 2 + 1 >= len.length) {
                    len[i] = 1;
                } else {
                    len[i] = len[i * 2 + 1] + len[i * 2 + 2];
                }
            }
        }

        void clear() {
            Arrays.fill(a, 0);
            Arrays.fill(suf, 0);
            Arrays.fill(pref, 0);
            Arrays.fill(max, 0);
        }

        void set(int i, int x) {
            i += n - 1;
            a[i] = x;
            suf[i] = pref[i] = max[i] = 1;
            while (i > 0) {
                i = (i - 1) / 2;
                pref[i] = pref[i * 2 + 1] == len[i * 2 + 1] ? (pref[i * 2 + 1] + pref[i * 2 + 2]) : (pref[i * 2 + 1]);
                suf[i] = (suf[i * 2 + 2] == len[i * 2 + 2]) ? (suf[i * 2 + 1] + suf[i * 2 + 2]) : (suf[i * 2 + 2]);
                max[i] = maxx(pref[i], suf[i], suf[i * 2 + 1] + pref[i * 2 + 2], max[i * 2 + 1], max[i * 2 + 2]);
            }
        }

        int get(int l, int r) {
            return get(0, 0, n, l, r);
        }

        int get(int i, int l, int r, int ql, int qr) {
            if (ql >= qr) {
                return 0;
            }
            if (l == ql && r == qr) {
                return max[i];
            }
            int m = (l + r) >> 1;
            int m1 = get(i * 2 + 1, l, m, ql, min(qr, m));
            int m2 = get(i * 2 + 2, m, r, max(ql, m), qr);
            int m3 = min(m - ql, suf[i * 2 + 1]);
            int m4 = min(qr - m, pref[i * 2 + 2]);
            return maxx(m1, m2, m3 + m4);
        }
    }

    int n, m;
    int[] ql, qr, qw;
    int[] bl, br, bm;
    int[] h;


    public void solve() throws IOException {
        n = nextInt();
        h = nextIntArray(n);
        Queue<Integer> pq = new PriorityQueue<>();
        for (int i : h) {
            pq.add(i);
        }
        Map<Integer, Integer> mm = new TreeMap<>();
        int[] back = new int[n + 1];
        while (!pq.isEmpty()) {
            int v = pq.poll();
            if (!mm.containsKey(v)) {
                mm.put(v, mm.size() + 1);
                back[mm.size()] = v;
            }
        }
        for (int i = 0; i < n; i++) {
            h[i] = mm.get(h[i]);
        }
        m = nextInt();
        ql = new int[m];
        qr = new int[m];
        qw = new int[m];
        for (int i = 0; i < m; i++) {
            ql[i] = nextInt() - 1;
            qr[i] = nextInt();
            qw[i] = nextInt();
        }
        bl = new int[m];
        br = new int[m];
        bm = new int[m];
        for (int i = 0; i < m; i++) {
            bl[i] = 1;
            br[i] = n + 1;
        }

        SegmentTree st = new SegmentTree();
        st.setSize(n);
        List<Integer>[] hs = createAdjacencyList(n + 1);
        for (int i = 0; i < n; i++) {
            hs[h[i]].add(i);
        }
        List<Integer>[] qh = createAdjacencyList(n + 1);
        while (true) {
            boolean finish = true;
            for (int i = 0; i < m; i++) {
                bm[i] = (bl[i] + br[i]) >> 1;
                if (bl[i] + 1 < br[i]) {
                    finish = false;
                }
            }
            if (finish) {
                break;
            }
            for (int i = 0; i <= n; i++) {
                qh[i].clear();
            }
            for (int i = 0; i < m; i++) {
                qh[bm[i]].add(i);
            }
            st.clear();
            for (int i = n; i >= 0; i--) {
                for (int j : hs[i]) {
                    st.set(j, 1);
                }
                for (int j : qh[i]) {
                    int x = st.get(ql[j], qr[j]);
                    if (x >= qw[j]) {
                        bl[j] = bm[j];
                    } else {
                        br[j] = bm[j];
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            println(back[bl[i]]);
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

    int maxx(int... a) {
        int res = a[0];
        for (int i = 1; i < a.length; i++) {
            res = max(res, a[i]);
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

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}