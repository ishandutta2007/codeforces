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
        char[] s = next().toCharArray();
        char[] t = next().toCharArray();
        int n = s.length;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - 'a';
        }
        a[n - 1]++;
        for (int i = n - 1; i >= 0; i--) {
            if (i > 0) {
                a[i - 1] += a[i] / 26;
            }
            a[i] %= 26;
        }
        char[] q = new char[n];
        for (int i = 0; i < n; i++) {
            q[i] = (char) (a[i] + 'a');
        }
        String ss = String.valueOf(s);
        String tt = String.valueOf(t);
        String qq = String.valueOf(q);
        if (ss.compareTo(qq) < 0 && qq.compareTo(tt) < 0) {
            println(qq);
        } else {
            println("No such string");
        }
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