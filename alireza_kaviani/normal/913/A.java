import java.util.*;
import static java.lang.Math.*;

public class contest1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String args[])
    {
        problem_1 a=new problem_1();
    }

    static class problem_1
    {
        problem_1()
        {
            int n=sc.nextInt() , m=sc.nextInt();
            int p=(int)pow(2,(min(32,n)));

            System.out.printf("%d",m%p);
        }
    }
}