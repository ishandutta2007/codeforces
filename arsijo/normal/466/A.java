import java.util.Scanner;


public class A466 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = Math.min((n / m) * b, (n - (n % m)) * a);
		int d = Math.min((n % m) * a, b);
		System.out.println(c + d);
	}
	
}