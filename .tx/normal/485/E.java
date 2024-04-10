import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    int[] mt;

    void mul(int[] a, int[] b) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            mt[i] = b[a[i]];
        }
        System.arraycopy(mt, 0, a, 0, n);
    }

    int[] pow(int[] a, int pow) {
        if (pow == 1) {
            return Arrays.copyOf(a, a.length);
        }
        int[] t = pow(a, pow / 2);
        mul(t, t);
        if (pow % 2 == 1) {
            mul(t, a);
        }
        return t;
    }

    public void solve() throws IOException {
        char[] s = next().toCharArray();
        int n = s.length;
        int m = nextInt();
        int[] p = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = (i - 1 + n) % n;
        }
        int[] cnt = new int[n];
        int[] pos = new int[n];
        mt = new int[n];
        int[] tp = new int[n];
        int[] shift = new int[n];
        char[] ns = new char[n];
        for (; m-- > 0; ) {
            int k = nextInt();
            int d = nextInt();
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
            Arrays.fill(cnt, 0);
            for (int i = 0; i < k; i++) {
                cnt[i % d]++;
            }
            pos[0] = 0;
            for (int i = 1; i < d; i++) {
                pos[i] = pos[i - 1] + cnt[i - 1];
            }
            for (int i = 0; i < k; i++) {
                p[i] = pos[i % d]++;
            }
            mul(p, c);
            for (int i = 0; i < n; i++) {
                shift[i] = (i - k + 1 + n) % n;
            }
            int[] t = pow(p, n - k + 1);
            mul(t, shift);
            for (int i = 0; i < n; i++) {
                tp[t[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                print(ns[i] = s[tp[i]]);
            }
            char[] _ = s;
            s = ns;
            ns = _;
            println();
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