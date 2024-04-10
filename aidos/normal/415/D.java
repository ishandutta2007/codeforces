import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionD {
	public static void main(String[] args){
		new SolutionD().run();
	}
	int dp[];
	int n, k;
	int mod = 1000000007;
	void solve(){
		n = in.nextInt();
		k = in.nextInt();
		dp = new int[n+1];
		dp[1] = 1;
		for(int i = 0; i < k; ++i){
			for(int j = n/2; j > 0; --j){
				int x = dp[j];
				for(int t = j + j; t <= n; t += j){
					dp[t] += x;
					if( dp[t] >= mod) dp[t]-=mod;
				}
			}
		}
		int ans = 0;
		for(int  i = 1; i <= n; i++){
			ans += dp[i];
			if(ans >= mod) ans-=mod;
		}
		out.println(ans);
	}
	PrintWriter out;
	FastScanner in;
	public void run(){
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(InputStream is){
			bf = new BufferedReader(new InputStreamReader(is));
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(Exception ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}	
		int[] nextArray(int n){
			int x[] = new int[n];
			for(int i = 0; i < n; i++){
				x[i] = Integer.parseInt(next());
			}
			return x;
		}
	}
}