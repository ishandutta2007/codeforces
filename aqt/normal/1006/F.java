import java.util.*;
import java.io.*;

public class _1006_F {
	
	static int N, M; static long arr[][], cnt = 0, tar; static HashMap<Long, Long> mid[];

	public static void main(String[] args) throws IOException {
		N = readInt(); M = readInt(); tar = readLong(); arr = new long[N+1][M+1];
		for(int i = 1; i<=N; i++) for(int j = 1; j<=M; j++) arr[i][j] = readLong();
		mid = new HashMap[N+1]; for(int i = 1; i<=N; i++) mid[i] = new HashMap<Long, Long>();
		dfs1(1, 1, 0); dfs2(N, M, 0); println(cnt); exit();
	}
	
	public static void dfs1(int r, int c, long val) {
		if(r + c == N + 1) {mid[r].put(val, mid[r].getOrDefault(val, 0L) + 1); return;}
		if(r < N) dfs1(r+1, c, val ^ arr[r][c]); if(c < M) dfs1(r, c+1, val ^ arr[r][c]);
	} 
	
	public static void dfs2(int r, int c, long val) {
		if(r + c == N + 1) {cnt += mid[r].getOrDefault(val ^ arr[r][c] ^ tar, 0L); return;}
		if(r > 1) dfs2(r-1, c, val ^ arr[r][c]); if(c > 1) dfs2(r, c-1, val ^ arr[r][c]);
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