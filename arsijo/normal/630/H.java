import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static BigInteger fac(int n) {
		if (n == 0 || n == 1)
			return BigInteger.ONE;
		BigInteger ans = BigInteger.valueOf(1);
		for (int i = 2; i <= n; i++)
			ans = ans.multiply(BigInteger.valueOf(i));
		return ans;
	}

	static BigInteger c(int n, int k) {
		return fac(n).divide(fac(n - k)).divide(fac(k));
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		BigInteger dp[][] = new BigInteger[n + 1][6];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= 5; j++)
				dp[i][j] = BigInteger.valueOf(0);
		dp[0][0] = BigInteger.valueOf(1);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 5; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j != 0) {
					dp[i][j] = dp[i][j].add(dp[i - 1][j - 1].multiply(BigInteger.valueOf(n - j + 1)));
				}
			}
		}
		System.out.println(dp[n][5]);
	}
}