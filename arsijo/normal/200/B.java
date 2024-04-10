import java.util.Scanner;


public class B200 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long sum = 0;
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			sum += a;
		}
		double ans = (double) sum / n;
		sc.close(); 
		System.out.println(ans);
	}
	
}