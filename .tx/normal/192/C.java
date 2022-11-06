import java.io.*;
import java.util.*;

public class TaskC implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() {
		try {
			while (stok == null || !stok.hasMoreTokens()) {
				stok = new StringTokenizer(in.readLine());
			}
		} catch (Exception e) {
			return null;
		}
		return stok.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	int f(char c) {
		return (int) (c - 'a');
	}

	void solve() throws IOException {
		int n = nextInt();
		int[][] d = new int[26][26];
		String s;
		for (int i = 0; i < n; i++) {
			s = nextToken();
			for (int g = 0; g < 26; g++) {
				if (d[g][f(s.charAt(0))] > 0) {
					d[g][f(s.charAt(s.length() - 1))] = Math.max(
							d[g][f(s.charAt(s.length() - 1))],
							d[g][f(s.charAt(0))] + s.length());
				}
			}
			d[f(s.charAt(0))][f(s.charAt(s.length() - 1))] = Math.max(
					d[f(s.charAt(0))][f(s.charAt(s.length() - 1))], s.length());
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans = Math.max(ans, d[i][i]);
		}
		out.println(ans);
	}

	public void run() {
		try {
			try {
				in = new BufferedReader(new FileReader("taskc.in"));
				out = new PrintWriter("taskc.out");
			} catch (Exception e1) {
				try {
					in = new BufferedReader(new FileReader("input.txt"));
					out = new PrintWriter("output.txt");
				} catch (Exception e2) {
					in = new BufferedReader(new InputStreamReader(System.in));
					out = new PrintWriter(System.out);
				}
			}
			solve();
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) throws IOException {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {
		}
		new Thread(new TaskC()).start();
	}
}//ojivut