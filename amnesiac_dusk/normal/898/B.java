import java.util.*;
import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int a=in.nextInt();
		int b=in.nextInt();
		int x=0;
		while(true)
		{
			
			if(n<x*a)
			{
				x=-1;
				break;
			}
			else if((n-x*a)%b==0)
			{
				break;
			}
			
			x++;
		}
		if(x!=-1)
		{
			System.out.println("YES");
			System.out.println(x+" "+(n-x*a)/b);
		}
		else
		{
			System.out.println("NO");
		}
	}
}