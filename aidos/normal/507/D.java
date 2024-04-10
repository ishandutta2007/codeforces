import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionC{

	public static void main(String[] args){
		new SolutionC().run();
	}
	int n, k, m;
	long dp[][][][];
	long pow[];
	boolean used[][][][];
	long go(int cur, int ost, int has, int last){
		
		if(cur == n){
			if(last != 0) {
				if(ost == 0) return 1;
				return has;
			}
			return 0;
		}
		
		if(used[cur][ost][has][last]) return dp[cur][ost][has][last];
		used[cur][ost][has][last] = true;
		int hash = has;
		if(ost == 0) {
			if(last != 0) hash = 1;
		}
		long ans = 0;
		for(int i = 0; i < 10; i++){
			if(i == 0) ans += go(cur+1, ost, hash, 0);
			else {
				int z = (int)((i * pow[cur] % k + ost)% k);
				ans += go(cur+1, z, hash, 1);
			}
			ans %= m;
		}
		dp[cur][ost][has][last] = ans;
		return ans;
	}
	void solve(){
		n = in.nextInt();
		k = in.nextInt();
		m = in.nextInt();
		dp = new long[n][k][2][2];
		used = new boolean[n][k][2][2];
		pow = new long[n+1];
		pow[0] = 1;
		for(int i=1; i<=n; i++){
			pow[i] = (pow[i-1] * 10L) % k;
		}
		long ans = 0;
		for(int i = 0; i < 10; i++){
			if(i == 0) ans += go(1, 0, 0, 0);
			else ans += go(1, i % k, 0, 1);
			ans %= m;
		}
		ans %= m;
		out.println(ans);
	}



	class Pair implements Comparable<Pair>{
		long x, y;
		Pair(long x, long y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Long) y).compareTo(o.y); 
			return ((Long) x).compareTo(o.x);
		}

	}
	FastScanner in;
	PrintWriter out;
	void run(){
		in = new FastScanner(System.in);
		out = new PrintWriter(new OutputStreamWriter(System.out));
		solve();
		out.close();
	}

	void runIO(){
		try{
			in = new FastScanner(new File("expr.in"));
			out = new PrintWriter(new FileWriter(new File("expr.out")));
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		public FastScanner(InputStream is){
			bf = new BufferedReader(new InputStreamReader(is), 32768);
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(IOException ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		String nextLine(){
			try{
				return bf.readLine();
			}
			catch(Exception ex){
				ex.printStackTrace();
			}
			return "";
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; i++)
				a[i] = Long.parseLong(next());
			return a;
		}
	}
}