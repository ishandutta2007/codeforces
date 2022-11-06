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
		double a = nextDouble(), b = nextDouble(), m = nextDouble(), vx = nextDouble(), vy = nextDouble(), vz = nextDouble();
		double t = -m / vy;
		double x0, z0, sx, sz;
		sx = vx * t + a / 2;
		sz = vz * t;
		if ((long) Math.floor(sz / b) % 2 == 0) {
			z0 = sz - Math.floor(sz / b) * b;
		} else {
			z0 = b - sz + Math.floor(sz / b) * b;
		}
		if ((long) Math.floor(sx / a) % 2 == 0) {
			x0 = sx - Math.floor(sx / a) * a;
		} else {
			x0 = a - sx + Math.floor(sx / a) * a;
		}
		out.printf("%.7f %.7f\n", x0, z0);
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
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {
		}
		new Thread(new TaskD()).run();
	}
}//xygdev