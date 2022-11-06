import java.io.*;
import java.math.BigInteger;
import java.util.*;
import javax.script.*;

public class Main implements Runnable {
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

	void solve() throws IOException, ScriptException, NoSuchMethodException {
		ArrayList<StringBuilder> ans = new ArrayList();
		StringBuilder lol;
		StringBuilder ansPart;
		int size = 0;
		boolean last = false;
		while (true) {
			boolean f = true;
			try {
				lol = new StringBuilder(in.readLine());
			} catch (Exception e) {
				break;
			}
			if (lol == null)
				break;
			for (int i = 0; i < lol.length(); i++) {
				if (lol.charAt(i) == ' ')
					continue;
				if (lol.charAt(i) == '#') {
					f = false;
					break;
				}
				f = true;
				break;
			}
			if (f == false) {
				last = false;
				ans.add(lol);
				size++;
				continue;
			} else {
				ansPart = new StringBuilder();
				for (int i = 0; i < lol.length(); i++) {
					if (lol.charAt(i) != ' ') {
						ansPart.append(lol.charAt(i));
					}
				}
				if (last == true) {
					StringBuilder nope;
					nope = ans.get(size - 1).append(ansPart);
					ans.set(size - 1, nope);
				} else {
					size++;
					ans.add(ansPart);
				}
				last = true;
				continue;
			}

		}

		for (int i = 0; i < size; i++) {
			out.println(ans.get(i));
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) throws IOException {
		// Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}//zyycik