import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    final int inf = (int) 1e9;

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
        }

        int[] max = new int[n];
        max[n - 1] = p[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max[i] = max(p[i], max[i + 1]);
        }

        int[][] dp = new int[n + 2][n + 2];
        for (int[] i : dp) {
            Arrays.fill(i, inf);
        }
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dp[i][j] == inf) continue;
                if (max[j] != 0) {
                    if (p[i] != 0) {
                        dp[j + 1][j + 2] = min(dp[j + 1][j + 2], dp[i][j] + 1);
                    }
                    if (p[i] != 100) {
                        dp[j][j + 1] = min(dp[j][j + 1], dp[i][j] + 1);
                    }
                }
                if (max[j] != 100) {
                    if (p[i] != 0) {
                        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
                    }
                    if (p[i] != 100) {
                        dp[i][j] = min(dp[i][j], dp[i][j] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                if (dp[i][j] <= k) {
                    ans++;
                }
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