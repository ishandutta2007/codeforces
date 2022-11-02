import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n, m;
	int a[];
	String b[];
	void solve(){
		a = new int[4];
		b = new String[4];
		for(int i = 0; i < 4; i++){
			b[i] = in.next();
			a[i] = b[i].length()-2;
		}
		Arrays.sort(a);
		if(a[0] * 2 <= a[1]){
			if(a[3] >= a[2] * 2){
				out.print('C');
			}
			else {
				for(int i = 0; i < 4; i++){
					if(b[i].length() == a[0] + 2){
						out.print((char)('A' + i));
					}
				}
			}
		}
		else if(a[3] >= a[2] * 2){
			for(int i = 0; i < 4; i++){
				if(b[i].length() == a[3] + 2){
					out.print((char)('A' + i));
				}
			}
		}
		else {
			out.print('C');
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