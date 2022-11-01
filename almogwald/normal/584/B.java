import java.util.Scanner;
import java.util.Arrays;
public class e {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.close();
		
		long res1 = 1, res2 = 1;
		for (int i = 1; i <= n; ++i) {
			res1 = res1 * 27 % (1000000007);
			res2 = res2 * 7 % (1000000007);
		}
		
		res1 += 1000000007;
		long final_res = (res1 - res2) % (1000000007);
   		System.out.print(final_res);		
	}
}