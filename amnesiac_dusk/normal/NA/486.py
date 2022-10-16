import java.util.*;
public class Main
{
    public static void main(String[]args)
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        long a=0;
        for(int i=0; i<n; i++)
        a+=Math.abs(in.nextInt());
        System.out.println(a);
    }
}