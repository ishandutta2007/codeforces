import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionC{

	public static void main(String[] args){
		new SolutionC().run();
	}
	long n;
	int h;
	long go(int cur, long x, int tt){
		if(cur == h) return 0;
		long t = 1;
		for(int i = cur+1; i<h; i++)
			t *= 2;
		//out.println(cur + " " + x + " " + tt + " " + t);
		if(tt == 0){
			if( t >= x) return go(cur + 1, x, 1);
			return go(cur + 1, x - t, 0) + (t * 2)-1;
		}
		else {
			if( t < x) return go(cur + 1, x - t, 0);
			return go(cur + 1, x , 1) + (t * 2)-1;
		}
	}
	void solve(){
		h = in.nextInt();
		n = in.nextLong();
		out.println(go(0, n, 0) + h);
	}



	class Pair implements Comparable<Pair>{
		long x, y;
		Pair(long x, long y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Long) y).compareTo(o.y); 
			return ((Long) x).compareTo(o.x);
		}

	}
	FastScanner in;
	PrintWriter out;
	void run(){
		in = new FastScanner(System.in);
		out = new PrintWriter(new OutputStreamWriter(System.out));
		solve();
		out.close();
	}

	void runIO(){
		try{
			in = new FastScanner(new File("expr.in"));
			out = new PrintWriter(new FileWriter(new File("expr.out")));
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		public FastScanner(InputStream is){
			bf = new BufferedReader(new InputStreamReader(is), 32768);
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(IOException ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		String nextLine(){
			try{
				return bf.readLine();
			}
			catch(Exception ex){
				ex.printStackTrace();
			}
			return "";
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; i++)
				a[i] = Long.parseLong(next());
			return a;
		}
	}
}