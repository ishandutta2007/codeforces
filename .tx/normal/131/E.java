import java.io.*;
import java.util.*;

public class TaskE {
	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return "-1";
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}

	final int inf = (int) (1e9);

	void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		int[] col = new int[n], row = new int[n], diag1 = new int[2 * n - 1], diag2 = new int[2 * n - 1];
		int[] datax = new int[m], datay = new int[m];
		int[] colmin = new int[n], colmax = new int[n];
		int[] rowmin = new int[n], rowmax = new int[n];
		int[] diag1min = new int[2 * n - 1], diag1max = new int[2 * n - 1];
		int[] diag2min = new int[2 * n - 1], diag2max = new int[2 * n - 1];
		for (int i = 0; i < n; i++) {
			colmin[i] = inf;
			rowmin[i] = inf;
			colmax[i] = -inf;
			rowmax[i] = -inf;
		}
		for (int i = 0; i < 2 * n - 1; i++) {
			diag1min[i] = inf;
			diag2min[i] = inf;
			diag1max[i] = -inf;
			diag2max[i] = -inf;
		}
		int x, y, d1, d2;
		for (int i = 0; i < m; i++) {
			x = nextInt() - 1;
			y = nextInt() - 1;
			d1 = x - y + n - 1;
			d2 = x - (n - 1 - y) + n - 1;
			datax[i] = x;
			datay[i] = y;
			row[x]++;
			col[y]++;
			diag1[x - y + n - 1]++;
			diag2[x - (n - 1 - y) + n - 1]++;
			if (rowmin[x] > y) {
				rowmin[x] = y;
			}
			if (rowmax[x] < y) {
				rowmax[x] = y;
			}
			if (colmin[y] > x) {
				colmin[y] = x;
			}
			if (colmax[y] < x) {
				colmax[y] = x;
			}
			if (diag1min[d1] > x) {
				diag1min[d1] = x;
			}
			if (diag1max[d1] < x) {
				diag1max[d1] = x;
			}
			if (diag2min[d2] > x) {
				diag2min[d2] = x;
			}
			if (diag2max[d2] < x) {
				diag2max[d2] = x;
			}
		}
		int[] ans = new int[9];
		int t;
		for (int i = 0; i < m; i++) {
			x = datax[i];
			y = datay[i];
			d1 = x - y + n - 1;
			d2 = x - (n - 1 - y) + n - 1;
			t = 8;
			if (rowmax[x] == y) {
				t--;
			}
			if (rowmin[x] == y) {
				t--;
			}
			if (colmax[y] == x) {
				t--;
			}
			if (colmin[y] == x) {
				t--;
			}
			if (diag1max[d1] == x) {
				t--;
			}
			if (diag1min[d1] == x) {
				t--;
			}
			if (diag2max[d2] == x) {
				t--;
			}
			if (diag2min[d2] == x) {
				t--;
			}
			ans[t]++;
		}
		for (int i = 0; i < 9; i++) {
			out.print(ans[i]);
			out.print(' ');
		}
	}

	void run() throws IOException {
		// br = new BufferedReader(new FileReader("taske.in"));
		// out = new PrintWriter("taske.out");
		// br = new BufferedReader(new FileReader("input.txt"));
		// out = new PrintWriter("output.txt");
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Locale.setDefault(Locale.US);
		new TaskE().run();
	}
}