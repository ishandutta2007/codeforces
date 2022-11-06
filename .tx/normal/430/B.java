import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;

    int destroy(int[] a, int l, int r, int cc) {
        if (l < 0 || r >= a.length || a[l] != a[r]) {
            return 0;
        }
        int c = a[l];
        int del = 0;
        while (l >= 0 && a[l] == c) {
            l--;
            del++;
        }
        while (r < a.length && a[r] == c) {
            r++;
            del++;
        }
        if (del + cc < 3) {
            return 0;
        }
        return del + destroy(a, l, r, 0);
    }

    void solve() {
        int n = nextInt();
        int k = nextInt();
        int x = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                ans = Math.max(ans, destroy(a, i, i + 1, 1));
            }
        }
        println(ans);
    }

    Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) {
                    return null;
                }
                stok = new StringTokenizer(s);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
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

    public static void main(String[] args) {
        try (Main main = new Main()) {
            main.solve();
        }
    }
}