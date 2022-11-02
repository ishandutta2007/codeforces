import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}
	int mod = 1000000007;
	int [][] mul(int a[][], int b[][]){
		int c[][] = new int[2][2];
		for(int i = 0; i < 2;i++)
			for(int j = 0; j < 2; j++){
				c[i][j] = 0;
				for(int k = 0; k < 2; k++){
					long x = a[i][k];
					x *= b[k][j];
					c[i][j] +=(int)( x % mod);
					c[i][j] %= mod;
				}
			}
		return c;
	}
	int [][] pow(int t[][], long n){
		if( n == 0){
			int a[][] = new int[2][2];
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					if( i == j) a[i][j] = 1;
					else a[i][j] = 0;
				}
			}
			return a;
		}
		if(n % 2==1) return mul(pow(t, n-1), t);
		int a[][] = pow(t, n/2);
		return mul(a, a);
	}
	void solve() {
		int a[][] = new int[2][2];
		a[0][0] = 3;
		a[1][0] = 1;
		a[0][1] = 1;
		a[1][1] = 3;
		long n = in.nextLong();
		int b[][] = pow(a, n);
		out.println(b[0][0]);
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