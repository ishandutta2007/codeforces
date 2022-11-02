import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class SolutionA {
	public static void main(String[] args) {
		new SolutionA().run();
	}
	int n;
	int m;
	char c[][];
	void go(int x){
		if(x == n) return;
		if(x % 2 == 0) for(int i = 0; i < m; i++) c[x][i] = '#';
		else if(x % 4 == 1) c[x][m-1] = '#';
		else c[x][0] = '#';
		go(x + 1);
	}
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		c = new char[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				c[i][j] = '.';
		go(0);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				out.print(c[i][j]);
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