import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			final int mod = 1000_000_007;
			int n = in.nextInt();
			int K = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			Arrays.sort(a);

			int[][][] dp = new int[n + 1][n/2+2][K + 1];
			dp[0][0][0] = 1;
            int k1;
			for (int i = 0; i < n; i++) {
				int d = i == 0 ? 0 : a[i] - a[i - 1];
				for (int g = 0; g <= n/2; g++) {
					for (int k = 0; k <= K; k++) {
						k1 = k + g * d;
						if (k1 <= K) {
							dp[i + 1][g][k1] = (int) ((dp[i + 1][g][k1] + dp[i][g][k] * (long) (g + 1)) % mod);
							if (g > 0) {
								dp[i + 1][g - 1][k1] = (int) ((dp[i + 1][g - 1][k1] + dp[i][g][k] * (long) g) % mod);
							}
							dp[i + 1][g + 1][k1] = (dp[i + 1][g + 1][k1] + dp[i][g][k]) % mod;
						}
					}
				}
			}

			int res = 0;
			for (int v : dp[n][0]) {
				res = (res + v) % mod;
			}
			out.println(res);
		}

	}

	static class InputReader {
		final InputStream is;
		final byte[] buf = new byte[1024];
		int pos;
		int size;

		public InputReader(InputStream is) {
			this.is = is;
		}

		public int nextInt() {
			int c = read();
			while (isWhitespace(c))
				c = read();
			int sign = 1;
			if (c == '-') {
				sign = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = read();
			} while (!isWhitespace(c));
			return res * sign;
		}

		int read() {
			if (size == -1)
				throw new InputMismatchException();
			if (pos >= size) {
				pos = 0;
				try {
					size = is.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (size <= 0)
					return -1;
			}
			return buf[pos++] & 255;
		}

		static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}