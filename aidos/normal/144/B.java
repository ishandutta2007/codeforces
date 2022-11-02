import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}
	int x[], y[], r[];
	void solve() {
		int xa = in.nextInt();
		int ya = in.nextInt();
		int xb = in.nextInt();
		int yb = in.nextInt();
		TreeSet<Pair> ts = new TreeSet <Pair>();
		for(int i = Math.min(xa, xb); i <= Math.max(xa, xb); i++){
			ts.add(new Pair(i, ya));
			ts.add(new Pair(i, yb));
		}
		for(int i = Math.min(ya, yb); i <= Math.max(ya, yb); i++){
			ts.add(new Pair(xa, i));
			ts.add(new Pair(xb, i));
		}
		int n = in.nextInt();
		x = new int[n];
		y = new int[n];
		r = new int[n];
		for(int i =  0;i < n; i++){
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			r[i] = in.nextInt();
		}
		int ans = 0;
		for(Pair t: ts){
			boolean ok = false;
			for(int i = 0; i < n && !ok; i++){
				if((t.x - x[i]) * (t.x - x[i]) + (t.y - y[i]) * (t.y - y[i]) <= r[i] * r[i]){
					ok = true;
				}
			}
			if(!ok) ans++;
		}
		out.println(ans);
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
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new FileWriter(new File("output.txt")));
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