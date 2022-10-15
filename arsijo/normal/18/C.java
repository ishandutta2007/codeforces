import java.util.Scanner;


public class C18 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r[] = new int[n];
		
		long a = 0;
		long b = 0;
		
		for(int i = 0; i < n; i++){
			r[i] = sc.nextInt();
			a+=r[i];
		}
		
		sc.close();
		
		int ans = 0;
		
		for(int i = 0; i < n-1; i++){
			b+=r[i];
			a-=r[i];
			if (a == b){
				ans++;
			}
		}
		
		System.out.println(ans);
	}
	
}