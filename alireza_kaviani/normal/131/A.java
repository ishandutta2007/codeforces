import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s=sc.next(),ans=s;
        int a = 0,cnt=0;

        for(int i=0;i<s.length();i++)
        {
            if(i==0 && s.charAt(0)>='a') a=1;

            else if(s.charAt(i)<'a') cnt++;
        }

        if(cnt==s.length()) ans=s.toLowerCase();

        if(a==1 && cnt==s.length()-1)
        {
            s.toLowerCase();

            ans=String.valueOf(s.charAt(0)).toUpperCase();

            for(int i=1;i<s.length();i++)
            {
                ans+=String.valueOf(s.charAt(i)).toLowerCase();
            }
        }

        System.out.println(ans);
    }

}