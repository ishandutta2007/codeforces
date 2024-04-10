import java.util.*;
import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		double d=n;
		d/=10;
		System.out.println(10*Math.round(d));
	}
}