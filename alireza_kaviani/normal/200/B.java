import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        problem_1 a=new problem_1();

    }

    static class problem_1
    {
        problem_1()
        {
            int n=sc.nextInt();
            double ans=0;

            for(int i=0;i<n;i++)
            {
                ans+=sc.nextDouble();
            }

            System.out.printf("%.10f",ans/(double)n);
        }
    }
}