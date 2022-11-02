import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int deq[];
	int t0, t1, a, b;
	int dp[][];
	void solve(){
		int n = in.nextInt(), m = in.nextInt(), d = in.nextInt();
		deq = new int[n+1];
		dp = new int[n][2];
		long ans = 0;
		a = in.nextInt();
		ans = in.nextInt();
		t0 = in.nextInt();
		for(int i = 0; i<n; i++){
			dp[i][0] = -Math.abs(a - i - 1);
		}
		for(int i = 1; i<m; i++){
			a = in.nextInt();
			ans += in.nextInt();
			t1 = in.nextInt();
			int cur = i%2;
			int prev = 1 - cur;
			int st = 0;
			int fi = 0;
			int dis = n-1;
			if(d *1L * (t1 - t0) < dis) dis = d * (t1 - t0);
			int t = 0;
			for(int j = 0; j<n; j++){
				while(st < fi && deq[st]+dis<j){
					st++;
				}
				while(j+dis>=t && t < n){
					while(fi>st && dp[deq[fi-1]][prev] < dp[t][prev]) fi--;
					deq[fi++] = t++;
				}
				dp[j][cur] = dp[deq[st]][prev] - Math.abs(a - j - 1);
			}
			t0 = t1;
		}
		int mi = Integer.MIN_VALUE;
		for(int i = 0; i < n; i++)
			mi = Math.max(mi, dp[i][(m - 1) % 2]);
		out.println(ans + mi);
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
	}
}