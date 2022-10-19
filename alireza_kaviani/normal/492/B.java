import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int n = sc.nextInt();
        double m = sc.nextInt();
        double a[] = new double[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);

        double ans = max(a[0] - 0, m - a[n - 1]);
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, (a[i + 1] - a[i]) / 2);
        }

        System.out.printf("%.10f",ans);
    }

}