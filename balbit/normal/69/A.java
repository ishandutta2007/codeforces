/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner mo = new Scanner (System.in);
		int n = mo.nextInt();
		int a=0, b=0, c=0;
		for (int i = 0; i<n; i++){
			int x = mo.nextInt(), y =mo.nextInt(), z =mo.nextInt();
			a+=x; b+=y; c+=z;
		}
		if (a!=0 || b!=0 || c!=0) System.out.println("NO");
		else System.out.println("YES");
	}
}