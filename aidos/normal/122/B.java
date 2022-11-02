	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionB{
	
		public static void main(String[] args){
			new SolutionB().run();
		}
		int dp[];
		void solve(){
			char c[] = in.next().toCharArray();
			int n = c.length;
			dp = new int[10];
			for(int i=0; i<n; i++) dp[c[i] - '0']++;
			int ans = -1;
			if(dp[7] > dp[4]) ans = 7;
			else if(dp[4]>0) ans = 4;
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