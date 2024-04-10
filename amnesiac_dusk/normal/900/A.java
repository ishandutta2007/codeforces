import java.util.*;
import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		int te,plu=0, min=0;
		for(int i=0; i<t; i++)
		{
			te=in.nextInt();
			if(te>0)
				plu++;
			else if(te<0)
				min++;
			te=in.nextInt();
		}
		if(plu>1&&min>1)
			System.out.println("No");
		else
			System.out.println("Yes");
	}
}