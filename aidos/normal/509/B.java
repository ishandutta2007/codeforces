import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {
	public static void main(String[] args) {
		new SolutionB().run();
	}
	int n;
	int m;
	int a[];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		a = in.nextIntArray(n);
		int mi = a[0];
		int ma = a[0];
		for(int i = 1; i < n; i++){
			if(mi > a[i]) mi = a[i];
			if(ma < a[i]) ma = a[i];
		}
		if(ma - mi > m) {
			out.println("NO");
			return;
		}
		out.println("YES");
		for(int i = 0; i < n; i++){
			int cur = mi;
			if(a[i] > mi) cur++;
			for(int j = 0; j < cur; j++) out.print("1 ");
			for(int j = cur; j < a[i]; j++) out.print((j - cur +2) + " ");
			out.println();
		}
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