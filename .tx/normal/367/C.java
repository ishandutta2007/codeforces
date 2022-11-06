import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    long countEdges(long n) {
        long res = n * (n - 1) / 2;
        if (n % 2 == 0) {
            res += n / 2 - 1;
        }
        return res;
    }

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            in.nextInt();
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int max = 0;
        for (int i = 1; i <= m; i++) {
            if (countEdges(i) < n) {
                max = i;
            }
        }
        long ans = 0;
        for (int i = 0; i < max; i++) {
            ans += a[m - 1 - i];
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