import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	void solve(){
		int t = in.nextInt();
		int x[] = new int[t];
		int y[] = new int[t];
		int z[] = new int[t];
		String a[] = new String[t];
		for(int i = 0; i < t; i++){
			int k = in.nextInt();
			a[i] = in.next();
			for(int j = 0; j < k; j++){
				int ty = 1;
				char f[] = in.next().toCharArray();
				char g = f[0];
				for(int d = 0; d < f.length; d++){
					if(f[d] == '-') continue;
					if(f[d] != g) ty = 0;
				}
				if(ty == 0){
					g++;
					ty=2;
					for(int d = 0; d < f.length; d++){
						if(f[d] == '-') continue;
						if(f[d] >= g) ty = 0;
						g = f[d];
					}
				}
				if(ty == 0) x[i]++;
				else if(ty == 1) y[i]++;
				else z[i]++;
			}
		}
		int mi = 0;
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < t; i++){
			mi = Math.max(y[i], mi);
		}
		for(int i = 0; i < t; i++){
			if(y[i] == mi){
				if(sb.length() == 0) sb.append(a[i]);
				else sb.append(", " + a[i]);
			}
		}
		out.println("If you want to call a taxi, you should call: " + sb.toString() + ".");
		mi = 0;
		sb = new StringBuilder();
		for(int i = 0; i < t; i++){
			mi = Math.max(z[i], mi);
		}
		for(int i = 0; i < t; i++){
			if(z[i] == mi){
				if(sb.length() == 0) sb.append(a[i]);
				else sb.append(", " + a[i]);
			}
		}
		out.println("If you want to order a pizza, you should call: " + sb.toString() + ".");

		mi = 0;
		sb = new StringBuilder();
		for(int i = 0; i < t; i++){
			mi = Math.max(x[i], mi);
		}
		for(int i = 0; i < t; i++){
			if(x[i] == mi){
				if(sb.length() == 0) sb.append(a[i]);
				else sb.append(", " + a[i]);
			}
		}
		out.println("If you want to go to a cafe with a wonderful girl, you should call: " + sb.toString() + ".");
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