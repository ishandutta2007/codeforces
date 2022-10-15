import java.math.BigDecimal;
import java.util.Scanner;


public class C131 {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long m = sc.nextInt();
		
		long t = sc.nextInt();
		if (t == 5){
			System.out.println(factorial(n, 4) * factorial(m, 1));
			return;
		}
		
		long ans = 0;
		
		for (long i = 4; i < t; i++){
			
			long a = i;
			long b = t - i;
			
			if ((a <= n) && (b <= m)){
				ans += factorial(n, a) * factorial(m, b);
			}
			
		}
		System.out.println(ans);
	}
	
	public static long factorial(long n, long r){
		/*
		 * 	a > b always
		 * 
		 *        a!
		 *   -----------            
		 *   b! (a - b)!
		 */
		
		
		BigDecimal b = fac2(r).multiply(fac2(n - r));
        return fac2(n).divide(b).longValue();
	}
	
	public static BigDecimal fac2(long n) {
        if (n <= 1)
            return new BigDecimal(1);
        return new BigDecimal(n).multiply(fac2(n - 1));
    }

}