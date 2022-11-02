	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionD{
	
		public static void main(String[] args){
			new SolutionD().run();
		}
		ArrayList<Pair> get(int n){
			ArrayList<Pair> arr = new ArrayList<Pair>();
			for(int i = -1000; i<=1000; i++){
				if( i == 0) continue;
				for(int j = -1000; j <= 1000; j++){
					int x = i * i + j * j;
					double td = Math.sqrt(x);
					int ti = (int) td;
					if(td - ti < 1e-9 && ti == n){
						arr.add(new Pair(i, j));
					}
				}
			}
			return arr;
		}
		void solve(){
			int n = in.nextInt();
			int m = in.nextInt();
			ArrayList<Pair> arr = get(n), arr2 = get(m);
			for(Pair t:arr){
				for(Pair d: arr2){
					int a1 = (t.x - d.x)*(t.x - d.x) + (t.y - d.y) * (t.y - d.y);
					int a2 = t.x * t.x + t.y * t.y;
					int a3 = d.x * d.x + d.y * d.y;
					if(a2 + a3 == a1 && t.x != d.x && t.y != d.y){
						out.println( "YES\n0 0\n" + t.x + " " + t.y + "\n" + d.x + " " + d.y);
						return;
					}
				}
			}
			out.println("NO");
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