import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Item implements Comparable<Item> {
        int l, r;

        public Item(int l, int r) {
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Item o) {
            return Integer.compare(r, o.r);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            int w = nextInt();
            a[i] = new Item(x - w, x + w);
        }
        Arrays.sort(a);
        int ans = 1;
        int last = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].l >= a[last].r) {
                ans++;
                last = i;
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