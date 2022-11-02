import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}

	int n;
	int m;
	ArrayList<Integer> arr[], arr2[], arrx;
	int col[];
	boolean flag;
	void dfs(int v){
		col[v] = 1;
		arrx.add(v);
		for(int t:arr2[v]){
			if(col[t] == 0){
				dfs(t);
			}
		}
	}
	void dfs2(int v){
		if(flag) return;
		col[v] = 2;
		for(int t: arr[v]){
			if(col[t] == 2){
				flag = true;
				return;
			}
			if(col[t] == 1) dfs2(t);
		}
		col[v] = 3;
	}
	void solve() {
		n = in.nextInt();
		m = in.nextInt();
		arr = new ArrayList[n];
		arr2 = new ArrayList[n];
		col = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = new ArrayList<Integer>();
			arr2[i] = new ArrayList<Integer>();
		}
		for(int i = 0;  i<m; i++){
			int x = in.nextInt()-1;
			int y = in.nextInt()-1;
			arr[x].add(y);
			arr2[x].add(y);
			arr2[y].add(x);
		}
		arrx = new ArrayList<Integer>();
		long ans =0;
		for(int i = 0; i < n; i++){
			if(col[i] == 0) {
				arrx.clear();
				dfs(i);
				flag = false;
				ans += arrx.size();
				for(int t: arrx){
					if(col[t] == 1) dfs2(t);
				}
				if(!flag) ans--;
			}
		}
		out.println(ans);
	}

	class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = y;
			this.y = x;
		}

		@Override
		public int compareTo(Pair o) {
			if (o.x == x)
				return ((Integer) y).compareTo(o.y);
			return ((Integer) x).compareTo(o.x);
		}

	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(new OutputStreamWriter(System.out));
		solve();
		out.close();
	}

	void runIO() {
		try {
			in = new FastScanner(new File("expr.in"));
			out = new PrintWriter(new FileWriter(new File("expr.out")));
			solve();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader bf;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				bf = new BufferedReader(new FileReader(f));
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

		public FastScanner(InputStream is) {
			bf = new BufferedReader(new InputStreamReader(is), 32768);
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(bf.readLine());
				} catch (IOException ex) {
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		String nextLine() {
			try {
				return bf.readLine();
			} catch (Exception ex) {
				ex.printStackTrace();
			}
			return "";
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(next());
		}

		BigDecimal nextBigDecimal() {
			return new BigDecimal(next());
		}

		int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = Integer.parseInt(next());
			return a;
		}

		long[] nextLongArray(int n) {
			long a[] = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = Long.parseLong(next());
			return a;
		}
	}
}