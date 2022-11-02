import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
	public static void main(String[] args){
		new SolutionC().run();
	}
	int q[];
	int deg[];
	int x[];
	int y[];
	int s[];
	void solve(){
		int n = in.nextInt();
		deg = new int[n];
		s = new int[n];
		x = new int[n];
		y = new int[n];
		q = new int[n];
		int sz = 0;
		int sz2 = 0;
		for(int i = 0; i < n; i++){
			deg[i] = in.nextInt();
			s[i] = in.nextInt();
			if(deg[i] <= 1){
				q[sz++] = i;
			}
		}
		while(sz > 0){
			sz--;
			int t = q[sz];
			if( deg[t] == 0) continue;
			deg[t]--;
			deg[s[t]]--;
			x[sz2] = t;
			y[sz2] = s[t];
			sz2++;
			s[s[t]] ^= t;
			if(deg[s[t]] == 1) {
				q[sz] = s[t];
				sz++;
			}
		}
		out.println(sz2);
		for(int i = 0; i < sz2; i++)
			out.println(x[i] + " " + y[i]);
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