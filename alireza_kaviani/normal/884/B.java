import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),x=sc.nextInt(),sum=0;
        int arr[]=new int[n];

        for (int i = 0; i < n; i++) {
            arr[i]=sc.nextInt();
            sum+=arr[i];
        }

        if(sum+(n-1)==x)
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }

}