import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static BigInteger fac(int n){
		if(n == 0 || n == 1)
			return BigInteger.ONE;
		BigInteger ans = BigInteger.valueOf(1);
		for(int i = 2; i <= n; i++)
			ans = ans.multiply(BigInteger.valueOf(i));
		return ans;
	}
	
	static BigInteger c(int n, int k){
		return fac(n).divide(fac(n - k)).divide(fac(k));
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		BigInteger ans = c(n, 5).add(c(n, 6)).add(c(n, 7));
		System.out.println(ans);
		
	}
}