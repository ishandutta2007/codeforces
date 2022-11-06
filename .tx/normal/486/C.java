import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    int to(int a, int b, int n) {
        if (a == b) {
            return 0;
        }
        int m1, m2;
        if (b > a) {
            m1 = b - a;
            m2 = a + n - b;
        } else {
            m1 = a - b;
            m2 = b + n - a;

        }
        return min(m1, m2);
    }

    public void solve() throws IOException {
        int n = nextInt();
        int p = nextInt() - 1;
        char[] s = next().toCharArray();
        int[][] d = new int[n][2];
        int x = -1;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                x = i;
                break;
            }
        }
        if (x == -1) {
            println(0);
            return;
        }
        d[x][0] = to(p, x, n) + to(s[x], s[n - 1 - x], 26);
        d[x][1] = to(p, n - 1 - x, n) + to(s[n - 1 - x], s[x], 26);
        int last = x;
        for (int i = x + 1; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                d[i][0] = min(d[last][0] + to(last, i, n), d[last][1] + to(n - 1 - last, i, n)) + to(s[i], s[n - 1 - i], 26);
                d[i][1] = min(d[last][0] + to(last, n - 1 - i, n), d[last][1] + to(n - 1 - last, n - 1 - i, n)) + to(s[n - 1 - i], s[i], 26);
                last = i;
            }
        }
        int ans1 = min(d[last][0], d[last][1]);
        for (int[] i : d) {
            Arrays.fill(i, 0);
        }
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                x = i;
            }
        }
        d[x][0] = to(p, x, n) + to(s[x], s[n - 1 - x], 26);
        d[x][1] = to(p, n - 1 - x, n) + to(s[n - 1 - x], s[x], 26);
        last = x;
        for (int i = x - 1; i >= 0; i--) {
            if (s[i] != s[n - 1 - i]) {
                d[i][0] = min(d[last][0] + to(last, i, n), d[last][1] + to(n - 1 - last, i, n)) + to(s[i], s[n - 1 - i], 26);
                d[i][1] = min(d[last][0] + to(last, n - 1 - i, n), d[last][1] + to(n - 1 - last, n - 1 - i, n)) + to(s[n - 1 - i], s[i], 26);
                last = i;
            }
        }
        int ans2 = min(d[last][0], d[last][1]);
        println(min(ans1, ans2));
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