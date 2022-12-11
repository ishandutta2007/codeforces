import java.util.*;
import java.io.*;

public class _0035_D_Animals {

	public static void main(String[] args) throws IOException, FileNotFoundException {
//		br = new BufferedReader(new InputStreamReader(System.in));
//		pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
				br = new BufferedReader(new FileReader("input.txt"));
				pr = new PrintWriter(new FileWriter("output.txt"));
		int N = readInt(), K = readInt();
		int dp[] = new int[K+1];
		for(int i = 1; i<=N; i++) {
			int wt = readInt()*(N-i+1);
			for(int j = K; j>=wt; j--) {
				dp[j] = Math.max(dp[j], dp[j-wt]+1);
			}
		}
		println(dp[K]);
		exit();
	}

	static BufferedReader br;
	static PrintWriter pr;
	static StringTokenizer st;

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		br.close();
		pr.close();
		System.exit(0);
	}

}