import java.util.*;
import java.io.*;

public class _086_D_PowerfulArray {
	
	static int BLKSZ;
	
	public static class Query implements Comparable<Query>{
		int l, r, id;
		public Query(int l, int r, int id) {
			this.l = l; this.r = r; this.id = id;
		}
		public int compareTo(Query q) {
			if(q.l/BLKSZ == this.l/BLKSZ) 
				if(this.r != q.r) return Integer.compare(this.r, q.r);
				else return Integer.compare(this.l, q.l);
			return Integer.compare(this.l/BLKSZ, q.l/BLKSZ);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt(); BLKSZ = (int) (2.5*Math.sqrt(N));
		int arr[] = new int[N+1]; long ans[] = new long[Q]; for(int i = 1; i<=N; i++) arr[i] = readInt();
		PriorityQueue<Query> pq = new PriorityQueue<>(); int l = 1, r = 0; long a[] = new long[1000001], val = 0;
		for(int q = 0; q<Q; q++) pq.add(new Query(readInt(), readInt(), q)); while(!pq.isEmpty()) {Query q = pq.poll(); 
			while(r < q.r) {val += (2*a[arr[++r]]+1)*arr[r]; a[arr[r]]++;}
			while(l > q.l) {val += (2*a[arr[--l]]+1)*arr[l]; a[arr[l]]++;}
			while(r > q.r) {val -= (2*a[arr[r]]-1)*arr[r]; a[arr[r--]]--;}
			while(l < q.l) {val -= (2*a[arr[l]]-1)*arr[l]; a[arr[l++]]--;}
			ans[q.id] = val;
		}
		for(long b : ans) println(b); exit();
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