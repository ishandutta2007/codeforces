import java.util.*;
import java.io.*;

public class _1036_C_ClassyNumbers {

	static long dp[][] = new long[4][19];
	static long pow[] = new long[19];
	
	public static void main(String[] args) throws IOException {
		int T = readInt();
		Arrays.fill(dp[0], 1);
		dp[1][0] = dp[2][0] = dp[3][0] = 1;
		for(int d = 1; d<4; d++) {
			for(int i = 1; i<19; i++) {
				dp[d][i] = dp[d-1][i-1]*9+dp[d][i-1];
//				print(dp[d][i] + " ");
			}
//			println();
		}
//		for(int d = 1; d<4; d++) {
//			for(int i = 1; i<19; i++) {
//				dp[d][i] += dp[d][i-1] + dp[d-1][i] - dp[d-1][i-1];
//				print(dp[d][i] + " ");
//			}
//			println();
//		}
		pow[0] = 1;
		for(int i = 1; i<19; i++) pow[i] = pow[i-1]*10;
		while(T-- > 0) {
			long L = readLong(), R = readLong();
			if(R == pow[18]) {
				if(L == pow[18]) println(1);
				else println(rec(18, 0, true, pow[18]-1)-rec(18, 0, true, L-1)+1);
			}
			else {
				println(rec(18, 0, true, R) - rec(18, 0, true, L-1));
			}
		}
		exit();
	}
	
	static long rec(int p, int k, boolean edge, long lim) {
//		println(p + " " + k + " " + edge + " " + lim);
		if(p == -1) return 1;
		if(!edge) return dp[3-k][p+1];
		long dig = (lim/pow[p])%10;
		if(dig == 0) return rec(p-1, k, edge, lim);
		long ans = 0;
		ans = rec(p-1, k, !edge, lim);
		if(k != 3) ans += (dig-1)*rec(p-1, k+1, !edge, lim);
		ans += (k != 3 ? rec(p-1, k+1, edge, lim) : 0);
		return ans;
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}

	public static String read() throws IOException {
		byte[] ret = new byte[1024];
		int idx = 0;
		byte c = Read();
		while (c <= ' ') {
			c = Read();
		}
		do {
			ret[idx++] = c;
			c = Read();
		} while (c != -1 && c != ' ' && c != '\n' && c != '\r');
		return new String(ret, 0, idx);
	}

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}