import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}
	char t[][];
	ArrayList<String> arr, arr2;
	int n;
	boolean check(String x){
		char c[]  = x.toCharArray();
		int m = c.length;
		for(int i =0; i < n; i++){
			for(int j = 0; j <=t[i].length - m; j++){
				boolean ok = true;
				for(int k = 0; k < m; k++)
					if(c[k] != t[i][j + k]) ok = false;
				if(ok) return false;
			}
		}
		return true;
	}
	boolean go(){

		for(String x: arr){
			for(char y = 'a'; y <= 'z'; y++){
				String k = x + y;
				if(check(k)){
					out.println(k);
					return true;
				}
				arr2.add(k);
			}
		}
		arr.clear();
		for(String x: arr2) arr.add(x);
		arr2.clear();
		
		return false;
	}
	void solve() {
		n = in.nextInt();
		t = new char[n][];
		for(int i = 0; i < n; i++) t[i] = in.next().toCharArray();
		arr = new ArrayList<String>();
		arr2 = new ArrayList<String>();

		arr.add("");
		if(!go()){
			if(!go()){
				go();
			}
		}
		//out.println("-1");
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