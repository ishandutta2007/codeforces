import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    int[][] sum;

    int getSum(int c, int l, int r) {
        int res = sum[c][r];
        if (l != 0) {
            res -= sum[c][l - 1];
        }
        return res;
    }

    void add(Map<Integer, Integer> m, int key, int add) {
        Integer t = m.get(key);
        if (t == null) {
            t = 0;
        }
        t += add;
        if (t == 0) {
            m.remove(key);
        } else {
            m.put(key, t);
        }
    }

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
        }

        List<Integer> ans = new ArrayList<>();
        Map<Integer, Integer> tm = new TreeMap<>();
        for (int q = 0; q + (m - 1L) * p < n && q < p; q++) {
            tm.clear();
            for (int i : b) {
                add(tm, i, 1);
            }
            for (int i = 0; i < m; i++) {
                add(tm, a[q + i * p], -1);
            }
            if (tm.size() == 0) {
                ans.add(q);
            }
            for (int i = q + p; i + (m - 1L) * p < n; i += p) {
                add(tm, a[i - p], 1);
                add(tm, a[i + (m - 1) * p], -1);
                if (tm.size() == 0) {
                    ans.add(i);
                }
            }
        }
        Collections.sort(ans);
        out.println(ans.size());
        for (int i : ans) {
            out.print((i + 1) + " ");
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