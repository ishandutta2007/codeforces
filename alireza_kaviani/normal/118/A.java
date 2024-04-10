import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        String s=sc.next();

        s=s.toLowerCase();

        for (int i=0;i<s.length();i++) {
            if(s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u' || s.charAt(i)=='y')
            {
                //.....
            }
            else
            {
                System.out.print("."+s.charAt(i));
            }
        }
    }
}