import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	char c[] = {'E', 'S', 'W','N'};
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, -1, 0, 1};
	int cnt[];
	boolean check(int d1, int d2){
		if(d1 < 0 && cnt[2]  < Math.abs(d1)) return false;
		if(d1 > 0 && cnt[0] < d1) return false;
		if(d2 < 0 && cnt[1]  < Math.abs(d2)) return false;
		if(d2 > 0 && cnt[3] < d2) return false;
		return true;
	}
 	
	void solve(){
		int t = in.nextInt();
		Pair p1 = new Pair(in.nextInt(), in.nextInt());
		Pair p2 = new Pair(in.nextInt(), in.nextInt());
		int dif1 = p2.x - p1.x;
		int dif2 = p2.y - p1.y;
		char x[] = in.next().toCharArray();
		cnt = new int[4];
		if(p1.compareTo(p2) == 0){
			out.println(0);
			return;
		}
		for(int i = 0; i < t; i++){
			int j = 0;
			while(c[j] != x[i]) j++;
			cnt[j]++;
			if(check(dif1, dif2)){
				out.println(i+1);
				return;
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