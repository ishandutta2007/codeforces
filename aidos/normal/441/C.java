import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionC{

	public static void main(String[] args){
		new SolutionC().run();
	}
	int n, m, k;
	ArrayList<ArrayList<Pair> > arr;
	boolean used[][];
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		arr = new ArrayList<ArrayList<Pair>>();
		int x = 0;
		int y = 0;
		int dir = 0;
		for(int i = 1; i < k; i++){
			ArrayList<Pair> arr2 = new ArrayList<Pair>();
			arr2.add(new Pair(x+1, y+1));
			if(dir == 0){
				if(y + 1 < m){
					arr2.add(new Pair(x+1, y+2));
					y += 2;
					if( y == m){
						y = m-1;
						x++;
						dir = 1;
					}
				}
				else {
					arr2.add(new Pair(x + 2, y + 1));
					x++;
					y--;
					dir = 1;
				}
			}
			else {
				if(y > 0){
					arr2.add(new Pair(x+1, y));
					y -= 2;
					if( y == -1){
						y = 0;
						x++;
						dir = 0;
					}
				}
				else {
					arr2.add(new Pair(x + 2, y + 1));
					x++;
					y++;
					dir = 0;
				}
			}
			arr.add(arr2);
		}
		ArrayList <Pair> arr3 = new ArrayList<Pair>();
		while(x < n){
			arr3.add(new Pair(x+1, y+1));
			if(dir == 0){
				y++;
				if(y == m){
					dir = 1;
					x++;
					y = m-1;
				}
			}
			else {
				y--;
				if( y == -1){
					y = 0;
					x++;
					dir = 0;
				}
			}
		}
		arr.add(arr3);
		for(ArrayList<Pair> d: arr){
			out.print(d.size() + " ");
			for(Pair t: d){
				out.print(t.x + " " + t.y + " ");
			}
			out.println();
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