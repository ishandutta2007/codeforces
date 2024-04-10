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
        char[] s = next().toCharArray();
        char[] t = next().toCharArray();
        int[][] ps = new int[26][26];
        for (int[] i : ps) {
            Arrays.fill(i, -1);
        }
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            if (x != y && ps[x][y] == -1) {
                ps[x][y] = i;
            }
        }

        boolean ok = false;
        int ai = -2;
        int aj = -2;

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            if (ps[y][x] != -1) {
                int j = ps[y][x];
                char _ = s[i];
                s[i] = s[j];
                s[j] = _;
                ok = true;
                ai = i;
                aj = j;
                break;
            }
        }

        for (int i = 0; !ok && i < n; i++) {
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            if (x == y) {
                continue;
            }
            for (int c = 0; c < 26; c++) {
                if (ps[c][x] != -1) {
                    int j = ps[c][x];
                    char _ = s[i];
                    s[i] = s[j];
                    s[j] = _;
                    ok = true;
                    ai = i;
                    aj = j;
                    break;
                }
            }
        }

        int h = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                h++;
            }
        }
        println(h);
        printf("%d %d", ai + 1, aj + 1);
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