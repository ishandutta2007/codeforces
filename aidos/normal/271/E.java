import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionE {
	public static void main(String[] args){
		new SolutionE().run();
	}
	HashSet <Integer> hs;
	int gcd(int a, int b){
		if(a == 0) return b;
		return gcd(b % a, a);
	}
	int n, m, k;
	long ans = 0;
	void add(int x, int m){
		while( x < m){
			if(hs.contains(x)) return;
			hs.add(x);
			ans += m - x;
			x <<= 1;
		}
	}
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		hs = new HashSet<Integer>();
		for(int i = 0; i < n; i++){
			int x = in.nextInt() - 1;
			k = gcd(k, x);
		}
		for(int i = 1; i  <= 50000; i++) {
			if(k % i == 0) {
				add(i, m);
				add(k/i, m);
			}
		}
		out.println(ans);
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