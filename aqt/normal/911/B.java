import java.util.*;
public class _35_B_TwoCakes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(), A = sc.nextInt(), B = sc.nextInt();
		int max = 0;
		
		for(int i = 1; i<N; i++) {
			max = Math.max(Math.min(A/i, B/(N-i)), max);
		}
		
		System.out.println(max);
	}

}