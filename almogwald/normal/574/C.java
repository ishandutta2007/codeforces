import java.util.Scanner;
public class e {

	static int gcd(int num1, int num2) {
		if (num2 == 0)
			return num1;
		return gcd(num2, num1%num2);
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		int[] prizes = new int[n];
		for(int i=0;i<n;i++){
			prizes[i]=in.nextInt();
		}
		in.close();
		int all_gcd = prizes[0];
		for (int i = 1; i < n; ++i) {
			if (all_gcd >= prizes[i])
				all_gcd = gcd(all_gcd, prizes[i]);
			else
				all_gcd = gcd(prizes[i], all_gcd);
		}
		for(int i = 0; i < n; i++) {
			int chekr = prizes[i] / all_gcd;
			while(true) {
				if(chekr % 2 == 0) {
					chekr /= 2;
				} else {
					break;
				}
			}
			while(true){
				if(chekr%3==0){
					chekr/=3;
				} else {
					break;
				}
			}
			if(chekr!=1){
				System.out.println("No");
				System.exit(0);
			}
		}
		System.out.println("Yes");
		
	}

}