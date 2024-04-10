	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionD{
	
		public static void main(String[] args){
			new SolutionD().run();
		}
		int is_p[][];
		int d[];
		int n;
		char c[];
		int go(int x, int y){
			if(x > y) return 1;
			if(is_p[x][y] != -1) return is_p[x][y];
			is_p[x][y] = go(x+1, y-1);
			if(c[x] != c[y]) is_p[x][y] = 0;
			return is_p[x][y];
		}
		void solve(){
			c = in.next().toCharArray();
			n = c.length;
			d = new int[n+1];
			is_p = new int[n][n];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++)
					is_p[i][j] = -1;
			}
			for(int i = n-1; i>=0; i--){
				for(int j = i; j<n; j++)
					d[i] += go(i, j);
				d[i] += d[i+1];
			}
			long ans = 0;
			for(int i = 0; i < n; i++)
				for(int j = i; j < n; j++){
					if(go(i, j) == 1) ans += d[j+1];
				}
			out.println(ans);
		}
	
	
	
		class Pair implements Comparable<Pair>{
			int x, y;
			Pair(int x, int y){
				this.x = y;
				this.y = x;
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