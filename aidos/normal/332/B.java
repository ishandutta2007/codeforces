import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}
	long d[];
	long sum[];
	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		sum = new long[n+1];
		d = new long[n+1];
		for(int i = 1; i <= n; i++){
			sum[i] = sum[i-1] + in.nextLong();
		}
		int a1 = 0;
		int a2 = k;
		for(int i=0; i<= n; i++){
			if(i >= k)
				d[i] = Math.max(d[i-1], sum[i] - sum[i-k]);
			else d[i] = 0;
		}
		for(int i = 2 * k; i <= n; i++){
			if(d[a1] + sum[a2] - sum[a2 - k] < sum[i] - sum[i-k] + d[i - k]){
				a1 = i - k;
				a2 = i;
			}
		}
		for(int i = k; i <= n; i++){
			if(d[i] == d[a1]){
				a1 = i;
				break;
			}
		}
		out.println((a1 - k + 1) + " " + (a2 - k + 1));
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