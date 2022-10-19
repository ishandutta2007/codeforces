import java.util.*;
import static java.lang.Math.*;

public class codeforces1 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[])
    {
        problem_6 a=new problem_6();
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
            if(n==1 && m==10)
            {
                System.out.println(-1);
            }
            else
            {
                m=((m==10)?(1):m);
                System.out.print(m);
                for(int i=1;i<n;i++)
                {
                    System.out.print(0);
                }
            }
        }
    }

    static class problem_5
    {
        public boolean check(int a,int b)
        {
            return (a%10==0 || a%10==b);
        }

        problem_5()
        {
            int n=sc.nextInt(),m=sc.nextInt();

            int ans=0;
            for(int i=1;i<=10;i++)
            {
                if(check(n*i,m))
                {
                    ans=i;
                    break;
                }
            }

            System.out.println(ans);
        }
    }

    static class problem_6
    {
        problem_6()
        {
            long a=sc.nextLong(),b=sc.nextLong();
            long x=sc.nextLong(),y=sc.nextLong(),z=sc.nextLong();

            a-=2*x;
            b-=3*z;
            a-=y;
            b-=y;

            long ans=0;
            if(b<0)
            {
                ans+=-b;
            }
            if(a<0)
            {
                ans+=-a;
            }

            System.out.print(ans);
        }
    }
}