import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n, m;
	int a[];
	int b[];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		a = new int[m];
		b = new int[m];
		for(int i = 0; i < n; i++){
			String x = in.next();
			if(x.lastIndexOf('1') == -1){
				out.println(-1);
				return;
			}
			int pos = x.lastIndexOf('1');
			for(int j = 0; j < m; j++){
				if(x.charAt(j) == '1') pos = j;
				if(pos <= j) a[j] = j - pos;
				else a[j] = m - pos + j;
			}
			pos = x.indexOf('1');
			for(int j = m-1; j>=0; j--){
				if(x.charAt(j) == '1') pos = j;
				if(pos >= j) a[j] = Math.min(a[j], pos - j);
				else a[j] = Math.min(a[j], pos + m - j);
			}
			for(int j = 0; j < m; j++)
				b[j] += a[j];
		}
		int res = Integer.MAX_VALUE;
		for(int i = 0; i < m; i++)
			res = Math.min(res, b[i]);
		out.println(res);
	}
	


	class Pair implements Comparable<Pair>{
		int x, y;
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Integer) y).compareTo(o.y); 
			return ((Integer) x).compareTo(o.x);
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
			bf = new BufferedReader(new InputStreamReader(is));
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
		char nextChar(){
			return next().charAt(0);
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