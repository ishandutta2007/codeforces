import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int r1, r2, c1,c2,d1,d2;
	int a[][];
	boolean check(){
		TreeSet<Integer> ts = new TreeSet<Integer>();
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				ts.add(a[i][j]);
		if(ts.size() != 4) return false;
		if(r1 != a[0][0] + a[0][1]) return false;
		if(r2 != a[1][0] + a[1][1]) return false;
		if(c1 != a[0][0] + a[1][0]) return false;
		if(c2 != a[0][1] + a[1][1]) return false;
		if(d1 != a[0][0] + a[1][1]) return false;
		if(d2 != a[0][1] + a[1][0]) return false;
		return true;
	}
	void solve(){
		r1 = in.nextInt();
		r2 = in.nextInt();
		c1 = in.nextInt();
		c2 = in.nextInt();
		d1 = in.nextInt();
		d2 = in.nextInt();
		a = new int[2][2];
		for(int i = 1;i<=9; i++){
			for(int j = 1; j <= 9; j++)
				for(int k =1; k <= 9; k++) 
					for(int t = 1; t <= 9; t++){
						a[0][0] = i;
						a[0][1] = j;
						a[1][0] = k;
						a[1][1] = t;
						if(check()){
							for(int y = 0; y < 2; y++){
								for(int h: a[y]){
									out.print(h + " ");
								}
								out.println();
							}
							return;
						}
					}
		}
		out.println(-1);
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