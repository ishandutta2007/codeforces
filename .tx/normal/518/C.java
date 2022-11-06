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
        int k = nextInt();

        int[] a = new int[n];
        int[] pos = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt() - 1;
            pos[a[i]] = i;
        }

        long ans = 0;

        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int px = pos[x];
            ans += px / k + 1;
            if (px > 0) {
                int y = a[px - 1];
                pos[x]--;
                pos[y]++;
                a[px] = y;
                a[px - 1] = x;
            }
        }

        println(ans);
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