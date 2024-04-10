import java.util.*;
import java.io.*;

public class _0813_E_ArmyCreation {
	
	static class Node{
		int l, r, val; Node left, right;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
		Node copy() {
			Node x = new Node(this.l, this.r);
			x.val = this.val;
			x.left = this.left;
			x.right = this.right;
			return x;
		}
	}
	
	static Node build(int l, int r) {
		Node n = new Node(l, r);
		if(l == r) return n;
		int mid = (l+r)/2;
		n.left = build(l, mid); n.right = build(mid+1, r);
		return n;
	}
	
	static Node upd(Node x, int p, int v) {
		Node n = x.copy(); n.val += v;
		if(n.l == p && n.r == p) return n;
		int mid = (n.l + n.r)/2;
		if(p <= mid) n.left = upd(n.left, p, v);
		else n.right = upd(n.right, p, v);
		return n;
	}
	
	static int query(Node n, int l, int r) {
		if(n.l == l && n.r == r) return n.val;
		int mid = (n.l + n.r)/2;
		if(r <= mid) return query(n.left, l, r);
		else if(l > mid) return query(n.right, l, r);
		else return query(n.left, l, mid) + query(n.right, mid+1, r);
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt();
		ArrayList<Integer> al[] = new ArrayList[100001];
		for(int i = 1; i<=100000; i++) al[i] = new ArrayList<>();
		Node seg[] = new Node[N+1]; seg[0] = build(1, N);
		for(int i = 1; i<=N; i++) {
			int n = readInt();
			al[n].add(i);
			seg[i] = seg[i-1].copy();
			seg[i] = upd(seg[i], i, 1);
			if(al[n].size() > K)
				seg[i] = upd(seg[i], al[n].get(al[n].size()-K-1), -1);
		}
		int Q = readInt();
		int last = 0;
		for(int q = 0; q<Q; q++) {
			int l = ((readInt() + last)%N)+1, r = ((readInt() + last)%N)+1;
			if(l > r) {int temp = l; l = r; r = temp;}
			println(last = query(seg[r], l, r));
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