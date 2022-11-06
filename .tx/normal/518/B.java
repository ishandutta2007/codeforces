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

        int ns = s.length;
        int nt = t.length;

        int[] cs = new int[256];
        int[] ct = new int[256];

        for (int i = 0; i < ns; i++) {
            cs[s[i]]++;
        }

        for (int i = 0; i < nt; i++) {
            ct[t[i]]++;
        }

        for (int ttt = 0; ttt < 2; ttt++) {

            int ans = 0;
            for (int i = 0; i < 256; i++) {
                int x = min(cs[i], ct[i]);
                cs[i] -= x;
                ct[i] -= x;
                ans += x;
            }

            print(ans);
            print(" ");
            for (int i = 'A'; i <= 'Z'; i++) {
                cs[i - 'A' + 'a'] += cs[i];
                ct[i - 'A' + 'a'] += ct[i];
                cs[i] = 0;
                ct[i] = 0;
            }
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