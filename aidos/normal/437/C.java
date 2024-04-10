import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB{

	public static void main(String[] args){
		new SolutionB().run();
	}
	Pair p[];
	ArrayList<Integer> arr[];
	int a[];
	boolean used[];
	void solve(){
		int n, m;
		n = in.nextInt();
		m = in.nextInt();
		arr = new ArrayList[n];
		used = new boolean[n];
		p = new Pair[n];
		a = new int[n];
		for(int i=0; i < n; i++){
			p[i] = new Pair(in.nextInt(), i);
			a[i] = p[i].x;
		}
		Arrays.sort(p);
		for(int i = 0; i < n; i++)
			arr[i] = new ArrayList<Integer>();
		for(int i = 0, x, y; i < m; i++){
			x = in.nextInt()-1;
			y = in.nextInt()-1;
			arr[x].add(y);
			arr[y].add(x);
		}
		long ans = 0;
		for(int i = n-1; i>0; i--){
			int x = p[i].y;
			for(int y: arr[x]){
				if(!used[y]) ans += a[y]; 
			}
			used[x] = true;
		}
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
	}
}