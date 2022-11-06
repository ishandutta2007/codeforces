import java.io.*;
import java.util.*;

public class TaskC {
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

	class Rec {
		int x, y, l;

		Rec() {
		}

		Rec(int x, int y, int l) {
			this.x = x;
			this.y = y;
			this.l = Math.min(l, 8);
		}
	}

	void solve() throws IOException {
		int n = 8;
		char[][][] a = new char[n][n][10];
		boolean[][][] b = new boolean[n][n][10];
		for (int f = 0; f < 10; f++) {
			for (int i = 0; i < n; i++) {
				for (int g = 0; g < n; g++) {
					a[i][g][f] = '.';
				}
			}
		}
		b[0][0][0] = true;
		for (int i = 0; i < n; i++) {
			for (int g = 0; g < n; g++) {
				a[i][g][0] = nextChar();
			}
			nextLine();
		}
		for (int f = 0; f < 10; f++) {
			for (int i = 0; i < n - 1; i++) {
				for (int g = 0; g < n; g++) {
					if (a[i][g][f] == 'S') {
						a[i + 1][g][f + 1] = 'S';
					}
				}
			}
		}

		Queue<Rec> q = new ArrayDeque<Rec>();
		q.add(new Rec(7, 0, 0));
		Rec v;
		int[] dx = new int[] { 0, 1, -1, 0, 0, 1, 1, -1, -1 };
		int[] dy = new int[] { 0, 0, 0, 1, -1, 1, -1, 1, -1 };
		int x, y;
		while (!q.isEmpty()) {
			v = q.poll();
			for (int f = 0; f < dx.length; f++) {
				x = v.x + dx[f];
				y = v.y + dy[f];
				if (x < 0 || x >= n || y < 0 || y >= n || a[x][y][v.l] == 'S'
						|| a[x][y][v.l + 1] == 'S') {
					continue;
				}
				if (!b[x][y][v.l + 1]) {
					q.add(new Rec(x, y, v.l + 1));
					b[x][y][v.l + 1] = true;
				}
			}
		}
		if (b[7][7][9]) {
			out.print("WIN");
		} else {
			out.print("LOSE");
		}
	}

	void run() throws IOException {
		// br = new BufferedReader(new FileReader("taskc.in"));
		// out = new PrintWriter("taskc.out");
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
		new TaskC().run();
	}
}