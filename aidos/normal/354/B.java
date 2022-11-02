import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}
	char c[][];
	boolean used[][];
	int dp[][];
	int sub[][];
	ArrayList <Integer> arr[];
	int n;
	int getC(int i){
		if(i == 'a') return 1;
		if(i == 'b') return -1;
		return 0;
	}
	int go(int pos, int set){
		if(used[pos][set]) return dp[pos][set];
		used[pos][set] = true;
		if(pos == 2 * n - 2) {
			return dp[pos][set] = 0;
		}
		int pr = 0;
		int xx[] = new int[27];
		for(int i = 0; i < arr[pos].size(); i++){
			int r = arr[pos].get(i);
			int x = r/n;
			int y = r % n;
			if(((1 << i) & set) > 0){
				if(y + 1 < n) {
					xx[c[x][y+1] - 'a'] |= (1 << pr);
				}
				if( x + 1 < n){
					if( y + 1 < n)
						xx[c[x+1][y] - 'a'] |= (1 << (pr+1));
					else xx[c[x+1][y] - 'a'] |= (1 << pr);
				}
			}
			if(y + 1 < n) pr++;
		}
		int res = Integer.MIN_VALUE/2;
		if(pos % 2 == 0) res = Integer.MAX_VALUE/2;
		for(int i = 0; i < 26; i++){
			if(xx[i] == 0) continue;
			if(pos % 2 == 0){
				res = Math.min(res, getC(i + 'a') + go(pos+1, xx[i]));
			}
			else res = Math.max(res, getC(i + 'a') + go(pos+1, xx[i]));
		}
		return dp[pos][set] = res;
	}
	void solve() {
		n = in.nextInt();
		c = new char[n][];
		for(int i = 0; i < n; i++){
			c[i] = in.next().toCharArray();
		}
		arr = new ArrayList[n * 2];
		for(int i = 0;  i < n * 2; i++)
			arr[i] = new ArrayList<Integer>();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				arr[i + j].add(i * n + j);
		}
		used = new boolean[n * 2][(1 << n)];
		dp = new int[n*2][1 << n];
		int g = go(0, 1) + getC(c[0][0]);
		if( g > 0)
			out.println("FIRST");
		else if( g < 0) out.println("SECOND");
		else out.println("DRAW");
	}

	class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
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