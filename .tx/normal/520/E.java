import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final long mod = inf + 7;

    long pow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        long t = pow(a, b / 2);
        t = t * t % mod;
        if (b % 2 == 1) {
            t *= a;
        }
        return t % mod;
    }

    long[] fact;
    long[] backFact;
    long[] pow10;

    long c(int n, int k) {
        if (n < k || k < 0) {
            return 0;
        }
        return fact[n] * backFact[k] % mod * backFact[n - k] % mod;
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();

        char[] d = next().toCharArray();

        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        backFact = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            backFact[i] = pow(fact[i], mod - 2);
        }
        pow10 = new long[n + 1];
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = pow10[i - 1] * 10 % mod;
        }
        long[] s = new long[n];
        s[0] = c(n - 2, k - 1);
        for (int i = 1; i < n - 1; i++) {
            s[i] = s[i - 1] + c(n - 2 - i, k - 1) * pow10[i] % mod;
            s[i] %= mod;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (d[i] - '0') * pow10[n - 1 - i] % mod * c(i, k) % mod;
            ans %= mod;
        }
        for (int i = 0; i < n - 1; i++) {
            ans += (d[i] - '0') * s[n - 2 - i] % mod;
            ans %= mod;
        }
        println(ans);

    }

    void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        } finally {
            close();
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String filename) throws IOException {
        super("".equals(filename) ? "output.txt" : filename + ".out");
        in = new BufferedReader(new FileReader("".equals(filename) ? "input.txt" : filename + ".in"));
    }

    public static void main(String[] args) throws IOException {
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

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
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