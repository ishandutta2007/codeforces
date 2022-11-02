import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionD {
	public static void main(String[] args) {
		new SolutionD().run();
	}
	
	boolean used[][];
	double dp[][];
	int n, t;
	double p;
	double get(int x, int cur){
		if(x == t||cur == n) return cur;
		if(used[x][cur]) return dp[x][cur];
		used[x][cur] = true;
		return dp[x][cur] = p * get(x + 1, cur+1) + (1-p) * get(x + 1, cur);
	}
	void solve(){
		n = in.nextInt();
		p = in.nextDouble();
		t = in.nextInt();
		used = new boolean[t][n];
		dp = new double[t][n];
		out.printf("%.12f\n",get(0, 0));
	}
	FastScanner in;
	PrintWriter out;
	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader bf;

		public FastScanner(InputStream is) {
			bf = new BufferedReader(new InputStreamReader(is));
		}

		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
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
		short nextShort(){
			return Short.parseShort(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; ++i)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = Long.parseLong(next());
			return a;
		}
	}

}