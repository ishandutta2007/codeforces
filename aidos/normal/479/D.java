	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionD{
	
		public static void main(String[] args){
			new SolutionD().run();
		}
		TreeSet <Integer> ts;
		int a[];
		int n;
		boolean con(int x){
			for(int i = 0; i < n; i++){
				if(ts.contains(a[i] - x)) return true;
			}
			return false;
		}
		void solve(){
			n = in.nextInt();
			int l = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			ts = new TreeSet<Integer>();
			a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = in.nextInt();
				ts.add(a[i]);
			}
			boolean ok1 = con(x), ok2 = con(y);
			if(ok1 && ok2) out.println(0);
			else if(ok1) out.println("1\n" + y);
			else if(ok2) out.println("1\n" + x);
			else {
				for(int i = 0; i < n; i++){
					if(ts.contains(a[i] - x - y)){
						out.println("1\n" + (a[i] - x));
						return;
					}
					if(a[i] + x <= l && ts.contains(a[i] + x - y)){
						out.println("1\n" + (a[i] + x));
						return;
					}
					if(a[i] - x >= 0 && ts.contains(a[i] + y - x)){
						out.println("1\n" + (a[i] - x));
						return;
					}
				}
				out.println("2\n" + x + " " + y);
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