import java.util.Arrays;
import java.util.Scanner;


public class B322 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ar[] = new int[3];
		for(int i = 0; i < 3; i++){
			ar[i] = sc.nextInt();
		}
		
		Arrays.sort(ar);
		
		int ans = ar[0];
		ar[1] -= ans;
		ar[2] -= ans;
		ans += ar[1] / 3;
		ans += ar[2] / 3;
		
		if (ar[0] > 0 && ar[1] % 3 == 2 && ar[2] % 3 == 2) ans++;
		
		System.out.println(ans);
		sc.close();
	}
	
}