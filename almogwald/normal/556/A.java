import java.util.Scanner;

public class w {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		String a = in.nextLine();
		int b = 0;
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (a.charAt(i) == '0') {
				b++;
			} else {
				c++;
			}
		}
		int p=Math.abs(b-c);
		System.out.println(p);
		in.close();
	}

}