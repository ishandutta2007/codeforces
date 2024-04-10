import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionA {
	public static void main(String[] args){
		new SolutionA().run();
	}
	
	boolean ok(int x){
		int b[] = new int[11];
		while( x > 0){
			b[x % 10]++;
			x/=10;
		}
		for(int i = 0; i < 10; i++) if( b[i] > 1) return false;
		return true;
	}
	void solve(){
		int n = in.nextInt() + 1;
		while(!ok(n)) n++;
		out.println(n);
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