import java.util.*;
import java.io.*;

public class _380_C_SerejaAndBrackets {
	
	public static class Node{
		int l, r, val, open, close;
		public Node(int l, int r) {
			this.l = l; this.r =r ;
		}
		
		public Node clone() {
			Node n = new Node(0, 0);
			n.l = this.l; n.r = this.r; n.open = this.open; n.close= this.close; n.val = this.val;
			return n;
		}
	}

	static Node seg[];
	static char c[];
	
	static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r); if(l == r) {if(c[l] == ')') seg[idx].close = 1; else seg[idx].open = 1; return;}
		int mid = (l+r)/2; build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
		seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
		if(seg[2*idx].open > seg[2*idx+1].close) {
			seg[idx].val += seg[2*idx+1].close;	
			seg[idx].open += seg[2*idx].open - seg[2*idx+1].close + seg[2*idx+1].open;
			seg[idx].close += seg[2*idx].close;
		}
		else {
			seg[idx].val += seg[2*idx].open;
			seg[idx].close += seg[2*idx+1].close - seg[2*idx].open + seg[2*idx].close;
			seg[idx].open += seg[2*idx+1].open;
		}
	}
	
	static Node query(int l, int r, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) return seg[idx];
		int mid = (seg[idx].l+seg[idx].r)/2;
		if(l > mid) return query(l, r, 2*idx+1); else if(r <= mid) return query(l, r, 2*idx);
		Node n = new Node(0, 0), left = query(l, mid, 2*idx), right = query(mid+1, r, 2*idx+1);
		n.val = left.val + right.val;
		if(left.open > right.close) {
			n.val += right.close;
			n.open += left.open - right.close + right.open;
			n.close += left.close;
		}
		else {
			n.val += left.open;	
			n.close += right.close - left.open + left.close;
			n.open += right.open;
		}
		return n;
	}
	
	public static void main(String[] args) throws IOException {
		String s = read(); int N = s.length(); c = (" " + s).toCharArray(); 
		seg = new Node[4*N+1]; build(1, N, 1);
		int Q = readInt(); for(int q = 0; q<Q; q++) {
			println(2*query(readInt(), readInt(), 1).val);
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
		byte[] ret = new byte[1000000];
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