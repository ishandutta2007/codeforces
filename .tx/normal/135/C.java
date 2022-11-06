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

	void solve() throws IOException {
		char[] a = nextLine().toCharArray();
		int k1 = 0, k0 = 0, kv = 0, n = a.length;
		int last1 = -1, last0 = -1, lastv = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == '0') {
				k0++;
				last0 = i;
			} else if (a[i] == '1') {
				k1++;
				last1 = '1';
			} else {
				kv++;
				lastv = i;
			}
		}

		if (k0 > k1 + kv) {
			out.println("00");
			return;
		}

		if (k1 > k0 + kv + 1) {
			out.println("11");
			return;
		}

		if (k0 + kv > k1) {
			out.println("00");
		}
		if (a[n - 1] == '1') {
			if (k0 + kv >= k1 - 1) {
				out.println("01");
			}
		} else if (a[n - 1] == '?') {
			if (k0 + kv - 1 >= k1) {
				out.println("01");
			}
		}
		if (a[n - 1] == '0') {
			if (k1 + kv >= k0) {
				out.println("10");
			}
		} else if (a[n - 1] == '?') {
			if (k1 + kv - 1 >= k0 + 1) {
				out.println("10");
			}
		}
		if (k1 + kv > k0 + 1) {
			out.println("11");
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
}//liovzr