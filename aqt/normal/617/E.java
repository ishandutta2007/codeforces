import java.util.*;
import java.io.*;

public class _617_E_XORAndFavoriteNumber {
	
	public static class Query implements Comparable<Query>{
		int l, r, idx;
		public Query(int l, int r, int idx) {this.l = l; this.r = r; this.idx = idx;}
		public int compareTo(Query q) {
			if(q.l/BLKSZ == this.l/BLKSZ) return Integer.compare(this.r, q.r);
			else return Integer.compare(q.l/BLKSZ, this.l/BLKSZ);
		}
	}
	
	static int BLKSZ;

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt(), K = readInt(); BLKSZ = (int) Math.sqrt(N);
		int arr[] = new int[N+1]; for(int i = 1; i<=N; i++) arr[i] = readInt() ^ arr[i-1]; long ans[] = new long[Q]; 
		Query q[] = new Query[Q]; for(int i = 0; i<Q; i++) q[i] = new Query(readInt()-1, readInt(), i); Arrays.sort(q);
		int l = 0, r = -1; long tot = 0; int a[] = new int[1<<20]; for(Query qu : q) {
			while(r < qu.r) {r++; tot += a[arr[r] ^ K]; a[arr[r]]++; }
			while(r > qu.r) {a[arr[r]]--; tot -= a[arr[r] ^ K]; r--;}
			while(l > qu.l) {l--; tot += a[arr[l] ^ K]; a[arr[l]]++;}
			while(l < qu.l) {a[arr[l]]--; tot -= a[arr[l] ^ K]; l++;}
			ans[qu.idx] = tot;
		}
		for(long ll : ans) println(ll); exit();
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