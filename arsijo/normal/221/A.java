import java.util.Scanner;


public class A221 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.print(n);
		for(int i = 1; i < n; i++){
			System.out.print(" " + i);
		}
		sc.close();
	}
	
}