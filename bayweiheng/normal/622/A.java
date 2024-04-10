//package CodeForces;

import java.util.Scanner;

public class P622A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long l = s.nextLong();
		long n = (long) Math.sqrt(2*l);
		long a = l-(n*n+n)/2;
		if (a<1) {
			a+=n;
		}
		System.out.print(a);
		s.close();
	}
}