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

	int len(long x) {
		int res = 0;
		while (x > 0) {
			x /= 10;
			res++;
		}
		return res;
	}

	boolean check(long x) {
		int f = (int) (x % 10);
		while (x / 10 > 0) {
			x /= 10;
		}
		return f == x;
	}
	
	long center(long x) {
		return x / 10 % p10[len(x) - 2];
	}

	long[] p10;

	void solve() {
		p10 = new long[19];
		p10[0] = 1;
		for (int i = 1; i < 19; i++) {
			p10[i] = p10[i - 1] * 10;
		}
		long l = nextLong(), r = nextLong();
		long ans = 0;
		while (l <= r && l <= 100) {
			if (check(l)) {
				ans++;
			}
			l++;
		}
		while (!check(l)) {
			l++;
		}
		while (!check(r)) {
			r--;
		}
		if (l > r) {
			out.println(ans);
			return;
		}
		int lenl = len(l), lenr = len(r);
		if (lenl == lenr) {
			ans += center(r) - center(l) + 1 + p10[lenl - 2] * (r % 10 - l % 10);
		} else {
			ans += p10[lenl - 2] - center(l) + center(r) + 1;
			l += (p10[lenl - 2] - center(l)) * 10;
			l -= l % 10;
			while (!check(l)) {
				l++;
			}
			r -= center(r) * 10;
			for (int i = 1; i <= 16; i++) {
				for (int g = 1; g <= 9; g++) {
					long v = g * p10[i + 1] + g;
					if (v >= l && v < r) {
						ans += p10[i];
					}
				}
			}
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

	public static void main(String[] args) {
		new Thread(new TaskC()).run();
	}
}//xosrus