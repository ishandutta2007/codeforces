import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        int n=sc.nextInt(),k=sc.nextInt(),ans=0;
        int a[]=new int[n];

        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }

        for(int i=0;i<n;i++)
        {
            if(a[i]>=a[k-1] && a[i]>0)
            {
                ans++;
            }
        }

        System.out.println(ans);
    }
}