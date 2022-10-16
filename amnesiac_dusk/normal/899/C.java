import java.util.*;
import java.io.*;
 
public class Main 
{
	public static void main(String[] args) throws IOException
	{	
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		if(n==1)
		{
			System.out.println(1);
			System.out.print("1 1");
		}
		if(n%4==0)
		{
			System.out.println(0);
			System.out.print(n/2+" ");
			for(int i=1; i<=n/4; i++)
				System.out.print(i+" ");
			for(int i=3*n/4+1; i<=n; i++)
				System.out.print(i+" ");
		}
		else if(n%2==0)
		{
			System.out.println(1);
			System.out.print(n/2+" ");
			for(int i=1; i<=n/2; i++)
			{
				if(i%2==0)
					System.out.print(i+" ");
			}
			System.out.print(n/2+1+" ");
			for(int i=n/2+2; i<=n; i++)
			{
				if(i%2==1)
					System.out.print(i+" ");
			}
		}
		else if(n%2==1)
		{
			if((n+1)%4==0)
				System.out.println(0);
			else
				System.out.println(1);
			System.out.print(n/2+" "+3+" ");
			for(int i=4; i<=n; i++)
			{
				if(i%4==0||(i+1)%4==0)
					System.out.print(i+" ");
			}
			System.out.println();
		}
		in.close();
	}
}