import java.util.*;
import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		double a=in.nextInt(), b=in.nextInt();
		int c=in.nextInt();
		int i=0,te2;
		ou: while(i<1000000)
		{
			te2=(int)(a/b);
			if(te2==c&&i!=0)
			{
				System.out.println(i);
				break ou;
			}
		//	System.out.println(te2);
			i++;
			a-=te2*b;
			a*=10;
			//System.out.println(a);
		}
		if(i>500000)
			System.out.println(-1);
	}
}