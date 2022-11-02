import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
	public static void main(String[] args){
		try{
			new SolutionC().run();
			//new SolutionC().runIO();
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}
	int n, k;
	int a[];
	void solve(){
		n = in.nextInt();
		k = in.nextInt();
		a = in.nextArray(n);
		Arrays.sort(a);
		for(int i = a[0]; i>1; i--){
			int cur = 0;
			for(int j = i; j<= a[n-1] && cur < n; j+=i){
				if(a[cur] - j>=i) continue;
				if(a[cur]-j>k || a[cur] < j) break;
				int r = n-1;
				while(cur <= r){
					int mid = (cur + r) /2;
					if(a[mid] - j <= k) {
						cur = mid+1;
					}
					else r = mid-1;
				}
			}
			if( cur == n ){
				out.println(i);
				return;
			}
		}
		out.println(1);
	}
	PrintWriter out;
	FastScanner in;
	public void run(){
		try{
			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	public void runIO(){
		try{
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}

	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(File is){
			try{
				bf = new BufferedReader(new FileReader(is));
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
		public FastScanner(InputStream is){
			try{
				bf = new BufferedReader(new InputStreamReader(is));
			}catch(Exception ex){
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