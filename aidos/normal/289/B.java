import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n, m, d;
	int a[][];
	int cnt[];
	int dp[];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		d = in.nextInt();
		a = new int[n][m];
		cnt = new int[80010];
		dp = new int[80010];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) a[i][j] = in.nextInt();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j]%d != a[0][0] % d){
					out.println(-1);
					return;
				}
				cnt[a[i][j]]++;
			}
		}
		int cur = 0;
		int ans = Integer.MAX_VALUE;
		
		for(int j = a[0][0] % d + (20000/d) * d; j >= 0; j -= d){
			dp[j] = dp[j + d] + cur;
			cur += cnt[j];
		}
		cur = 0;
		int c = 0;
		for(int i = a[0][0] % d; i <= 10000; i += d){
			ans = Math.min(ans, dp[i] + cur  + c);
			c += cur ;
			cur += cnt[i];
		}
		out.println(ans);
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