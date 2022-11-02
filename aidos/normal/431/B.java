import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int a[][] = new int[5][5];
	boolean used[] = new boolean[5];
	int x[] = new int[5];
	int ans = 0;
	void dfs(int pos){
		if(pos == 5){
			int cnt = 0;
			for(int i = 0; i<5; i++){
				for(int j = i+1; j < 5; j+=2){
		            cnt += a[x[j]][x[j-1]];
		            cnt += a[x[j-1]][x[j]];
				}
			}
			if(ans < cnt) ans = cnt;
			return;
		}
		for(int i = 0; i < 5; i++){
			if(!used[i]){
				used[i] = true;
				x[pos] = i;
				dfs(pos+1);
				used[i] = false;
			}
		}
	}
	void solve(){
		for(int i = 0; i < 5; i++)
			for(int j = 0; j<5; j++)
				a[i][j] = in.nextInt();
		dfs(0);
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