import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;
    final int mod = inf + 7;

    class Fenv {
        int[] a;

        Fenv(int n) {
            a = new int[n];
        }

        void add(int i, int x) {
            for (; i < a.length; i |= (i + 1)) {
                a[i] += x;
                a[i] %= mod;
            }
        }

        int get(int r) {
            if (r < 0) {
                return 0;
            }
            int res = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                res += a[r];
                res %= mod;
            }
            return res;
        }
    }

    public void solve() throws IOException {
        String s = next();
        String t = next();
        String st = t + "#" + s;
        int[] z = new int[st.length()];
        int l = -1, r = -1;
        for (int i = 1; i < z.length; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < st.length() && st.charAt(i + z[i]) == st.charAt(z[i])) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                r = i + z[i] - 1;
                l = i;
            }
        }
        boolean[] cool = new boolean[s.length()];
        for (int i = t.length(); i < z.length; i++) {
            if (z[i] == t.length()) {
                cool[i - 2] = true;
            }
        }
        Fenv f = new Fenv(s.length());
        int[] d = new int[s.length()];
        int[] d2 = new int[s.length()];
        if (cool[0]) {
            d2[0] = 1;
        } else {
            d2[0] = 0;
        }
        d[0] = d2[0];
        f.add(0, d[0]);
        for (int i = 1; i < s.length(); i++) {
            d2[i] = d2[i - 1];
            if (cool[i]) {
                d2[i] = i - t.length() + 2;
                if (i - t.length() >= 0) {
                    d2[i] += f.get(i - t.length());
                }
                d2[i] %= mod;
            }
            d[i] = d[i - 1] + d2[i];
            d[i] %= mod;
            f.add(i, d[i]);
        }
        println(d[s.length() - 1]);
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