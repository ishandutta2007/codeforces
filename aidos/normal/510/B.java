import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {
	public static void main(String[] args) {
		new SolutionB().run();
	}
	int n;
	int m;
	char c[][];
	int used[][];
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, -1, 0, 1};
	int ti = 1;
	boolean flag = false;
	void dfs(int x, int y, int prx, int pry){
		used[x][y] = ti;
		ti++;
		for(int i = 0; i < 4; i++){
			int X = (dx[i] + x);
			int Y = (dy[i] + y);
			if(X < 0 || Y < 0 || Y >= m || X >= n || prx == X && pry == Y) continue;
			if(c[x][y] != c[X][Y]) continue;
			if(used[X][Y] == 0) dfs(X, Y, x, y);
			else if(used[X][Y] > 0 && used[x][y] - used[X][Y] >= 3) flag = true; 
		}
		used[x][y] = -1;
	}
	void solve(){
		n = in.nextInt();
		m = in.nextInt();
		c = new char[n][m];
		for(int i = 0; i < n; i++)
			c[i] = in.next().toCharArray();
		used = new int[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(used[i][j] == 0) dfs(i, j, i, j);
		if(flag) out.println("Yes");
		else out.println("No");
	}
	FastScanner in;
	PrintWriter out;
	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader bf;

		public FastScanner(InputStream is) {
			bf = new BufferedReader(new InputStreamReader(is));
		}

		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(Exception ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		short nextShort(){
			return Short.parseShort(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; ++i)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = Long.parseLong(next());
			return a;
		}
	}

}