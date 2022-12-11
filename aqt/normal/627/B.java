import java.util.*;
import java.io.*;

public class _0627_B_FactoryRepairs {
	
	public static class Node{
		int l, r, a, b;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}
	
	static Node seg[];
	static int A, B;
	
	public static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r); if(l == r) return;
		int mid = (l + r)/2; build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
	}
	
	public static void upd(int pos, int val, int idx) {
		if(seg[idx].l == pos && seg[idx].r == pos) {
			seg[idx].a = Math.min(A, seg[idx].a + val); seg[idx].b = Math.min(B, seg[idx].b + val); return;
		}
		int mid = (seg[idx].l + seg[idx].r)/2; if(pos <= mid) upd(pos, val, 2*idx); else upd(pos, val, 2*idx+1);
		seg[idx].a = seg[2*idx].a + seg[2*idx+1].a; seg[idx].b = seg[2*idx].b + seg[2*idx+1].b;
	}
	
	public static int query(int l, int r, int idx, boolean a) {
		if(seg[idx].l == l && seg[idx].r == r) return a ? seg[idx].a : seg[idx].b;
		int mid =(seg[idx].l+seg[idx].r)/2; if(l > mid) return query(l, r, 2*idx+1, a); else if(r <= mid) return query(l, r, 2*idx, a);
		else return query(l, mid, 2*idx, a) + query(mid+1, r, 2*idx+1, a);
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(), a = readInt(), b = readInt(), Q = readInt(); A = a; B = b;
		seg = new Node[4*N+1]; build(1, N, 1); while(Q-->0) {
			if(readInt() == 1) upd(readInt(), readInt(), 1);
			else {
				int n = readInt(); println((n == 1 ? 0 : query(1, n-1, 1, false)) + (n + K > N ? 0 : query(n+K, N, 1, true)));
			}
		}
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