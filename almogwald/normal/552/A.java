import java.util.Scanner;
public class Tablecount {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long sum = 0;
		for (int i=0;i<n;i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			sum +=(x2-x1+1)*(y2-y1+1);
		}
		in.close();
		System.out.println(sum);
		
	}

}