import java.util.Scanner;

public class palindromestuff {

	public static void main(String[] args) {
		String a;
		int n;
		Scanner in = new Scanner(System.in);
		a = in.nextLine();
		n = in.nextInt();
		
		in.close();
	//	System.out.println(a.length());
	//	System.out.println(n);
		if (a.length() % n != 0) {
			System.out.println("NO");	
			System.exit(0);
		}
		int pallen = a.length() /n;
		for (int i=0;i<n;i++) {
			for (int j=0;j<pallen/2;j++) {
				// System.out.println(a.charAt(i*pallen+j));
				if (a.charAt(i*pallen+j) != a.charAt(i*pallen+pallen-1-j)) {
					System.out.println("NO");	
					System.exit(0);					
				}
			}
		}
		System.out.println("YES");			
	}

}