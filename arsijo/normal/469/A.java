import java.util.Scanner;


public class A469 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean[] bol = new boolean[n];
		int a = sc.nextInt();
		for (int i = 0; i < a; i++){
			int g = sc.nextInt();
			bol[g-1] = true;
		}
		a = sc.nextInt();
		for (int i = 0; i < a; i++){
			int g = sc.nextInt();
			bol[g-1] = true;
		}
		for(int i = 0; i < n; i++){
			if (!bol[i]){
				System.out.println("Oh, my keyboard!");
				System.exit(0);
			}
		}
		System.out.println("I become the guy.");
	}
}