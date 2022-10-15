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
		int n = x.nextInt();
		int [] a = new int[n];
		for (int i = 0; i<n; ++i) a[i] = x.nextInt();
		Arrays.sort(a);
		int re = 0;
		for (int i = 0; i<n; i+=2) {
		    re += a[i+1]-a[i];
		}
		System.out.println(re);
	}
}