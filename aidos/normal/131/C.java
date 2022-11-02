	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionB{
	
		public static void main(String[] args){
			new SolutionB().run();
		}
		long c[][];
		void solve(){
			long ans = 0;
			int n = in.nextInt();
			int m = in.nextInt();
			int t = in.nextInt();
			c = new long [32][32];
			c[0][0] = 1;
			for(int i = 1; i < 32; i++){
				c[i][0] = 1;
				for(int j = 1; j < i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
				c[i][i] = 1;
			}
			for(int i = 4; i<= n; i++){
				if(t - i <= 0 || t - i > m) continue;
				ans += c[n][i] * 1L * c[m][t-i];
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