import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionA {
	public static void main(String[] args) {
		new SolutionA().run();
	}
	
	void solve(){
		Point a = new Point(in.nextInt(), in.nextInt());
		Point b = new Point(in.nextInt(), in.nextInt());
		Point c = new Point(in.nextInt(), in.nextInt());
		c.x -= a.x;
		b.x -= a.x;
		c.y -= a.y;
		b.y -= a.y;
		long ans1 = b.x * 1L * c.y;
		long ans2 = b.y * 1L * c.x;
		if(ans1 > ans2) out.println("LEFT");
		else if(ans1 == ans2) out.println("TOWARDS");
		else out.println("RIGHT");
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