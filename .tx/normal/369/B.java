import sun.misc.Unsafe;

import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    void smth(int[] ans, int l, int r) {
        int x = 0;
        for (int i = 0; i < ans.length; i++) {
            if (ans[i] < l) {
                x -= l - ans[i];
                ans[i] = l;
            } else if (ans[i] > r) {
                x += ans[i] - r;
                ans[i] = r;
            } else {
                if (x < 0 && ans[i] > l) {
                    int o = ans[i];
                    ans[i] += max(l - ans[i], x);
                    x += ans[i] - o;
                } else if (x > 0 && ans[i] < r) {
                    int o = ans[i];
                    ans[i] += min(r - ans[i], x);
                    x -= ans[i] - o;
                }
            }
        }
        if (x != 0) {
            ans[ans.length - 1] += x;
        }
    }

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int l = in.nextInt();
        int r = in.nextInt();
        int sall = in.nextInt();
        int sk = in.nextInt();
        int[] ans = new int[n];
        sall -= sk;
        for (int i = 0; i < k - 1; i++) {
            ans[i] = sk / (k - i);
            sk -= sk / (k - i);
        }
        ans[k - 1] = sk;
        n -= k;
        for (int i = 0; i < n - 1; i++) {
            ans[i + k] = sall / (n - i);
            sall -= sall / (n - i);
        }
        if (n != 0) {
            ans[k + n - 1] = sall;
        }


        for (int i : ans) {
            out.print(i + " ");
        }
    }

    void run() {
        try {
            in = new FastIO();
            solve();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    class FastIO {
        private BufferedReader in;

        private StringTokenizer stok;

        FastIO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        FastIO(String s) throws FileNotFoundException {
            if ("".equals(s)) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(s + ".in"));
                out = new PrintWriter(s + ".out");
            }
        }

        void close() throws IOException {
            in.close();
            out.close();
        }

        String next() {
            while (stok == null || !stok.hasMoreTokens()) {
                try {
                    stok = new StringTokenizer(in.readLine());
                } catch (Exception e) {
                    return null;
                }
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
    }
}