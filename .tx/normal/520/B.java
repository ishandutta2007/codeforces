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
        int[] a = new int[31000];
        Arrays.fill(a, inf);
        a[n] = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(n);
        while (!q.isEmpty()) {
            int x = q.poll();
            if (x * 2 < a.length && a[x * 2] > a[x] + 1) {
                q.add(x * 2);
                a[x * 2] = a[x] + 1;
            }
            if (x - 1 >= 0 && a[x - 1] > a[x] + 1) {
                q.add(x - 1);
                a[x - 1] = a[x] + 1;
            }
        }
        println(a[m]);
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