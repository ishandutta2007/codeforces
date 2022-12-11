import java.util.*;
import java.io.*;

public class _242_E_XOROnSegment {

	public static class Node{
		int l, r, lazy, amt[]; long sum;
		public Node(int l, int r) {
			this.l = l; this.r = r; amt = new int[32];
		}
	}
	
	static Node seg[]; static int org[]; static long pow2[];
	
	static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r); if(l == r) {
			for(int i = 0; i<=31; i++) if(((1<<i)&org[l]) != 0) seg[idx].amt[i]++; seg[idx].sum = org[r]; return;
		}
		int mid = (l+r)/2; build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
		seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
		for(int i = 0; i<32; i++) seg[idx].amt[i] = seg[2*idx].amt[i] + seg[2*idx+1].amt[i];
	}
	
	static void upd(int l, int r, int val, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) {
			int rng = r - l + 1; 
			for(int i = 0; i<32; i++) if(((1<<i)&val) != 0) {
				seg[idx].sum -= pow2[i] * seg[idx].amt[i];
				seg[idx].amt[i] = rng - seg[idx].amt[i];
				seg[idx].sum += seg[idx].amt[i] * pow2[i];
			}
			seg[idx].lazy ^= val; return;
		}
		int mid = (seg[idx].l + seg[idx].r)/2; pushdown(idx);
		if(l > mid) upd(l, r, val, 2*idx+1); else if(r <= mid) upd(l, r, val, 2*idx);
		else {upd(l, mid, val, 2*idx); upd(mid+1, r, val, 2*idx+1);}
		seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
		for(int i = 0; i<32; i++) seg[idx].amt[i] = seg[2*idx].amt[i] + seg[2*idx+1].amt[i];
	}
	
	static long sum(int l, int r, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) return seg[idx].sum;
		int mid = (seg[idx].l + seg[idx].r) / 2; pushdown(idx);
		if(r <= mid) return sum(l, r, 2*idx); else if(l > mid) return sum(l, r, 2*idx+1);
		else return sum(l, mid, 2*idx) + sum(mid + 1, r, 2*idx+1); 
	}
	
	private static void pushdown(int idx) {
		int rng1 = seg[2*idx].r - seg[2*idx].l + 1, rng2 = seg[2*idx+1].r - seg[2*idx+1].l + 1, val = seg[idx].lazy; 
		for(int i = 0; i<32; i++) if(((1<<i)&val) != 0) {
			seg[2*idx].sum -= pow2[i] * seg[2*idx].amt[i];
			seg[2*idx].amt[i] = rng1 - seg[2*idx].amt[i];
			seg[2*idx].sum += seg[2*idx].amt[i] * pow2[i];
			seg[2*idx+1].sum -= pow2[i] * seg[2*idx+1].amt[i];
			seg[2*idx+1].amt[i] = rng2 - seg[2*idx+1].amt[i];
			seg[2*idx+1].sum += seg[2*idx+1].amt[i] * pow2[i];
		}
		seg[2*idx].lazy ^= val; seg[2*idx+1].lazy ^= val; seg[idx].lazy = 0;
	}

	public static void main(String[] args) throws IOException {
		pow2 = new long[32]; pow2[0] = 1; for(int i = 1; i<32; i++) pow2[i] = pow2[i-1] * 2;
		int N = readInt(); org = new int[N+1]; for(int i = 1; i<=N; i++) org[i] = readInt();
		seg = new Node[4*N+1]; build(1, N, 1); int Q = readInt(); for(int q= 0; q<Q; q++) {
			if(readInt() == 1) println(sum(readInt(), readInt(), 1));
			else upd(readInt(), readInt(), readInt(), 1);
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