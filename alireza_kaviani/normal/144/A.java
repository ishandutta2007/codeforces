import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),ind=0,mind=0;
        int a[]=new int[n];
        int b[]=new int[n];

        for (int i = 0; i < n ; i++) {
            a[i]=sc.nextInt();
            b[i]=a[i];
        }

        Arrays.sort(b);

        for(int i=0;i<n;i++)
        {
            if(a[i]==b[n-1])
            {
                ind=i;
                break;
            }
        }

        for (int i = a.length - 1; i >= 0; i--) {
            if(a[i]==b[0])
            {
                mind=i;
                break;
            }
        }

        if(ind>mind)mind++;
        System.out.println(ind+(n-1)-mind);
    }

}