import java.util.*;
import java.io.*;

public class _1013_E {

	public static void main(String[] args) throws IOException {
		int N = readInt(); long arr[] = new long[N+2]; arr[N+1] = arr[0] = Integer.MIN_VALUE;
		for(int i = 1; i<=N; i++) arr[i] = readInt();
		long dp[][] = new long[N+1][N+1]; for(int i = 1; i<=N; i++) dp[i][1] = Math.max(0, arr[i-1]-arr[i]+1);
		for(int i = 0; i<=N; i++) for(int j = 2; j<=N; j++) dp[i][j] = 2L*Integer.MAX_VALUE; dp[0][1] = 2L*Integer.MAX_VALUE;
		for(int j = 2; j<=(N+1)/2; j++) {
			dp[2*j-1][j] = dp[2*j-3][j-1] + 
					Math.max(arr[2*j-2]-Math.min(arr[2*j-1], arr[2*j-3])+1, 0);
//			println(dp[2*j-3][j-1] + Math.max(arr[2*j-2]-arr[2*j-1]+1,0) + " " + (2*j-3) + " " + (j-1));
//			dp[2*j-3][j-1] += Math.max(arr[2*j]-arr[2*j-1]+1,0);
//			println(" " + dp[2*j-3][j-1]+ Math.max(arr[2*j]-arr[2*j-1]+1,0));
//			println(Math.max(arr[2*j]-arr[2*j-1]+1,0));
			for(int i = 2*j; i<=N; i++) {
				dp[i-3][j-1] = Math.min(dp[i-3][j-1]+Math.max(arr[i-2]-arr[i-3]+1, 0), dp[i-4][j-1]);
//				println(" " + dp[i-3][j-1]);
				dp[i][j] = Math.min(dp[i-3][j-1] + Math.max(arr[i-1]-arr[i]+1, 0), 
						dp[i-2][j-1] + Math.max(arr[i-1]-Math.min(arr[i-2], arr[i])+1, 0));
			}
			for(int i = N-2; i<=N; i++) dp[i][j-1] = Math.min(dp[i][j-1]+Math.max(arr[i+1]-arr[i]+1, 0), dp[i-1][j-1]);
//			for(int i = 1; i<=N; i++) println( "  " + dp[i][j-1] + " " + i);
		}
		for(int i = 1; i<=N; i++) dp[i][(N+1)/2] = Math.min(dp[i][(N+1)/2]+Math.max(arr[i+1]-arr[i]+1, 0), dp[i-1][(N+1)/2]);
//		for(int i = 1; i<=N; i++) println( "  " + dp[i][(N+1)/2] + " " + i);
		for(int i = 1; i<=(N+1)/2; i++) print(dp[N][i] + " ");
		exit();
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