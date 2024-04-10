import java.util.*;
import java.io.*;
 
public class Main 
{
	public static void main(String[] args) throws IOException
	{	
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int m=in.nextInt();
		int b=0;
		boolean ans=true;
		for(int i=0; i<n; i++)
		{
			int c=in.nextInt();
			int d=in.nextInt();
			if(b>=c)
			{
				if(b<d)
				b=d;
			}
			else
				ans=false;
		}
		if(b<m)
			ans=false;
		if(ans)
			System.out.println("YES");
		else
			System.out.println("NO");
		in.close();
	}
}