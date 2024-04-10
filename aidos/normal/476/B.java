import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionB {
	public static void main(String[] args){
		new SolutionB().run();
	}
	String a, b;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3=0;
	void solve(){
		a = in.next();
		b=  in.next();
		for(int i  =0; i<a.length(); i++){
			if(a.charAt(i) == '-') cnt1--;
			else cnt1++;
		}
		int n = b.length();
		for(int i = 0; i < (1<<n); i++){
			boolean ok = true;
			for(int j = 0; j < n; j++){
				if( b.charAt(j) == '?') continue;
				if((i & (1 << j)) > 0 && b.charAt(j) == '-') ok = false;
				else if((i & (1 << j)) ==  0 && b.charAt(j) == '+') ok = false;
			}
			if(!ok) continue;
			int c = 0;
			cnt3++;
			for(int j = 0; j< n; j++){
				if((i & (1 << j)) > 0) c++;
				else c--;
			}
			if( c == cnt1) cnt2++;
		}
		out.printf("%.12f", (double) cnt2/cnt3);
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