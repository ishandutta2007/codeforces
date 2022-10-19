import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),sum=0,sum2=0,ans=0;

        int a[]=new int[n];

        for (int i = 0; i < n ; i++) {
            a[i]=sc.nextInt();
            sum+=a[i];
        }

        sum/=2;
        Arrays.sort(a);

        for(int i=n-1;i>=0;i--)
        {
            ans++;
            sum2+=a[i];

            if(sum2>sum)break;
        }

        System.out.println(ans);
    }

}