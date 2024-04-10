
import java.util.Scanner;

public class two {

	public static void main(String[] args) {
		String a;
		int abpos, bapos;
		
		Scanner in = new Scanner(System.in);
		a = in.nextLine();
		in.close();
		abpos = a.indexOf("AB");
		if (abpos == -1) {
			System.out.println("NO");
			System.exit(0);
		}
		if (a.indexOf("BA",abpos+2) != -1) {
			System.out.println("YES");		
			System.exit(0);
		}

		bapos = a.indexOf("BA");
		if (bapos == -1) {
			System.out.println("NO");
			System.exit(0);
		}
		if (a.indexOf("AB",bapos+2) != -1) {
			System.out.println("YES");		
			System.exit(0);
		}
		System.out.println("NO");
	

}}