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

    int n = 2;
    int MOD = (int) 1e9 + 7;

    void solve() throws IOException {
        long A = nextLong(), B = nextLong(), n = nextLong(), x = nextLong();
        long a[][] = new long[2][2];
        a[0][0] = A; a[0][1] = B;
        a[1][0] = 0; a[1][1] = 1;
        a = pow(a, n);
        out.println(((a[0][0] * x) % MOD + a[0][1]) % MOD);
    }

    long[][] mul(long a[][], long b[][]) {
        long c[][] = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c[i][j] += (a[i][k] * b[k][j]) % MOD;
                    c[i][j] %= MOD;
                }
            }
        }
        return c;
    }

    long[][] pow(long a[][], long n) {
        if (n == 1) {
            return a;
        } else if (n % 2 == 0) {
            long t[][] = pow(a, n / 2);
            return mul(t, t);
        } else {
            long t[][] = pow(a, n - 1);
            return mul(a, t);
        }
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