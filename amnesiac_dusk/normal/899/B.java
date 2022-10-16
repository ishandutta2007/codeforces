import java.util.*;
import java.io.*;
 
public class Main 
{
	public static void main(String[] args) throws IOException
	{	
		Scanner in=new Scanner(System.in);
		int b[]= {31,28,31,30,31,30,31,31,30,31,30,31,31, 31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
		int n=in.nextInt();
		int a[]=new int[n];
		for(int i=0; i<n; i++)
			a[i]=in.nextInt();
		boolean gollum=false,ans=false;
		for(int j=0; j<72-n; j++)
		{
			gollum=true;
			for(int k=1; k<=n; k++)
			{
				if(a[k-1]!=b[j+k])
				{
					gollum=false;
					break;
				}
			}
			if(gollum)
				ans=true;
			if(ans)
				break;
		}
		if(ans)
			System.out.println("YES");
		else
			System.out.println("NO");
		in.close();
	}
}