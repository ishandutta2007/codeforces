import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class SegmentTree1 {
        int[] a;

        SegmentTree1(int n) {
            a = new int[4 * n];
            Arrays.fill(a, -1);
        }

        void set(int i, int l, int r, int qi) {
            if (l + 1 == r) {
                a[i] = 0;
                return;
            }
            int m = (l + r) >> 1;
            if (qi < m) {
                set(i * 2 + 1, l, m, qi);
            } else {
                set(i * 2 + 2, m, r, qi);
            }
            a[i] = (a[i] == -1) ? qi - l : min(a[i], qi - l);
        }

        int getLeft(int i, int l, int r, int ql, int qr) {
            if (r <= ql || l >= qr) {
                return -1;
            }
            if (ql <= l && r <= qr) {
                return a[i];
            }
            int m = (l + r) >> 1;
            int al = getLeft(i, l, m, ql, qr);
            int ar = getLeft(i, m, r, ql, qr);
            if (al != -1) {
                return al;
            }
            if (ar != -1) {
                return ar + m - l;
            }
            return -1;
        }
    }

    final int mod = inf + 7;

    class SegmentTree {
        double[] s;
        boolean wasCalc = false;

        SegmentTree(int n) {
            s = new double[n];
        }

        void set(int i, int l, int r, int qi, int x) {
            s[qi] = x == 0 ? 0 : log(x);
        }

        void calc() {
            wasCalc = true;
            for (int i = 1; i < s.length; i++) {
                s[i] += s[i - 1];
            }
        }

        double getS(int i, int l, int r, int ql, int qr) {
            if (ql >= qr) {
                return 0;
            }
            if (!wasCalc) {
                calc();
            }
            return s[qr - 1] - (ql == 0 ? 0 : s[ql - 1]);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }

        int[][] up = new int[n][n];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '0') {
                    continue;
                }
                if (a[i - 1][j] == '0') {
                    up[i][j] = 0;
                } else {
                    up[i][j] = up[i - 1][j] + 1;
                }
            }
        }

        int[][] down = new int[n][n];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != '0') {
                    if (a[i + 1][j] == '0') {
                        down[i][j] = 0;
                    } else {
                        down[i][j] = down[i + 1][j] + 1;
                    }
                }
            }
        }

        int[][] left = new int[n][n];
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (a[i][j] != '0') {
                    if (a[i][j - 1] == '0') {
                        left[i][j] = 0;
                    } else {
                        left[i][j] = left[i][j - 1] + 1;
                    }
                }
            }
        }

        int[][] right = new int[n][n];
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (a[i][j] != '0' && a[i][j + 1] != '0') {
                    right[i][j] = right[i][j + 1] + 1;
                }
            }
        }

        SegmentTree[] hor = new SegmentTree[n];
        SegmentTree[] ver = new SegmentTree[n];
        for (int i = 0; i < n; i++) {
            hor[i] = new SegmentTree(n);
            ver[i] = new SegmentTree(n);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hor[i].set(0, 0, n, j, a[i][j] - '0');
                ver[j].set(0, 0, n, i, a[i][j] - '0');
            }
        }

        double mxSNorm = 0;
        int nI = 0;
        int nJ = 0;
        int nMx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '0') {
                    continue;
                }
                if (i == 1 && j == 2) {
                    nI++;
                    nI -= 1;
                }
                int mx = up[i][j];
                mx = min(mx, down[i][j]);
                mx = min(mx, left[i][j]);
                mx = min(mx, right[i][j]);
                double curS = log(a[i][j] - '0');
                curS = curS + hor[i].getS(0, 0, n, j - mx, j);
                curS = curS + hor[i].getS(0, 0, n, j + 1, j + mx + 1);
                curS = curS + ver[j].getS(0, 0, n, i - mx, i);
                curS = curS + ver[j].getS(0, 0, n, i + 1, i + mx + 1);
                if (curS > mxSNorm + 1e-9) {
                    mxSNorm = curS;
                    nI = i;
                    nJ = j;
                    nMx = mx;
                }
            }
        }


        int[][] ur = new int[n][n];
        for (int sj = 0; sj + 1 < n; sj++) {
            int i = 1;
            int j = sj;
            while (i < n && j >= 0) {
                if (a[i][j] != '0' && a[i - 1][j + 1] != '0') {
                    ur[i][j] = ur[i - 1][j + 1] + 1;
                }
                i++;
                j--;
            }
        }
        for (int si = 2; si < n; si++) {
            int i = si;
            int j = n - 2;
            while (i < n && j >= 0) {
                if (a[i][j] != '0' && a[i - 1][j + 1] != '0') {
                    ur[i][j] = ur[i - 1][j + 1] + 1;
                }
                i++;
                j--;
            }
        }

        int[][] ul = new int[n][n];
        for (int sj = 1; sj < n; sj++) {
            int i = 1;
            int j = sj;
            while (i < n && j < n) {
                if (a[i][j] != '0' && a[i - 1][j - 1] != '0') {
                    ul[i][j] = ul[i - 1][j - 1] + 1;
                }
                i++;
                j++;
            }
        }

        for (int si = 2; si < n; si++) {
            int i = si;
            int j = 1;
            while (i < n && j < n) {
                if (a[i][j] != '0' && a[i - 1][j - 1] != '0') {
                    ul[i][j] = ul[i - 1][j - 1] + 1;
                }
                i++;
                j++;
            }
        }

        int[][] dr = new int[n][n];
        for (int sj = 0; sj + 1 < n; sj++) {
            int i = n - 2;
            int j = sj;
            while (i >= 0 && j >= 0) {
                if (a[i][j] != '0' && a[i + 1][j + 1] != '0') {
                    dr[i][j] = dr[i + 1][j + 1] + 1;
                }
                i--;
                j--;
            }
        }

        for (int si = n - 3; si >= 0; si--) {
            int i = si;
            int j = n - 2;
            while (i >= 0 && j >= 0) {
                if (a[i][j] != '0' && a[i + 1][j + 1] != '0') {
                    dr[i][j] = dr[i + 1][j + 1] + 1;
                }
                i--;
                j--;
            }
        }

        int[][] dl = new int[n][n];
        for (int sj = 1; sj < n; sj++) {
            int i = n - 2;
            int j = sj;
            while (i >= 0 && j < n) {
                if (a[i][j] != '0' && a[i + 1][j - 1] != '0') {
                    dl[i][j] = dl[i + 1][j - 1] + 1;
                }
                i--;
                j++;
            }
        }

        for (int si = n - 3; si >= 0; si--) {
            int i = si;
            int j = 1;
            while (i >= 0 && j < n) {
                if (a[i][j] != '0' && a[i + 1][j - 1] != '0') {
                    dl[i][j] = dl[i + 1][j - 1] + 1;
                }
                i--;
                j++;
            }
        }

        SegmentTree[] d1 = new SegmentTree[n + n - 1];
        SegmentTree[] d2 = new SegmentTree[n + n - 1];
        for (int i = 0; i < d1.length; i++) {
            d1[i] = new SegmentTree(n);
            d2[i] = new SegmentTree(n);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != '0') {
                    d1[i + j].set(0, 0, n, i, a[i][j] - '0');
                    d2[i - j + n - 1].set(0, 0, n, i, a[i][j] - '0');
                }
            }
        }

        double mxSCross = 0;
        int cI = 0;
        int cJ = 0;
        int cMx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '0') {
                    continue;
                }

                int mx = ur[i][j];
                mx = min(mx, ul[i][j]);
                mx = min(mx, dr[i][j]);
                mx = min(mx, dl[i][j]);

                double curS = log(a[i][j] - '0');
                curS = curS + d1[i + j].getS(0, 0, n, i - mx, i);
                curS = curS + d1[i + j].getS(0, 0, n, i + 1, i + mx + 1);
                curS = curS + d2[i - j + n - 1].getS(0, 0, n, i - mx, i);
                curS = curS + d2[i - j + n - 1].getS(0, 0, n, i + 1, i + mx + 1);

                if (curS > mxSCross + 1e-9) {
                    mxSCross = curS;
                    cI = i;
                    cJ = j;
                    cMx = mx;
                }

            }
        }

        if (mxSCross > mxSNorm + 1e-9) {
            long res = a[cI][cJ] - '0';
            for (int i = 1; i <= cMx; i++) {
                res = res * (a[cI - i][cJ - i] - '0') % mod;
                res = res * (a[cI + i][cJ - i] - '0') % mod;
                res = res * (a[cI + i][cJ + i] - '0') % mod;
                res = res * (a[cI - i][cJ + i] - '0') % mod;
            }
            println(res);
        } else {
            long res = a[nI][nJ] - '0';
            for (int i = 1; i <= nMx; i++) {
                res = res * (a[nI - i][nJ] - '0') % mod;
                res = res * (a[nI + i][nJ] - '0') % mod;
                res = res * (a[nI][nJ - i] - '0') % mod;
                res = res * (a[nI][nJ + i] - '0') % mod;
            }
            println(res);
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