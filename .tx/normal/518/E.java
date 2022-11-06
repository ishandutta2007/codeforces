import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    long[] res;
    long[] get(int cnt, long min, long max) {
        if (max - min - 1 < cnt) {
            return null;
        }
        if (min >= 0 || (-min - 1) * 2 + 1 < cnt) {
            for (int i = 0; i < cnt; i++) {
                res[i] = min + i + 1;
            }
        } else if (max <= 0 || (max - 1) * 2 + 1 < cnt) {
            for (int i = 0; i < cnt; i++) {
                res[i] = max - cnt + i;
            }
        } else {
            long x = min(-min, max) - 1;
            x = min(x, cnt / 2);
            for (int i = 0; i < cnt; i++) {
                res[i] = -x;
                x--;
            }
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        long nan = Long.MAX_VALUE;
        long[] a = new long[n];
        res = new long[n];
        for (int i = 0; i < n; i++) {
            String s = next();
            if (s.charAt(0) == '?') {
                a[i] = nan;
            } else {
                a[i] = Integer.parseInt(s);
            }
        }
        for (int i = 0; i < k; i++) {
            long last = -linf;
            int cnt = 0;
            int j = i;
            while (j < n) {
                if (a[j] != nan) {
                    long[] res = get(cnt, last, a[j]);
                    if (res == null) {
                        println("Incorrect sequence");
                        return;
                    }
                    int t = j - k;
                    while (cnt > 0) {
                        a[t] = res[--cnt];
                        t -= k;
                    }
                    last = a[j];
                } else {
                    cnt++;
                }
                j += k;
            }
            long[] res = get(cnt, last, linf);
            if (res == null) {
                println("Incorrect sequence");
                return;
            }
            int t = j - k;
            while (cnt-- > 0) {
                a[t] = res[cnt];
                t -= k;
            }
        }
        for (long i : a) {
            print(i);
            print(" ");
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