import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author 6aren
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int query = in.nextInt();
            int[] a = new int[300005];
            int[] b = new int[300005];
            long[][] dp = new long[300005][3];
            while (query != 0) {
                int n = in.nextInt();
                for (int i = 1; i <= n; i++) {
                    a[i] = in.nextInt();
                    b[i] = in.nextInt();
                }
                dp[1][0] = 0;
                dp[1][1] = b[1];
                dp[1][2] = b[1] * 2;
                for (int i = 2; i <= n; i++) {
                    for (int j = 0; j < 3; j++) {
                        int u = a[i] + j;
                        long mn = (long) 1e18;
                        for (int k = 0; k < 3; k++)
                            if (a[i - 1] + k != u) {
                                mn = Math.min(mn, dp[i - 1][k] + 1l * j * b[i]);
                            }
                        dp[i][j] = mn;
                    }
                }
                out.println(Math.min(dp[n][0], dp[n][1]));
                query--;
            }
        }

    }
}