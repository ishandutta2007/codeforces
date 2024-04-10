import java.util.*;
import java.io.*;

public class TaskC implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() {
		while (stok == null || !stok.hasMoreTokens()) {
			try {
				stok = new StringTokenizer(in.readLine());
			} catch (Exception e) {
				return null;
			}
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

	boolean[] solved;
	int[][] a;
	int[] w;
	int n;

	boolean canSolve(int x) {
		int[] t = a[x];
		for (int i = 0; i < t.length; i++) {
			if (!solved[t[i]]) {
				return false;
			}
		}
		return true;
	}

	int begin(int x) {
		int kol = 0, res = 0, i;
		boolean fl;
		Arrays.fill(solved, false);
		while (kol < n) {
			fl = true;
			while (fl) {
				fl = false;
				for (i = 0; i < n; i++) {
					if (!solved[i] && w[i] == x && canSolve(i)) {
						res++;
						kol++;
						solved[i] = true;
						fl = true;
					}
				}
			}
			if (kol != n) {
				res++;
			}
			x = (x + 1) % 3;
		}
		return res;
	}

	void solve() throws IOException {
		n = nextInt();
		w = new int[n];
		a = new int[n][];
		solved = new boolean[n];
		for (int i = 0; i < n; i++) {
			w[i] = nextInt() - 1;
		}
		int x;
		for (int i = 0; i < n; i++) {
			x = nextInt();
			a[i] = new int[x];
			for (int g = 0; g < x; g++) {
				a[i][g] = nextInt() - 1;
			}
		}
		int b0 = begin(0);
		int b1 = begin(1);
		int b2 = begin(2);
		out.println(Math.min(Math.min(b0, b1), b2));
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

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {
		}
		new Thread(new TaskC()).run();
	}
}//lrjask