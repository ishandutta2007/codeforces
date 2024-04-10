import java.util.*;
public class Main
{
    public static void main(String[]holags)
    {
    int ans=0;
    Scanner in=new Scanner(System.in);
    int n=in.nextInt();
    while(n>=100)
    {
        n-=100;
        ans++;
    }
    while(n>=20)
    {
        n-=20;
        ans++;
    }
    while(n>=10)
    {
        n-=10;
        ans++;
    }
    while(n>=5)
    {
        n-=5;
        ans++;
    }
    while(n>=1)
    {
        n-=1;
        ans++;
    }
    System.out.println(ans);
    //Ok I am not so supercool:P
}}