import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO io;

    // File names!!!

    void solve() throws IOException {
        char[] a = io.nextCharArray();
        int[] count = new int[10];
        for (char c : a) {
            count[c - '0']++;
        }
        int n = a.length;
        int m = io.nextInt();

        int[] pow10 = new int[19];
        long[] fact = new long[19];
        pow10[0] = 1;
        fact[0] = 1;
        for (int i = 1; i < 19; i++) {
            pow10[i] = (pow10[i - 1] * 10) % m;
            fact[i] = fact[i - 1] * i;
        }

        long[][] d = new long[1 << n][m];
        d[0][0] = 1;
        for (int mask = 0; mask < (1 << n); mask++) {
            int p = Integer.bitCount(mask);
            for (int mod = 0; mod < m; mod++) {
                if (d[mask][mod] == 0) {
                    continue;
                }
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        continue;
                    }
                    if (p == 0 && a[i] == '0') {
                        continue;
                    }
                    int nmask = mask | (1 << i);
                    int nmod = ((pow10[n - p - 1] * (a[i] - '0') + mod) % m);
                    d[nmask][nmod] += d[mask][mod];
                }
            }
        }
        long ans = d[(1 << n) - 1][0];
        for (int i : count) {
            ans /= fact[i];
        }
        io.println(ans);
    }

    void run() {
        try {
            io = new FastIO();
            solve();
            io.close();
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

    class FastIO extends PrintWriter {
        private BufferedReader in;
        private StringTokenizer stok;

        FastIO() {
            super(System.out);
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        FastIO(String s) throws FileNotFoundException {
            super("".equals(s) ? "output.txt" : s + ".out");
            in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
        }

        public void close() {
            super.close();
            try {
                in.close();
            } catch (IOException ignored) {
            }
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

        String nextLine() {
            try {
                return in.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        char[] nextCharArray() {
            return next().toCharArray();
        }

    }
}