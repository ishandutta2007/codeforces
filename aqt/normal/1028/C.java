import java.util.*;
import java.io.*;

public class _1028_C {

	public static class Query implements Comparable<Query>{
		int x, ty, by, val;
		public Query(int x, int ty, int by, int val) {
			this.x = x; this.ty = ty; this.by = by; this.val = val;
		}
		public int compareTo(Query q) {
			return Integer.compare(this.x, q.x);
		}
	}
	
	public static class Node{
		int l, r, val, idx, lazy;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}
	
	static Node seg[];
	
	static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r); if(l == r) {
			seg[idx].idx = l; return;
		}
		int mid = (l+r)/2; build(l,mid, 2*idx); build(mid+1, r, 2*idx+1);
		seg[idx].idx = seg[2*idx].idx;
	}
	
	static void upd(int l, int r, int v, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) {
			seg[idx].lazy += v;
			seg[idx].val += v; return;
		}
		if(seg[idx].lazy != 0) pd(idx);
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(r <= mid) upd(l, r, v, 2*idx);
		else if(l > mid) upd(l, r, v, 2*idx+1);
		else {upd(l, mid, v, 2*idx); upd(mid+1, r, v, 2*idx+1);}
		if(seg[2*idx].val > seg[2*idx+1].val) {
			seg[idx].val = seg[2*idx].val;
			seg[idx].idx = seg[2*idx].idx;
		}
		else {
			seg[idx].val = seg[2*idx+1].val;
			seg[idx].idx = seg[2*idx+1].idx;
		}
	}
	
	static void pd(int idx) {
		seg[2*idx].val += seg[idx].lazy;
		seg[2*idx+1].val += seg[idx].lazy;
		seg[2*idx].lazy += seg[idx].lazy;
		seg[2*idx+1].lazy += seg[idx].lazy;
		seg[idx].lazy = 0;
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt();
		Integer y[] = new Integer[2*N]; 
		Query q[] = new Query[2*N];
		for(int i = 0; i<N; i++) {
			int x1 = readInt(), y1 = readInt(), x2 = readInt(), y2 = readInt();
			y[2*i] = y1; y[2*i+1] = y2;
			q[2*i] = new Query(x1, y2, y1, 1);
			q[2*i+1] = new Query(x2+1, y2, y1, -1);
		}
		Arrays.sort(y); Arrays.sort(q);
		HashMap<Integer, Integer> compy = new HashMap<>();
		int idx = 0;
		for(int yv : y) {
			compy.put(yv, ++idx);
		}
		seg = new Node[8*N+1]; build(1, 2*N, 1);
		idx = 0;
		for(; idx<2*N; ) {
			int cx = q[idx].x;
			while(idx < 2*N && q[idx].x == cx) {
				upd(compy.get(q[idx].by), compy.get(q[idx].ty), q[idx].val, 1);
				idx++;
			}
			if(seg[1].val >= N-1) {
				println(cx + " " + y[seg[1].idx-1]);
				exit();
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