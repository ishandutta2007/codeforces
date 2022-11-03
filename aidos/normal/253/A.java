import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().runIO();
	}
	int n, m;
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		StringBuilder sb = new StringBuilder();
		if(n < m){
			sb.append('G');
			m--;
		}
		int f = 0;
		while(n > 0 || m > 0){
			if(f == 0 && n > 0){
				sb.append('B');
				n--;
			}
			else if(m > 0){
				sb.append('G');
				m--;
			}
			f = 1-f;
		}
		out.println(sb.toString());
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
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new FileWriter(new File("output.txt")));
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