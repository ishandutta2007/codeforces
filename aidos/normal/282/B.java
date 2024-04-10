import java.io.*;
import java.math.*;
import java.util.*;



public class SolutionB {
	public static void main(String[] args){
		new SolutionB().run();
	}
	void solve(){
		int n = in.nextInt();
		int a = 0, b = 0;
		StringBuilder sb = new StringBuilder();
		for(int i = 0, x, y; i < n; i++){
			x = in.nextInt();
			y = 1000 - x;
			in.st.nextToken();
			if( a + x <= b + 500) {
				sb.append('A');
				a+=x;
			}
			else {
				sb.append('G');
				b += y;
			}
		}
		
		out.println(sb);
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