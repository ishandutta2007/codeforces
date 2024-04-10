import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        String s=sc.next().toLowerCase(),s2=sc.next().toLowerCase();
        String a[]=new String[2];
        a[0]=s;a[1]=s2;
        Arrays.sort(a);

        if(s.equals(s2))System.out.print(0);

        else if(s.equals(a[0]))System.out.print(-1);

        else System.out.print(1);
    }
}