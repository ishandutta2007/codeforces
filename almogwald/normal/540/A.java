import java.util.Scanner;


public class Lock {
	public static void main(String[] args) {
		int n;
		String s1,s2;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		s1 = in.next();
		s2 = in.next();
		in.close();
		long answer=0;
		for (int i = 0; i < n; i++) {
			int d1 = Integer.valueOf(s1.charAt(i)) -48;
			int d2 = Integer.valueOf(s2.charAt(i)) -48;
			
			int dx = Math.abs(d2-d1);
			if (dx > 5) dx = 10 -dx;
		//	System.out.println(dx);
			answer += dx;			
		}
		System.out.println(answer);
	}
}