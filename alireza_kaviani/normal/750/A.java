import java.util.*;
import static java.lang.Math.*;

public class codeforces1 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[])
    {
        problem_2 a=new problem_2();
    }

    static class problem_1
    {
        problem_1() {
            int n = sc.nextInt(), ans = 0;
            double cnt[] = new double[5];

            for (int i = 0; i < n; i++) {
                cnt[sc.nextInt()]++;
            }

            ans += cnt[4];
            ans += cnt[3];

            cnt[1] -= cnt[3];

            if (cnt[1] < 0) cnt[1] = 0;

            ans += Math.ceil(cnt[2] / 2);
            cnt[2] %= 2;

            if (cnt[2] == 1) {
                cnt[1] -= 2;
                if (cnt[1] < 0) cnt[1] = 0;
            }

            ans += Math.ceil(cnt[1] / 4);

            System.out.println(ans);
        }
    }

    static class problem_2
    {
        problem_2() {
            int n=sc.nextInt(), k=240-sc.nextInt();
            int t=5;

            int ans=0;
            while(k-t>=0)
            {
                k-=t;
                t+=5;
                ans++;
            }

            System.out.println(min(ans,n));
        }
    }
}