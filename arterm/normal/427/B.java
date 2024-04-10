import java.util.Scanner;

/**
 * Created by Samsung900 on 02.05.2014.
 */
public class TaskB {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int c = sc.nextInt();
        int a[] = new int[n + 1];
        int sum[] = new int[n + 1];
        int ans = 0;

        for (int i = 1; i <= n; ++i)
            if (sc.nextInt() <= t)
                a[i] = 0;
            else
                a[i] = 1;

        for (int i = 1; i < c; ++i)
            sum[i] = sum[i - 1] + a[i];

        for (int i = c; i <= n; ++i){
            sum[i] = sum[i - 1] + a[i] - a[i - c];
            if (sum[i] == 0)
                ++ans;
        }

        System.out.println(ans);

    }
}