import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        int n=sc.nextInt();

        for(int i=0;i<n;i++)
        {
            String s=sc.next();
            int l=s.length()-2;
            if(l<=8)
            {
                System.out.println(s);
            }
            else
            {
                System.out.println(s.charAt(0)+""+l+""+s.charAt(l+1));
            }
        }
    }
}