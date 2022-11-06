import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        boolean[] b = new boolean[n];
        int bc = nextInt();
        for (int i = 0; i < bc; i++) {
            b[nextInt()] = true;
        }
        boolean[] g = new boolean[m];
        int gc = nextInt();
        for (int i = 0; i < gc; i++) {
            g[nextInt()] = true;
        }
        for (int tt = 0; tt < n + m; tt++) {
            for (int i = 0; i < n * m; i++) {
                b[i % n] |= g[i % m];
                g[i % m] |= b[i % n];
            }
        }
        boolean hasUnhappy = false;
        for (boolean i : g) {
            hasUnhappy |= !i;
        }
        for (boolean i : b) {
            hasUnhappy |= !i;
        }
        println(hasUnhappy ? "No" : "Yes");
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