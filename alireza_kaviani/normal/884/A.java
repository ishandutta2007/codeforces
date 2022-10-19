import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),t=sc.nextInt();
        int sec[]=new int[n];

        for (int i = 0; i <n ; i++) {
            sec[i]=86400-sc.nextInt();
        }

        int i=0,ans=0;

        while(t>0)
        {
            t-=sec[i];
            ans++;
            i++;
        }

        System.out.println(ans);
    }

}