import java.util.*;
import static java.lang.Math.*;

public class codeforces1 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[])
    {
        problem_4 a=new problem_4();
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

    static class problem_3
    {
        public int function(int n)
        {
            return n*(n+1)/2;
        }

        problem_3()
        {
            int n=sc.nextInt();
            int ans=0 , t=0;

            for(int i=1;i<=n;i++)
            {
                if(t+function(i)>n)break;
                t+=function(i);
                ans++;
            }

            System.out.println(ans);
        }
    }

    static class problem_4
    {
        problem_4()
        {
            int n=sc.nextInt(),m=sc.nextInt();
            System.out.println(min(n,m)+" "+((max(n,m)-min(n,m))/2));
        }
    }
}