import java.util.Scanner;

public class Main {
    private static final int P = 1000000007;
    private static long pow(long x, int y) {
        long ret = 1;
        while (y > 0) {
            if (y %2 == 1) {
                ret = ret * x % P;
            }
            x = x * x % P;
            y /= 2;
        }
        return ret;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int[] a = new int[n + 1];
        long[] rev = new long[n + 1];
        long[] res = new long[2 * n + 1];
        long[][] down = new long[n + 1][n + 1];
        long[][] up = new long[2][2 * n + 1];
        for (int i = 1; i < n; ++i) {
            a[i] = cin.nextInt();
            rev[i] = pow(a[i], P - 2);
        }
        for (int i = n; i > 0; --i) {
            down[i][0] = 1;
            for (int j = 1; j < n; ++j) {
                if (i + j > n) {
                    break;
                }
                down[i][j] = down[i + 1][j - 1] * a[i] % P;
            }
        }

        long number = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                res[j] = (res[j] + number * down[i][j] % P) % P;
            }
            number = (number * a[i]) % P;
        }
        int pre = 0;
        number = a[1];
        for (int i = 2; i <= n; ++i) {
            int now = 1 - pre;
            for (int j = 0; j <= 2 * n - 2; ++j) {
                up[now][j] = 0;
            }
            up[now][1] = 1;
            for (int j = 2; j <= 2 * n - 2; ++j) {
                if (j - 1 <= n) {
                    up[now][j] = (up[pre][j - 1] + down[i - 1][j - 1] * rev[i - 1] % P * (a[i - 1] - 1) % P) % P;
                } else {
                    up[now][j] = up[pre][j - 1];
                }
            }
            for (int j = 1; j <= 2 * n - 2; ++j) {
                res[j] = (res[j] + number * up[now][j]  % P) % P;
            }
            number = (number * a[i]) % P;
            pre = now;
        }
        for (int i = 1; i <= 2 * n - 2; ++i) {
            System.out.print(res[i] * pow(2, P - 2) % P + " ");
        }
    }
}