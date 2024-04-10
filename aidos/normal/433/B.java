import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB{

	public static void main(String[] args){
		new SolutionB().run();
	}
	int n, m;
	long c[];
	Integer a[];
	long d[];
	void solve(){
		n = in.nextInt();
		c = new long[n+1];
		d = new long[n+1];
		a = new Integer[n+1];
a[0] = 0;
		for(int i = 1; i<= n; i++){
			a[i] = in.nextInt();
			d[i] = a[i] + d[i-1];
		}
		Arrays.sort(a);
		for(int i = 1; i<= n; i++){
			c[i] = c[i-1] + a[i];
		}
		m = in.nextInt();
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < m; i++){
			int z = in.nextInt();
			int l = in.nextInt()-1;
			int r = in.nextInt();
			long sum = c[r] - c[l];
			if(z == 1) sum = d[r] - d[l]; 
			sb.append(sum);
			sb.append('\n');
		}
		out.print(sb);
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
	}
}