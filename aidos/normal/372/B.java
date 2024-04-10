import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int d[][];
	int n, m, q;
	int dp[][][][];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		q = in.nextInt();
		d = new int[n+1][m+1];
		dp = new int[n+1][m+1][n+1][m+1];
		for(int i = 0; i < n; i++){
			char c[]=in.next().toCharArray();
			for(int j = 0; j < m; j++){
				if(c[j] == '1') d[i+1][j+1] = 0;
				else d[i+1][j+1] = 1+d[i][j+1];
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				for(int k = i; k <= n; k++){
					for(int t = j; t<= m; t++){
						dp[i][j][k][t] =  dp[i][j][k-1][t] + dp[i][j][k][t-1] - dp[i][j][k-1][t-1];
						int x = k - i+1;
						for(int y = t; y>=j && x > 0; y--){
							x = Math.min(d[k][y], x);
							dp[i][j][k][t] += x;
						}
					}
				}
			}
		}
		for(int i = 0; i < q; i++){
			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			int d = in.nextInt();
			out.println(dp[a][b][c][d]);
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
	}
}