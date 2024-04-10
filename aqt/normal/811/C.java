import java.util.*;
import java.io.*;

public class _811_C_VladikAndMemorableTrip {

	public static void main(String[] args) throws IOException {
		int N = readInt(); int arr[] = new int[N+1]; for(int i = 1; i<=N; i++) arr[i] = readInt();
		int l[] = new int[5001], f[] = new int[5001], fin[] = new int[5001];
		for(int i = 1; i<=N; i++) {if(f[arr[i]] == 0) f[arr[i]] = i; l[arr[i]] = i;}
		int val[] = new int[N+1]; boolean done[] = new boolean[5001]; Arrays.fill(val, -1);
		for(int i = 1; i<=N; i++) if(!done[arr[i]]){
			boolean tkn[] = new boolean[5001]; fin[arr[i]] = l[arr[i]]; val[i] = 0; 
			for(int j = i; j<=fin[arr[i]]; j++) if(!tkn[arr[j]]) {
				val[i] ^= arr[j]; fin[arr[i]] = Math.max(fin[arr[i]], l[arr[j]]); tkn[arr[j]] = true;
				if(f[arr[j]] < i) {val[i] = -1; break;}
			}
			done[arr[i]] = true; 
		}
		long dp[] = new long[N+2]; for(int i= 1; i<=N; i++) {
			dp[i+1] = Math.max(dp[i+1], dp[i]); if(val[i] >= 0) dp[fin[arr[i]]+1] = Math.max(dp[fin[arr[i]]+1], dp[i] + val[i]);
		}
		println(dp[N+1]); exit();
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

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
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