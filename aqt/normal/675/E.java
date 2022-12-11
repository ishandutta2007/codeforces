import java.util.*;
import java.io.*;

public class _675_E_TrainsAndStatistic {
	
	public static class Node{
		int l, r, val;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}

	static Node seg[]; static int arr[];
	static void build(int l, int r, int idx) {
		seg[idx] = new Node(l,r);if(l == r) {seg[idx].val = l; return;}
		int mid = (l+r)/2; build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
		seg[idx].val = arr[seg[2*idx].val] > arr[seg[2*idx+1].val] ? seg[2*idx].val : seg[2*idx+1].val;
	}
	
	static int query(int l, int r, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) return seg[idx].val;
		int mid = (seg[idx].l + seg[idx].r)/2; 
		if(r <= mid) return query(l, r, 2*idx); else if(l > mid) return query(l, r, 2*idx+1);
		int idx1 = query(l, mid, 2*idx), idx2 = query(mid + 1, r, 2*idx+1);
		return arr[idx1] > arr[idx2] ? idx1 : idx2;
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(); arr = new int[N+1]; for(int i = 0; i<N - 1; i++) arr[i] = readInt()-1; arr[N-1] = N-1;
		long dp[] = new long[N+1]; seg = new Node[4*N+1]; build(1, N, 1);
		for(int i = N-2; i>=0; i--) {
			int idx = query(i+1, arr[i], 1); dp[i] = 1L*N - i - 1 + dp[idx] - (arr[i] - idx);
		} 
		long tot = 0;for(int i = 0; i<=N; i++) tot += dp[i]; println(tot);
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