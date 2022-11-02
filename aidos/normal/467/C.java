import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n, m, k;
	long a[];
	long dp[][];
	boolean used[];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		a = new long[n+1];
		for(int i = 1; i <= n; i++){
			a[i] = a[i-1] + in.nextLong();
		}
		if(m == 1){
			used= new boolean[n+1];
			long ans = 0;
			for(int i = 1; i <= k; i++){
				int pos = -1;
				for(int j = 1; j <= n; j++){
					if(used[j]) continue;
					if(pos == -1 || a[pos] - a[pos-1] < a[j] - a[j-1]) pos=j;
				}
				used[pos] = true;
				ans += a[pos] - a[pos-1];
			}
			out.println(ans);
			return;
		}

		dp = new long[n+1][k+1];
		
		for(int i = 1; i<= k; i++){
			dp[0][i] = Long.MIN_VALUE;
		}
		for(int i = 1; i<=n; i++){
			if(m <= i){
				for(int j = 1; j<=k; j++){
					dp[i][j] = Math.max(dp[i-m][j-1] + a[i] - a[i-m], dp[i-1][j]);
				}
			}else {
				for(int j = 1; j<=k; j++){
					dp[i][j] = Long.MIN_VALUE;
				}
			}
		}
		out.println(dp[n][k]);
	}


	class Pair implements Comparable<Pair>{
		int x, y;
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Integer) y).compareTo(o.y); 
			return ((Integer) x).compareTo(o.x);
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
			bf = new BufferedReader(new InputStreamReader(is));
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