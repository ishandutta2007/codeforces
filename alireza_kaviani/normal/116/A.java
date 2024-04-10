import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt(), ans = 0, maxn = 0;

        for (int i = 0; i < n; i++) {
            ans -= sc.nextInt();
            ans += sc.nextInt();

            maxn = Math.max(maxn, ans);
        }

        System.out.println(maxn);
    }

}