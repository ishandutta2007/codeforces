import java.util.Scanner;


public class A447 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		int n = sc.nextInt();
		boolean[] bol = new boolean[p];
		for(int i = 0; i<n; i++){
			int a = sc.nextInt();
			if(bol[a % p]){
				System.out.println(i+1);
				System.exit(0);
			}
			bol[a % p] = true;
		}
		System.out.println(-1);
	}
	
}