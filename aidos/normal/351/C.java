import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}
	int n, m;
	int c[], d[];
	void solve() {
		n = in.nextInt();
		m = in.nextInt();
		c = in.nextIntArray(n);
		d = in.nextIntArray(n);
		Matrix st = new Matrix(50);
		for(int i = 0; i < n; i++){
			Matrix fi = new Matrix(50);
			for(int j = 0; j<50; j++)
				fi.a[j][j] = Integer.MAX_VALUE; 
			for(int j = 0; j<49; j++){
				fi.a[j+1][j] = d[i];
				fi.a[j][j+1] = c[i];
			}
			st = st.mul(fi);
		}
		out.println(st.pow(m).a[0][0]);
	}
	
	
	class Matrix{
		int n;
		long a[][];
		public Matrix(){
			a = new long[2][2];
		}
		public Matrix(int n){
			this.n = n;
			a=new long[n][n];
			for(int i = 0; i < n; i++){
				for(int j=0; j < n; j++){
					if(i == j) a[i][j] = 0;
					else a[i][j] = Integer.MAX_VALUE;
				}
			}
		}
		Matrix mul(Matrix x){
			Matrix t = new Matrix(n);
			for(int i = 0; i < n; i++)
				for(int j = 0;j < n; j++){
					t.a[i][j] = Integer.MAX_VALUE;
					for(int k = 0; k < n; k++){
						t.a[i][j] = Math.min(t.a[i][j], a[i][k] + x.a[k][j]);
					}
				}
			return t;
		}
		Matrix pow(int x){

			if(x == 0) {
				Matrix t = new Matrix(n);
				return t;
			}
			if(x % 2 == 0){
				return this.mul(this).pow(x/2);
			}
			return this.mul(this.pow(x-1));
		}
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