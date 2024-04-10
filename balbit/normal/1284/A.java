/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner x = new Scanner(System.in);
		int n = x.nextInt(), m = x.nextInt();
		String [] s = new String[n];
		String [] t = new String[m];
		for (int i = 0; i<n; ++i) s[i] = x.next();
		for (int i = 0; i<m; ++i) t[i] = x.next();
		
		int q = x.nextInt();
		
		for (int i = 0; i<q; ++i) {
		    int X = x.nextInt();
		    System.out.println(s[(X-1)%n] + t[(X-1)%m]);
		}
	}
}