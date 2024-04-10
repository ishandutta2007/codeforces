import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n, m;
	int p[];
	boolean used[];
	ArrayList<ArrayList<Integer> > go(int pos){
		ArrayList<ArrayList<Integer> > arr = new ArrayList<ArrayList<Integer>>();
		if(pos == 4){
			arr.add(new ArrayList<Integer>());
			return arr;
		}
		for(int i = 0; i < 4; i++){
			if(!used[i]) {
				used[i] = true;
				ArrayList<ArrayList<Integer>> arrx = go(pos + 1);
				for(int j = 0; j < arrx.size(); j++){
					arrx.get(j).add(i);
					arr.add(arrx.get(j));
				}
				used[i] = false;
			}
		}
		return arr;
	}
	void solve(){
		used = new boolean[4];
		ArrayList<ArrayList<Integer>> arr = go(0);
		p = new int[4];
		for(int i = 0; i < 4; i++)
			p[i] = in.nextInt();
		int a= in.nextInt();
		int b= in.nextInt();
		int ans=0;
		for(int i = a; i <= b; i++){
			int cnt = 0;
			for(ArrayList<Integer> t: arr){
				int x = i;
				for(int y: t){
					x %= p[y];
				}
				if(x == i) cnt++;
			}
			if(cnt >= 7) ans++;
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