import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {
	public static void main(String[] args) {
		new SolutionB().run();
	}
	
	void solve(){
		int n = in.nextInt();
		int m = in.nextInt();
		boolean a[] = new boolean[n];
		boolean b[] = new boolean[m];
		int x = in.nextInt();
		for(int i = 0; i < x; i++) a[in.nextInt()] = true;
		x = in.nextInt();
		for(int i = 0; i < x; i++) b[in.nextInt()] = true;
		for(int i = 1; i <= 1000000; i++){
			if(a[i % n] == b[i % m]) continue;
			a[i%n] = true;
			b[i%m]=true;
		}
		for(int i = 0; i < n; i++){
			if(!a[i]) {
				out.println("No");
				return;
			}
		}
		for(int i = 0; i < m; i++){
			if(!b[i]) {
				out.println("No");
				return;
			}
		}
		out.println("Yes");
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