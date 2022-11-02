import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionC{

	public static void main(String[] args){
		new SolutionC().run();
	}
	int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
	TreeMap < Pair, Integer> tm;
	Pair el[];
	int sz = 0;
	void add(Pair a){
		if(tm.containsKey(a)) return;
		tm.put(a, sz);
		el[sz] = a;
		sz++;
	}
	boolean contains(Pair x){
		if(tm.containsKey(x)) return true;
		return false;
	}
	int getPos(Pair x){
		return tm.get(x);
	}
	long d[];
	void solve(){
		Pair x0 = new Pair(in.nextInt(), in.nextInt());
		Pair x1 = new Pair(in.nextInt(), in.nextInt());
		el = new Pair[200100];
		tm = new TreeMap<Pair, Integer>();
		int n = in.nextInt();
		for(int i = 0; i < n; i++){
			int r = in.nextInt();
			int a = in.nextInt();
			int b = in.nextInt();
			while(a <= b){
				add(new Pair(r, a));
				a++;
			}
		}
		if(!contains(x0) ||!contains(x1) ){
			out.println(-1);
			return;
		}
		
		d = new long[sz];
		for(int i = 0; i < sz; i++){
			d[i] = Integer.MAX_VALUE;
		}
		d[getPos(x0)] = 0;
		PriorityQueue<Pair> pr = new PriorityQueue<Pair>();
		pr.add(new Pair(d[getPos(x0)], getPos(x0)));
		
		while(!pr.isEmpty()){
			Pair x = pr.peek();
			pr.remove();
			int pos = (int)x.y;
			if(d[pos] < x.x) continue;
			for(int i = 0; i < 8; i++){
				Pair t = new Pair(el[pos].x + dx[i], el[pos].y + dy[i]);
				if(contains(t)){
					int posx = getPos(t);
					if(d[posx] > d[pos] + 1){
						d[posx] = d[pos] + 1;
						pr.add(new Pair(d[posx], posx));
					}
				}
			}
		}
		if(d[getPos(x1)] == Integer.MAX_VALUE){
			out.println(-1);
		}
		else out.println(d[getPos(x1)]);
	}



	class Pair implements Comparable<Pair>{
		long x, y;
		Pair(long x, long y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Long) y).compareTo(o.y); 
			return ((Long) x).compareTo(o.x);
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