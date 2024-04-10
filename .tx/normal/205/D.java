import java.util.*;
import java.io.*;

public class TaskD implements Runnable {
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

	void solve() {
		int n = nextInt();
		int last = 0, x, y;
		int[] a = new int[2 * n], b = new int[2 * n], c = new int[2 * n];
		TreeMap<Integer, Integer> hm = new TreeMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			x = nextInt();
			if (!hm.containsKey(x)) {
				hm.put(x, last);
				last++;
			}
			x = hm.get(x);
			a[x]++;
			y = nextInt();
			if (!hm.containsKey(y)) {
				hm.put(y, last);
				last++;
			}
			y = hm.get(y);
			b[y]++;
			if (x == y) {
				c[y]++;
			}
		}
		int ans = n, d2 = (n + 1) / 2;
		for (int i = 0; i < n; i++) {
			if (a[i] + b[i] - c[i] >= d2) {
				ans = Math.min(ans, d2 - a[i]);
			}
		}
		if (ans != n) {
			out.println(Math.max(ans, 0));
		} else {
			out.println(-1);
		}
	}

	public void run() {
		try {
			try {
				in = new BufferedReader(new FileReader("taskd.in"));
				out = new PrintWriter("taskd.out");
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
		new Thread(new TaskD()).run();
	}
}//xsxeri