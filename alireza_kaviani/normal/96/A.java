import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        String s=sc.next();
        char last=s.charAt(0);
        int max=1;
        boolean t=false;

        for (int i = 1; i <s.length() ; i++) {
            if(max==7)t=true;
            if(last==s.charAt(i))max++;
            else max=1;

            last=s.charAt(i);
        }

        if(max>=7)
        {
            t=true;
        }

        if(t) System.out.print("YES");

        else System.out.print("NO");
    }
}