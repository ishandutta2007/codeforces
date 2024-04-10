import java.io.*;
import java.util.*;

public class Main {
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
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

    double p[][];
    double dp[][];
    int n;

    void rec(int mask, int i) {
        if (dp[mask][i] != -1) {
            return;
        }
        if (mask == (1 << n) - 1) {
            dp[mask][i] = (i == 0 ? 1 : 0);
            return;
        }
        dp[mask][i] = 0;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                rec(mask | (1 << j), i);
                rec(mask | (1 << j), j);
                dp[mask][i] = Math.max(dp[mask][i], dp[mask | (1 << j)][i] * p[i][j] + dp[mask | (1 << j)][j] * p[j][i]);
            }
        }
    }

    void solve() throws IOException {
        n = nextInt();
        if (n == 1) {
            out.println(1);
            return;
        }
        p = new double[n][n];
        dp = new double[(1 << n)][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = nextDouble();
            }
            for (int j = 0; j < (1 << n); j++) {
                dp[j][i] = -1;
            }
        }
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int mask = (1 << i) + (1 << j);
                rec(mask, i);
                rec(mask, j);
                ans = Math.max(ans, dp[mask][i] * p[i][j] + dp[mask][j] * p[j][i]);
            }
        }
        out.println(ans);
    }


    void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}