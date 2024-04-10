import java.util.Scanner;


public class A276 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int k = sc.nextInt();
		int max = 0;
		boolean b = true; // for first check
		for (int i = 0; i < a; i++){
			int f = sc.nextInt();
			int t = sc.nextInt();
			int p;
			if (t > k){
				p = f - t + k;
			}else{
				p = f;
			}
			if (p > max || b){
				b = false;
				max = p;
			}
		}
		sc.close();
		System.out.println(max);
	}
	
}