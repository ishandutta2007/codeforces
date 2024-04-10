import java.util.Scanner;


public class Main {
	static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		long l = in.nextLong();
		long r = in.nextLong();
		if (l % 2 != 0)
			l++;
		if (l + 2 > r)
		    System.out.println(-1);
		else
		    System.out.println(l + " " + (l + 1) + " " + (l + 2));

	}

}