import java.util.Scanner;


public class A251 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int ar[] = new int[n];
		
		for(int i = 0; i < n; i++) {
			ar[i] = sc.nextInt();
		}
		
		long ans = 0;
		
		int r = 0;
		for (int l = 0; l < n; l++) {
			r = Math.max(r, l);
			while(r + 1 < n && ar[r + 1] - ar[l] <= d) {
				r++;
			}
			if (r - l + 1 <= 2) {
				continue;
			}
			long a = r - l;
			ans = ans + (long) a * (long) (a - 1) / 2;
		}
		
		System.out.println(ans);
		
		sc.close();
	}
	
}