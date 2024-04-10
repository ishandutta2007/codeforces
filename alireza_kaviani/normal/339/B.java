import java.util.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static long function(long a, long b, long n) {
        return (b >= a) ? b - a : n - a + b;
    }

    public static void main(String[] args) {
        long n = sc.nextInt(), m = sc.nextInt();

        long now = 1;
        long ans = 0;
        for (long i = 0; i < m; i++) {
            long t = sc.nextInt();
            ans += function(now, t, n);
            now = t;
        }

        System.out.println(ans);
    }
}