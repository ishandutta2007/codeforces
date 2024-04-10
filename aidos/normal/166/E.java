import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB{

	public static void main(String[] args){
		new SolutionB().run();
	}
	int dp[][];
	int mod = 1000000007;
	void solve(){
		int n;
		n = in.nextInt();
		dp = new int[2][4];
		dp[0][0] = 1;
		int sum = 1;
		int prev = 0;
		for(int i = 1; i<=n; i++){
			int cur = prev ^ 1;
			for(int j = 0; j < 4; j++){
				dp[cur][j] = sum - dp[prev][j];
			}
			prev ^= 1;
			sum = 0;
			for(int j = 0; j < 4; j++){
				if(dp[prev][j] < 0) dp[prev][j] += mod;
				else if(dp[prev][j] >= mod) dp[prev][j] -= mod;
				sum += dp[prev][j];
				if(sum >= mod) sum -= mod;
			}
		}
		out.println(dp[n & 1][0]);
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
	}
}