import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int n=sc.nextInt();

        if(n<0)
        {
            if(abs(n%10)>abs(n/10%10))
            {
                System.out.print(n/10);
            }

            else
            {
                System.out.print(n/100*10+n%10);
            }
        }

        else
        {
            System.out.print(n);
        }
    }

}