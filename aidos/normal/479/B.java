import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n;
	int a[];
	int m;
	int x[];
	int y[];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		a = new int[n];
		x = new int[m];
		y = new int[m];
		for(int i = 0; i < n; i++){
			a[i] = in.nextInt();
		}
		int sz = 0;
		while(sz < m){
			int mi = 0;
			int ma = 0;
			for(int i = 0; i < n; i++){
				if(a[mi] > a[i]) mi = i;
				if(a[ma] < a[i]) ma = i;
			}
			if(a[ma] - a[mi] < 2) break;
			a[ma]--;
			a[mi]++;
			x[sz] = ma+1;
			y[sz] = mi+1;
			sz++;
		}
		Arrays.sort(a);
		out.println((a[n-1] - a[0]) + " " + sz);
		for(int i = 0; i < sz; i++){
			out.println(x[i] + " " + y[i]);
		}
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
		public String toString(){
			return x + " " + y;
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