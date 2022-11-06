import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;

    int[] a;
    long[] s;

    long go(int l, int r) {
        long res = s[r];
        if (l > 0) {
            res -= s[l - 1];
        }
        if (l < r) {
            res += go(l, l) + go(l + 1, r);
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        s = new long[n];

        Random rand = new Random(28403353);
        for (int i = 1; i < n; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[x];
            a[x] = a[i];
            a[i] = _;
        }
        Arrays.sort(a);
        s[0] = a[0];
        for (int i = 1; i < n; i++) {
            s[i] = a[i] + s[i - 1];
        }
        println(go(0, n - 1));
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
        } catch (Exception e) {
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
}