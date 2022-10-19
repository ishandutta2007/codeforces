import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s=sc.next();
        String s2="hello";
        int j=0;

        for(int i=0;i<s.length();i++)
        {
            if(j<5)
            {
                if(s2.charAt(j)==s.charAt(i))j++;
            }
        }

        if(j==5)
        {
            System.out.println("YES");
            return;
        }

        System.out.println("NO");
    }

}