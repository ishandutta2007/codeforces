import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	boolean cango(int a, int b, int x, int y){
		if(a == 0 && b == 0) return true;
		if(x == 0){
			return y !=0 && a == 0 && Math.abs(b) % Math.abs(y) == 0 && b/y >= 0;
		}
		if(Math.abs(a) % Math.abs(x) != 0) return false;
		if(y == 0) 
			return b==0 && a/x > 0;
		
		if(Math.abs(b) % Math.abs(y) == 0 &&  a / x ==b/y && a/x > 0) return true;
		
		return false;
	}
	void solve(){
		int a = in.nextInt();
		int b = in.nextInt();
		char c[] = in.next().toCharArray();
		if(a == 0 && b == 0) {
			out.println("Yes");
			return;
		}
		int n = c.length;
		int x = 0;
		int y = 0;
		for(int i = 0; i < n; i++){
			if(c[i] == 'U') y++;
			if(c[i] == 'D') y--;
			if(c[i] == 'L') x--;
			if(c[i] == 'R') x++;
		}
		int X = x;
		int Y = y;
		x = 0;
		y = 0;
		for(int i = 0; i < n; i++){

			if(c[i] == 'U') y++;
			if(c[i] == 'D') y--;
			if(c[i] == 'L') x--;
			if(c[i] == 'R') x++;
			int cura = a - x;
			int curb = b - y;
			if(cango(cura, curb, X, Y)){
				out.println("Yes");
				return;
			}
		}
		out.println("No");
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