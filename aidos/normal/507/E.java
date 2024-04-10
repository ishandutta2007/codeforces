import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionE{

	public static void main(String[] args){
		new SolutionE().run();
	}
	Pair dp[];
	ArrayList<Integer> arr[];
	int x[], y[], z[];
	int from[];
	int dis[];
	int n, m;
	boolean used[];
	void solve(){
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		n = in.nextInt();
		m = in.nextInt();
		used = new boolean[m];
		arr = new ArrayList[n];
		dp = new Pair[n];
		from = new int[n];
		dis = new int[n];
		x = new int[m];
		y = new int[m];
		z = new int[m];
		for(int i = 0; i < n; i++){
			arr[i] = new ArrayList<Integer>();
			dp[i] = new Pair(Integer.MAX_VALUE/10, 0, i);
		}
		for(int i = 0; i < m; i++){
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			z[i] = 1 - in.nextInt();
			arr[x[i]].add(i);
			arr[y[i]].add(i);
		}
		dp[0] = new Pair(0, 0, 0);
		pq.add(dp[0]);
		from[0] = -1;
		while(!pq.isEmpty()){
			Pair d = pq.poll();
			if(d.compareTo(dp[d.id]) > 0) continue;
			int id = d.id;
			for(int t: arr[id]){
				int dd = x[t];
				if(x[t] == id) dd = y[t];
				Pair cur = new Pair(d.x + 1, z[t] + d.y, dd);
				if(dp[dd].compareTo(cur) > 0) {
					dp[dd] = cur;
					from[dd] = id;
					dis[dd] = t;
					pq.add(cur);
				}
			}
		}
		int xx = n-1;
		ArrayList<Pair> ans = new ArrayList<Pair>();
		while(xx > 0){
			int go = from[xx];
			used[dis[xx]] = true;
			xx = go;
		}
		for(int i = 0; i < m; i++){
			if(used[i]){
				if(z[i] == 1) ans.add(new Pair(x[i]+1, y[i] + 1, 1));
			}
			else {
				if(z[i] == 0) ans.add(new Pair(x[i]+1, y[i] + 1, 0));
			}
		}
		out.println(ans.size());
		for(Pair cur : ans){
			out.println(cur.x + " " + cur.y + " " + cur.id);
		}
	}



	class Pair implements Comparable<Pair>{
		int x, y, id;
		Pair(int x, int y, int id){
			this.x = x;
			this.y = y;
			this.id = id;
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