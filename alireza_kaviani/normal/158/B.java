import java.util.*;


public class codeforces1 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),ans=0;
        double cnt[]=new double[5];

        for(int i=0;i<n;i++)
        {
            cnt[sc.nextInt()]++;
        }

        ans+=cnt[4];
        ans+=cnt[3];

        cnt[1]-=cnt[3];

        if(cnt[1]<0)cnt[1]=0;

        ans+=Math.ceil(cnt[2]/2);
        cnt[2]%=2;

        if(cnt[2]==1)
        {
            cnt[1]-=2;
            if(cnt[1]<0) cnt[1]=0;
        }

        ans+=Math.ceil(cnt[1]/4);

        System.out.println(ans);
    }

}