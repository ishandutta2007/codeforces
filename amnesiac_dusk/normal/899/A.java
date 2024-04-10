import java.util.*;
import java.io.*;
 
public class Main 
{
	public static void main(String[] args) throws IOException
	{	
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int a[]=new int[2];
		for(int i=0; i<n; i++)
		{
			if(in.nextInt()==1)
				a[0]++;
			else
				a[1]++;
		}
		if(a[1]<a[0])
			System.out.println(a[1]+(a[0]-a[1])/3);
		else if(a[1]==a[0])
			System.out.println(a[1]);
		else
			System.out.println(a[0]);
		in.close();
	}
}