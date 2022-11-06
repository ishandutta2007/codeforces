import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;
    final int mod = (int) 1e9 + 7;

    int getSum(int[] s, int l, int r) {
        if (l > r) {
            return 0;
        }
        int res = s[r];
        if (l > 0) {
            res = (res - s[l - 1] + mod) % mod;
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int a = nextInt() - 1;
        int b = nextInt() - 1;
        int k = nextInt();
        int[][] d = new int[k + 1][n];

        d[0][a] = 1;
        int[][] ps = new int[k + 1][n];
        for (int i = a; i < n; i++) {
            ps[0][i] = 1;
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (j != b) {
                    if (j < b) {
                        int s1 = getSum(ps[i - 1], j + 1, (b + j - 1) / 2);
                        int s2 = getSum(ps[i - 1], 0, j - 1);
                        d[i][j] = (s1 + s2) % mod;
                    } else {
                        int s1 = getSum(ps[i - 1], (b + j + 2) / 2, j - 1);
                        int s2 = getSum(ps[i - 1], j + 1, n - 1);
                        d[i][j] = (s1 + s2) % mod;
                    }
                }
            }
            ps[i][0] = d[i][0];
            for (int j = 1; j < n; j++) {
                ps[i][j] = (ps[i][j - 1] + d[i][j]) % mod;
            }
        }
        println(ps[k][n - 1]);
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

    <T> List<T>[] adjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}