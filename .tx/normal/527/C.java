import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Dsu {
        int[] a, s, r;

        public Dsu(int n) {
            a = new int[n];
            s = new int[n];
            r = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = i;
                s[i] = 1;
                r[i] = 1;
            }
        }

        int get(int x) {
            return x == a[x] ? x : (a[x] = get(a[x]));
        }

        void union(int x, int y) {
            x = get(x);
            y = get(y);

            if (x == y) {
                return;
            }

            if (r[x] > r[y]) {
                a[y] = x;
                s[x] += s[y];
            } else {
                a[x] = y;
                s[y] += s[x];
                r[y] = max(r[y], r[x] + 1);
            }
        }

        int getS(int x) {
            return s[get(x)];
        }
    }

    void solve() throws IOException {
        int W = nextInt();
        int H = nextInt();
        int n = nextInt();
        List<Integer> hc = new ArrayList<>();
        List<Integer> vc = new ArrayList<>();
        char[] cs = new char[n];
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            char c = cs[i] = next().charAt(0);
            int x = xs[i] = nextInt();
            if (c == 'H') {
                hc.add(x);
            } else {
                vc.add(x);
            }
        }

        Dsu hu = new Dsu(H);
        Dsu vu = new Dsu(W);

        int[] hl = new int[H];
        int[] vl = new int[W];
        Queue<Integer> sorted = new PriorityQueue<>(hc);
        sorted.add(H);
        int maxH = 0;
        int cur = 0;

        while (!sorted.isEmpty()) {
            int x = sorted.poll();
            for (int j = cur; j < x; j++) {
                hl[j] = x - cur;
                hu.union(cur, j);
            }
//            maxH = max(maxH, hl[cur]);
            maxH = max(maxH, hu.getS(cur));
            hl[cur] *= -1;
            cur = x;
        }
        sorted = new PriorityQueue<>(vc);
        sorted.add(W);
        int maxV = 0;
        cur = 0;
        while (!sorted.isEmpty()) {
            int x = sorted.poll();
            for (int j = cur; j < x; j++) {
                vl[j] = x - cur;
                vu.union(j, cur);
            }
//            maxV = max(maxV, vl[cur]);
            maxV = max(maxV, vu.getS(cur));
            vl[cur] *= -1;
            cur = x;
        }

        long[] ans = new long[n];

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = 1L * maxH * maxV;
            char c = cs[i];
            int x = xs[i];
            if (c == 'H') {
//                int t = abs(hl[x - 1]) + abs(hl[x]);
//                maxH = max(maxH, t);
//                int j = x - 1;
//                while (true) {
//                    if (hl[j] < 0) {
//                        hl[j] = -t;
//                        break;
//                    }
//                    hl[j] = t;
//                    j--;
//                }
//                hl[x] = t;
//                j = x + 1;
//                while (j < H && hl[j] > 0) {
//                    hl[j] = t;
//                    j++;
//                }
                hu.union(x - 1, x);
                maxH = max(maxH, hu.getS(x));
            } else {
//                int t = abs(vl[x - 1]) + abs(vl[x]);
//                maxV = max(maxV, t);
//                int j = x - 1;
//                while (true) {
//                    if (vl[j] < 0) {
//                        vl[j] = -t;
//                        break;
//                    }
//                    vl[j] = t;
//                    j--;
//                }
//                vl[x] = t;
//                j = x + 1;
//                while (j < W && vl[j] > 0) {
//                    vl[j] = t;
//                    j++;
//                }
                vu.union(x - 1, x);
                maxV = max(maxV, vu.getS(x));
            }
        }
        for (long i : ans) {
            println(i);
        }
    }

    public static void main(String[] args) throws IOException {
        try (Main main = new Main()) {
            main.solve();
        }
    }

    Main() throws IOException {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
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
}