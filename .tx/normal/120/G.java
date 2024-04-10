import java.io.*;
import java.util.*;

public class TaskG {
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
	
	void solve() throws IOException {
		int n = nextInt(), t = nextInt();
		int[][] a = new int[n][2], b = new int[n][2];
		for (int i = 0; i < n; i++) {
			a[i][0] = nextInt();
			b[i][0] = nextInt();
			a[i][1] = nextInt();
			b[i][1] = nextInt();
		}
		int m = nextInt();
		String[] words = new String[m];
		int[] c = new int[m];
		for (int i = 0; i < m; i++) {
			words[i] = nextToken();
			c[i] = nextInt();
		}
		int[][] d = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int g = 0; g < m; g++) {
				d[i][g] = 0;
			}
		}
		ArrayList<Integer>[] ans = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			ans[i] = new ArrayList<Integer>();
		}
		int i = 0, g = 0, v = 0, kol = 0, temp;
		boolean[] used = new boolean[m];
		Arrays.fill(used, false);
		while (kol < m) {
			temp = t;
			while (temp - Math.max(1, (c[v] - (a[i][g] + b[i][g == 0 ? 1 : 0]) - d[i][v])) >= 0) {
				temp -= Math.max(1, (c[v] - (a[i][g] + b[i][g == 0 ? 1 : 0]) - d[i][v]));
				ans[i].add(v);
				used[v] = true;
				kol++;
				if (kol == m) {
					break;
				}
				while (used[v]) {
					v++;
					if (v >= m) {
						v = 0;
					}
				}
			}
			if (kol == m) {
				break;
			}
			if (temp != 0) {
				d[i][v] += temp;
				v++;
				if (v >= m) {
					v = 0;
				}
				while (used[v]) {
					v++;
					if (v >= m) {
						v = 0;
					}
				}
			}
			i++;
			if (i >= n) {
				i = 0;
				g++;
				if (g >= 2) {
					g = 0;
				}
			}
		}
		for (int q = 0; q < n; q++) {
			out.print(ans[q].size());
			for (Integer s : ans[q]) {
				out.print(" " + words[s]);
			}
			out.println();
		}
	}

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		// br = new BufferedReader(new InputStreamReader(System.in));
		// out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Locale.setDefault(Locale.US);
		new TaskG().run();
	}
}