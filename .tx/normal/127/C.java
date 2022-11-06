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
		long t1 = nextLong(), t2 = nextLong(), x1 = nextLong(), x2 = nextLong(), t0 = nextLong();
		if (t0 == t1) {
			out.print(x1 + " " + (t1 == t2 ? x2 : 0));
			return;
		}
		long my1 = 0, my2 = 0, y1, y2;
		Double min = Double.MAX_VALUE, t;
		for (y2 = 1; y2 <= x2; y2++) {
			y1 = Math.min(x1, (t2 - t0) * y2 / (t0 - t1));
			t = (t1 * y1 + t2 * y2 + .0) / (y1 + y2);
			if (t >= t0
					&& (t - t0 < min || (t - t0 == min && y1 + y2 > my1 + my2))) {
				min = t - t0;
				my1 = y1;
				my2 = y2;
			}
		}
		out.print(my1 + " " + my2);
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