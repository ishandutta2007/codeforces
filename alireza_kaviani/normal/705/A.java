import java.util.*;
import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        problem_2 a=new problem_2();

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

    static class problem_2
    {
        problem_2()
        {
            int n=sc.nextInt();
            String[] s=new String[2];

            s[0]="I hate";
            s[1]="I love";

            for(int i=0;i<n;i++)
            {
                System.out.print(s[i%2]+((i!=n-1)?" that ":" it"));
            }
        }
    }
}