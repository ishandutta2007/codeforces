import java.util.*;
import java.lang.Math.*;

public class Minimal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (100 * x + y <= 100 * s)
                ans = Math.max(ans, y == 0 ? 0 : 100 - y);
        }
        System.out.println(ans);
        sc.close();
    }
}