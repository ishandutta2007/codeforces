import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionC{

	public static void main(String[] args){
		new SolutionC().run();
	}
	int m, t, r;
	int w[];
	TreeSet <Integer> ts = new TreeSet<Integer>();
	int go(int cur){
		if(cur == -1) return 0;
		int last = w[cur] - t;
		TreeSet <Integer> ts2 = new TreeSet<Integer>();
		for(int x: ts){
			if(x < w[cur]) ts2.add(x);
		}
		ts = ts2;
		int cnt = 0;
		while(ts.size() < r && last < w[cur]) {
			if(!ts.contains(last)){
				ts.add(last);
				cnt++;
			}
			last++;
		}
		if(ts.size() < r) return Integer.MAX_VALUE/1000;
		return go(cur-1) + cnt;
	}
	void solve(){
		m = in.nextInt();
		t = in.nextInt();
		r = in.nextInt();
		w = new int[m];
		for(int i = 0; i < m; i++)
			w[i] = in.nextInt();
		Arrays.sort(w);
		if(t < r){
			out.println(-1);
			return;
		}
		int ans = go(m-1);
		if(ans >= 100000) ans = -1;
		out.println(ans);
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
			bf = new BufferedReader(new InputStreamReader(is), 32768);
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