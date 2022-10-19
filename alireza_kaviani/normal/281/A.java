import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s=sc.next();

        String ans=String.valueOf(s.charAt(0)).toUpperCase();

        for(int i=1;i<s.length();i++)
        {
            ans+=s.charAt(i);
        }

        System.out.println(ans);
    }

}