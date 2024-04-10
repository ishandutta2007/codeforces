import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n;
	int a[][];
	void solve(){
		n = in.nextInt();
		int l = -(int)(2e9);
		int r = -l;
		for(int i = 0; i<n; i++){
			String a = in.next();
			int x = in.nextInt();
			String ans = in.next();
			if(a.equals(">")){
				if(ans.equals("Y")) l = Math.max(l, x+1);
				else r = Math.min(r, x);
			}
			else if(a.equals("<")){
				if(ans.equals("Y")) r = Math.min(r, x-1);
				else l = Math.max(l, x);
			}
			else if(a.equals(">=")){
				if(ans.equals("Y")) l = Math.max(l, x);
				else r = Math.min(r, x-1);
			} else if(a.equals("<=")){
				if(ans.equals("Y")) r = Math.min(r, x);
				else l = Math.max(l, x+1);
			}
		}
		if(r < l){
			out.println("Impossible");
			return;
		}
		out.println(l);
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