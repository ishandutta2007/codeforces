import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB{

	public static void main(String[] args){
		new SolutionB().run();
	}
	int a[] = new int[4];
	int b[] = new int[4];
	int c[] = new int[4];
	int n;
	void solve(){
		n = in.nextInt();
		for(int i = 0; i<4; i++){
			a[i] = Math.min(in.nextInt(), in.nextInt());
			b[i] = Math.min(in.nextInt(), in.nextInt());
			c[i] = a[i] + b[i];
		}
		int mi = 0;
		for(int i = 1; i < 4; i++){
			if(c[mi] > c[i]) mi = i;
		}
		if(c[mi] > n) out.println("-1");
		else out.println((mi+1) + " " + a[mi] + " " + (n - a[mi]));
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