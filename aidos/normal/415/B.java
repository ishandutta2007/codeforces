import java.io.*;
import java.math.*;
import java.util.*;



public class SolutionB {
	public static void main(String[] args){
		new SolutionB().run();
	}
	void solve(){
		int n = in.nextInt();
		int a = in.nextInt();
		int b =  in.nextInt();
		StringBuilder sb = new StringBuilder();
		for(int i = 0, x; i < n; i++){
			x = in.nextInt();
			long tt = x * 1L * a/b;
			long z = tt * b;
			z/=a;
			z++;
			if(z > x) z = x;
			while(z > 0 && (z - 1)  * 1L * a/b>=tt) z--;
			sb.append(x - z);
			sb.append(' ');
		}
		
		out.print(sb);
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