import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    int n, m;
    char[][] a;

    long getAns1() {
        long res = 0;
        for (int i = 1; i < n - 1; i++) {
            boolean ok = true;
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res++;
            }
        }

        for (int j = 1; j < m - 1; j++) {
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i][j] == '#') {
                    ok = false;
                }
            }
            if (ok) {
                res++;
            }
        }

        return res;
    }

    boolean[][] topFree;
    boolean[][] botFree;
    boolean[][] leftFree;
    boolean[][] rightFree;

    void calcFree() {
        topFree = new boolean[n][m];
        botFree = new boolean[n][m];
        leftFree = new boolean[n][m];
        rightFree = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m && a[i][j] != '#'; j++) {
                leftFree[i][j] = true;
            }
            for (int j = m - 1; j >= 0 && a[i][j] != '#'; j--) {
                rightFree[i][j] = true;
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n && a[i][j] != '#'; i++) {
                topFree[i][j] = true;
            }
            for (int i = n - 1; i >= 0 && a[i][j] != '#'; i--) {
                botFree[i][j] = true;
            }
        }
    }

    long getAns2() {
        calcFree();
        long res = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (leftFree[i][j] && topFree[i][j]) {
                    res++;
                }
                if (leftFree[i][j] && botFree[i][j]) {
                    res++;
                }
                if (rightFree[i][j] && topFree[i][j]) {
                    res++;
                }
                if (rightFree[i][j] && botFree[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }

    int[][] left;
    int[][] right;
    int[][] up;
    int[][] down;

    void calcAll() {
        calcFree();
        left = new int[n][m];
        right = new int[n][m];
        for (int i = 0; i < n; i++) {
            left[i][0] = a[i][0] == '#' ? 0 : -1;
            for (int j = 1; j < m; j++) {
                left[i][j] = a[i][j] == '#' ? j : left[i][j - 1];
            }
            right[i][m - 1] = a[i][m - 1] == '#' ? m - 1 : m;
            for (int j = m - 2; j >= 0; j--) {
                right[i][j] = a[i][j] == '#' ? j : right[i][j + 1];
            }
        }
        up = new int[n][m];
        up[0][0] = a[0][0] == '#' ? 0 : 1;
        for (int j = 1; j < m; j++) {
            up[0][j] = up[0][j - 1];
            if (a[0][j] != '#') {
                up[0][j]++;
            }
        }
        for (int i = 1; i < n; i++) {
            up[i][0] = a[i][0] == '#' ? 0 : up[i - 1][0];
            for (int j = 1; j < m; j++) {
                up[i][j] = up[i][j - 1];
                if (topFree[i][j]) {
                    up[i][j]++;
                }
            }
        }
        down = new int[n][m];
        down[n - 1][0] = a[n - 1][0] == '#' ? 0 : 1;
        for (int j = 1; j < m; j++) {
            down[n - 1][j] = down[n - 1][j - 1];
            if (a[n - 1][j] != '#') {
                down[n - 1][j]++;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            down[i][0] = a[i][0] == '#' ? 0 : down[i + 1][0];
            for (int j = 1; j < m; j++) {
                down[i][j] = down[i][j - 1];
                if (botFree[i][j]) {
                    down[i][j]++;
                }
            }
        }
    }

    long getAns3() {
        long res = 0;
        for (int t = 0; t < 4; t++) {
            calcAll();
            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    if (!topFree[i][j]) {
                        continue;
                    }
                    int l = max(1, left[i][j] + 1);
                    int r = min(m - 2, right[i][j] - 1);
                    int tt = up[i][r];
                    if (l > 0) {
                        tt -= up[i][l - 1];
                    }
                    res += tt - 1;
                    if (j + 1 <= r && topFree[i][j + 1]) {
                        res--;
                    }
                    if (j - 1 >= l && topFree[i][j - 1]) {
                        res--;
                    }
                    int dd = down[i][r];
                    if (l > 0) {
                        dd -= down[i][l - 1];
                    }
                    res += dd;
                    if (botFree[i][j]) {
                        res--;
                    }
                }
            }
            rotateA();
        }
        if (res % 2 != 0) {
            throw new AssertionError("ans3 is odd: " + res);
        }
        return res / 2;
    }

    void rotateA() {
        char[][] b = new char[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][n - i - 1] = a[i][j];
            }
        }
        int _ = n;
        n = m;
        m = _;
        a = b;
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        long ans1 = getAns1();
        System.err.println("ans1 = " + ans1);
        long ans2 = getAns2();
        System.err.println("ans2 = " + ans2);
        long ans3 = getAns3();
        System.err.println("ans3 = " + ans3);
        println(ans1 + ans2 + ans3);
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