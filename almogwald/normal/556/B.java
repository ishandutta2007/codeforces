import java.util.Scanner;

public class w {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		int b=in.nextInt();
		int presses=(n-b)%n;
		boolean clockwise=false;
		for (int i = 1; i < n; i++) {
			b=in.nextInt();
			if ((clockwise && ((n+i-b)%n!=presses) ||
				(!clockwise && ((b-i+n)%n!=presses))))
			{
				System.out.println("No");
				return;
			}
			clockwise=!clockwise;
		}
		System.out.println("Yes");
		in.close();
	}

}