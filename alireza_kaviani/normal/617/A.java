import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt();
        int ans=n/5+(n%5==0?0:1);
        System.out.println(ans);
    }

}