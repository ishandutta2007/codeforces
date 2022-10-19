import java.util.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int n=sc.nextInt() , m=sc.nextInt();

        int ans =0;
        for(int i=0;i<n;i++)
        {
            int t=sc.nextInt();

            if(t<=m)
            {
                ans++;
            }
            else
            {
                ans+=2;
            }
        }

        System.out.println(ans);
    }

}