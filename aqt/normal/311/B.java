import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;

public class _0311_B_CatsTransport {

	static class Pair implements Comparable<Pair> {
		int val, pos;

		public Pair(int val, int pos) {
			this.val = val;
			this.pos = pos;
		}

		public int compareTo(Pair p) {
			return Integer.compare(this.val, p.val);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt();
		dp = new long[K + 1][M + 1];
		long dis[] = new long[N + 1];
		Long val[] = new Long[M + 1];
		pre = new long[M + 1];
		for (int i = 2; i <= N; i++) {
			dis[i] = dis[i - 1] + readInt();
		}
		for (int i = 1; i <= M; i++) {
			val[i] = -dis[readInt()] + readLong();
		}
		Arrays.sort(val, 1, M + 1);
		for (int i = 1; i <= M; i++) {
			pre[i] = pre[i - 1] + val[i];
		}
		for (int i = 1; i <= M; i++) {
			dp[1][i] = val[i] * i - pre[i];
		}
		int ll[] = new int[M + 1];
		for (int i = 2; i <= K; i++) {
			int l = 0, r = 0;
			for (int j = 1; j <= M; j++) {
				while (r-l+1 >= 2) {
					if(f(ll[l+1], ll[l], i) <= val[j]) {
						l++;
					}
					else {
						break;
					}
				}
				dp[i][j] = dp[i-1][ll[l]] - pre[j] + pre[ll[l]] + val[j]*(j-ll[l]);
				while (r-l+1 >= 2) {
					if(f(j, ll[r-1], i) <= f(ll[r], ll[r-1], i)) {
						r--;
					}
					else {
						break;
					}
				}
				ll[++r] = j;
			}
		}
		println(dp[K][M]);
		exit();
	}

	static long dp[][];
	static long pre[];
	
	static double f(int k1, int k2, int i) {
		return (dp[i-1][k1] - dp[i-1][k2] + pre[k1] - pre[k2])/(1.0*k1-k2);
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
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