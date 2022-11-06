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
        double p = nextDouble();
        int t = nextInt();

        double[][] d = new double[t + 1][n + 1];
        d[0][0] = 1;
        for (int i = 1; i <= t; i++) {
            d[i][0] = (1 - p) * d[i - 1][0];
            for (int j = 1; j < n; j++) {
                d[i][j] = p * d[i - 1][j - 1] + (1 - p) * d[i - 1][j];
            }
            d[i][n] = p * d[i - 1][n - 1] + d[i - 1][n];
        }
        double ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += d[t][i] * i;
        }
        printf("%.7f", ans);
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