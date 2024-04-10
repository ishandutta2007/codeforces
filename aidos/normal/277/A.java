import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	boolean a[][], used[], b[][];
	int n;
	void dfs(int x){
		used[x] = true;
		for(int j = 0; j < n; j++){
			if(!used[j] && b[x][j]) dfs(j);
		}
	}
	void solve(){
		n = in.nextInt();
		int m = in.nextInt();
		a = new boolean[n][m];
		b = new boolean[n][n];
		used = new boolean[n];
		int cnt = 0;
		for(int i =0; i<n; i++){
			int k = in.nextInt();
			if(k == 0) {
				cnt++;
				used[i] = true;
			}
			for(int j = 0; j < k; j++){
				int x = in.nextInt() - 1;
				a[i][x] = true;
			}
		}
		int x = -1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				for(int k = 0; k < m; k++){
					if(a[i][k] && a[j][k]) b[i][j] = true; 
				}
			}
		for(int i=0; i < n; i++){
			if(!used[i]){
				x++;
				dfs(i);
			}
		}
		if(x < 0) x = 0;
		out.println(cnt + x);
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