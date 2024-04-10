import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt();
        int a1=0,a2=0,a3=0;

        for(int i=0;i<n;i++)
        {
            a1+=sc.nextInt();
            a2+=sc.nextInt();
            a3+=sc.nextInt();
        }

        if(a1==0 && a2==0  && a3==0)
        {
            System.out.println("YES");
        }

        else
        {
            System.out.println("NO");
        }
    }

}