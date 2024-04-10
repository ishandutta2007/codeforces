import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),ans=0;

        for(int i=0;i<n;i++)
        {
            int a=sc.nextInt(),b=sc.nextInt();

            if(b-a>=2)ans++;
        }

        System.out.println(ans);
    }

}