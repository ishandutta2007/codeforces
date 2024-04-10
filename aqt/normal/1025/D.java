import java.util.*;
import java.io.*;

public class _1025_D_RecoveringBST {

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int arr[] = new int[N+2];
		arr[0] = arr[N+1] = 1;
		for(int i = 1; i<=N; i++) {
			arr[i] = readInt();
		}
		chk = new boolean[N+2][N+2];
		for(int i = 0; i<=N+1; i++) {
			for(int j =0; j<=N+1; j++) {
				chk[i][j] = arr[i] == 1 || arr[j] == 1 || gcd(arr[i], arr[j]) > 1;
			}
		}
		dp = new boolean[N+2][N+2][2];
		done = new boolean[N+2][N+2][2];
		println(solve(1, N, 1) ? "Yes" : "No");
		exit();
	}

	//t == 1 is left
	static boolean solve(int l, int r, int t) {
		if(l > r) {
			return true;
		}
		if(done[l][r][t]) {
			return dp[l][r][t];
		}
		done[l][r][t] = true;
		int idx = t == 1 ? r+1 : l-1;
		for(int i = l; i<=r; i++) {
			if(chk[idx][i] && solve(l, i-1, 1) && solve(i+1, r, 0)) {
				return dp[l][r][t] = true;
			}
		}
		return false;
	}

	static boolean chk[][];
	static boolean dp[][][];
	static boolean done[][][];

	static int gcd(int a, int b) {
		if(a == 0 || b == 0) {
			return a+b;
		}
		return gcd(b, a%b);
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