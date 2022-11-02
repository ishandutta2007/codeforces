import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	
	boolean ok(char x[], char y[], char z[]){
		int pos = -1;
		int n = x.length;
		int m = y.length;
		int k = z.length;
		for(int i = 0; i+m <= n && pos == -1; i++){
			pos = i;
			for(int j = 0; j < m && pos != -1; j++){
				if(x[i + j] != y[j]) pos=-1;
			}
		}
		if(pos == -1) return false;
		int pos2 = -1;
		for(int i = pos + m; i+k <= n && pos2 == -1; i++){
			pos2 = i;
			for(int j = 0; j < k && pos2 != -1; j++){
				if(x[i + j] != z[j]) pos2=-1;
			}
		}
		return pos2 != -1;
	}
	
	void solve(){
		char a[] = in.next().toCharArray();
		char b[] = new char[a.length];
		for(int i = 0; i < a.length; i++)
			b[i] = a[a.length-i - 1];
		char x[] = in.next().toCharArray();
		char y[] = in.next().toCharArray();
		if(ok(a, x, y)){
			if(ok(b, x, y)){
				out.println("both");
			}
			else out.println("forward");
		}
		else if(ok(b, x, y)){
			out.println("backward");
		}
		else {
			out.println("fantasy");
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