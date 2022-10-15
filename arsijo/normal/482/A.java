import java.util.Scanner;


public class A482 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int l = 1;
		int r = m + 1;
		while (l <= r){
			System.out.print(l + " ");
			l++;
			if (l <= r){
				System.out.print(r + " ");
				r--;
			}
		}
		for (int i = m + 2; i <= n; i++){
			System.out.print(i + " ");
		}
	}
	
}