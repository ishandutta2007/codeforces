	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionB{
	
		public static void main(String[] args){
			new SolutionB().run();
		}
		int dx[] = {1, 0, 0, -1};
		int dy[] = {0, 1, -1, 0};
		int n, m, k;
		char c[][];
		boolean used[][];
		void dfs(int x, int y){
			if(k == 0) return;
			if(x < 0 || x >= n || y < 0 || y >= m || used[x][y] || c[x][y] == '#' ) return;
			k--;
			used[x][y] = true;
			for(int i = 0; i < 4; i++){
				dfs(x + dx[i], y+dy[i]);
			}			
		}
		void solve(){
			n = in.nextInt();
			m = in.nextInt();
			k = in.nextInt();
			used = new boolean[n][m];
			c = new char[n][];
			for(int i = 0; i < n; i++){
				c[i] = in.next().toCharArray();
				for(int j = 0; j < m; j++) if(c[i][j] == '.') k--;
			}
			k *= -1;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(c[i][j] == '.'){
						dfs(i, j);
						break;
					}
				}
			}
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(!used[i][j] && c[i][j] == '.') c[i][j] = 'X';
			for(int i = 0; i < n; i++){
				out.println(c[i]);
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
		}
	}