import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        int n=sc.nextInt(),ans=0;

        for(int i=0;i<n;i++)
        {
            String s=sc.next();
            if(s.charAt(0)=='-' || s.charAt(2)=='-')ans--;

            else ans++;
        }

        System.out.print(ans);
    }
}