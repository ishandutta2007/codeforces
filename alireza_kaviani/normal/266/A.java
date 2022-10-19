import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),ans=0;
        String s=sc.next();

        for(int i=1;i<n;i++)
        {
            if(s.charAt(i)==s.charAt(i-1)) ans++;
        }

        System.out.println(ans);
    }

}