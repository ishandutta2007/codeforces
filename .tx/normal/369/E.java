import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    class SegmentTree {
        int[] a;
        int n;

        SegmentTree(int count) {
            n = 1;
            while (n < count) {
                n *= 2;
            }
            a = new int[2 * n - 1];
        }

        void add1(int i) {
            i += n - 1;
            a[i]++;
            while (i > 0) {
                i = (i - 1) / 2;
                a[i] = a[i * 2 + 1] + a[i * 2 + 2];
            }
        }

        int get(int l, int r) {
            return get(0, 0, n, l, r);
        }

        int get(int i, int tl, int tr, int l, int r) {
            if (l >= r) {
                return 0;
            }
            if (tl == l && tr == r) {
                return a[i];
            }
            int m = (tl + tr) >> 1;
            return get(i * 2 + 1, tl, m, l, min(m, r)) + get(i * 2 + 2, m, tr, max(m, l), r);
        }
    }

    class Item {
        int l, id;

        Item(int l, int id) {
            this.l = l;
            this.id = id;
        }
    }

    final int MAXC = (int) (1e6) + 31;

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Integer>[] seg = new List[MAXC + 1];
        List<Item>[] q = new List[MAXC + 1];
        for (int i = 0; i <= MAXC; i++) {
            seg[i] = new ArrayList<>();
            q[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            int l = in.nextInt();
            int r = in.nextInt();
            seg[r].add(l);
        }

        for (int i = 0; i < m; i++) {
            int k = in.nextInt();
            int last = 0;
            for (int j = 0; j < k; j++) {
                int x = in.nextInt();
                q[x].add(new Item(last, i));
                last = x;
            }
            q[MAXC].add(new Item(last, i));
        }

        SegmentTree st = new SegmentTree(MAXC + 1);
        int[] ans = new int[m];
        for (int i = 0; i <= MAXC; i++) {
            int s = st.get(0, MAXC + 1);
            for (Item p : q[i]) {
                int sp = st.get(0, p.l + 1);
                ans[p.id] += s - sp;
            }
            for (Integer l : seg[i]) {
                st.add1(l);
            }
        }
        for (int i : ans) {
            out.println(n - i);
        }

    }

    void run() {
        try {
            in = new FastIO();
            solve();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    class FastIO {
        private BufferedReader in;

        private StringTokenizer stok;

        FastIO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        FastIO(String s) throws FileNotFoundException {
            if ("".equals(s)) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(s + ".in"));
                out = new PrintWriter(s + ".out");
            }
        }

        void close() throws IOException {
            in.close();
            out.close();
        }

        String next() {
            while (stok == null || !stok.hasMoreTokens()) {
                try {
                    stok = new StringTokenizer(in.readLine());
                } catch (Exception e) {
                    return null;
                }
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
    }
}