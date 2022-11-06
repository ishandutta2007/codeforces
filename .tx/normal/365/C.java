import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    // File names!!!

    void solve() throws IOException {
        int v = in.nextInt();
        String s = in.next();
        int n = s.length();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.charAt(i) - '0';
        }
        long[] countSum = new long[n * 9 + 1];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                countSum[sum]++;
            }
        }
        if (v == 0) {
            long ans = countSum[0] * countSum[0];
            for (int i = 1; i <= n * 9; i++) {
                ans += countSum[0] * countSum[i] * 2;
            }
            out.println(ans);
            return;
        }
        long ans = 0;
        for (int i = 1; i <= n * 9; i++) {
            if (v % i == 0 && v / i < countSum.length) {
                ans += countSum[i] * countSum[v / i];
            }
        }
        out.println(ans);
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