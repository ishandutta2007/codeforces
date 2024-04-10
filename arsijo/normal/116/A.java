import java.util.Scanner;


public class A116 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		long sum = 0;
		long max = 0;
		for(int i = 1; i < n; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			sum+=b-a;
			max = Math.max(max, sum);
		}
		System.out.println(max);
	}
	
}