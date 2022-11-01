//package CodeForces;

import java.util.Scanner;
import java.util.Arrays;

public class P492B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int lanterns = s.nextInt();
		int length = s.nextInt();
		int[] arr = new int[lanterns];
		for (int i=0;i<lanterns;i++) {
			arr[i]=s.nextInt();
		}
		Arrays.sort(arr);
		int max = 2*Math.max(arr[0], length-arr[arr.length-1]);
		//System.out.print(max);
		for (int j=0;j<lanterns-1;j++) {
			int t = arr[j+1]-arr[j];
			if (t>max) max=t;
		}
		System.out.print(max/2.0);
		s.close();
	}
}