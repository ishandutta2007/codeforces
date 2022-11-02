import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
	public static void main(String[] args) {
		new SolutionC().run();
	}
	int p[];
	int a[];
	int n;
	int m;
	int k;
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		a = new int[n];
		p = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = in.nextInt()-1;
			p[a[i]] = i;
		}
		long ans = 0;
		for(int i = 0; i < m; i++){
			int x = in.nextInt() - 1;
			int pos = p[x];
			ans += pos/k;
			ans++;
			if(pos > 0){
				int tmp = a[pos];
				a[pos] = a[pos-1];
				a[pos-1] = tmp;
				p[a[pos]] = pos;
				p[a[pos-1]] = pos-1;
			}
		}
		out.println(ans);
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