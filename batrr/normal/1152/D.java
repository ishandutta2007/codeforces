import java.util.Scanner;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    private static int mod = 1000000007;
    public static void main(String[] args) {
        int [][]dp = new int[2005][2005];
        int [][]ok = new int[2005][2005];
        ok[0][0] = 1;
        for(int i = 1; i <= 2000; i++){
            for(int j = i & 1; j <= i; j += 2){
                if(j == 0) {
                    dp[i][j] = dp[i - 1][j + 1];
                    if(ok[i - 1][j + 1] == 1)
                        dp[i][j] = (dp[i][j] + 1) % mod;
                    else
                        ok[i][j] = 1;
                    continue;
                }
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
                if(ok[i - 1][j + 1] == 1 || ok[i - 1][j - 1] == 1)
                    dp[i][j] = (dp[i][j] + 1) % mod;
                else
                    ok[i][j] = 1;

            }
        }
        System.out.print(dp[2 * sc.nextInt()][0]);
    }

}